//
//  gpaCalc.cpp
//  GPACalculatorProj
//
//  Created by Krish Makwana on 1/6/25.
//
#include "gpaCalc.hpp"
void writeInFile(vector<Semester> x,double overallGpa,string user){
    ofstream of("transcript.txt");  //declaring ofstream object and creating file
    of<<"Transcript of "<<user<<endl;
    for(int i=0;i<x.size();i++){    //going through each semester
        of<<"_______________________________________________"<<endl;
        of<<"For semester "<<i+1<<":"<<endl;
        of<<x[i]<<endl;                     //wrting entire semester content into file
        of<<"Term Gpa:"<<x[i].getSemGpa()<<endl;
    }
    of<<"_______________________________________________"<<endl;
    of<<"Overall GPA:"<<overallGpa<<endl;
    of.close();         //closing file
    cout<<"Transcript has been generated in a file named transcript.txt"<<endl;
}
int main(){
    int num=0;  //for number of semesters
    string user;    //for user's name
    cout<<"Enter your name:";
    getline(cin,user);      //handles spaces in name
    cout<<"Enter the number of semesters to find GPA:";
    cin>>num;
    vector<Semester>x;      //vector for storing all semesters
    for(int i=0;i<num;i++){
        int numberOfCourses;    //courses per semester
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Enter the number of courses you took in semester "<<i+1<<":";
        cin>>numberOfCourses;
        x.push_back(Semester(numberOfCourses)); //adding semester to the vector
        cout<<"Enter details for each course:"<<endl;
        for(int j=0;j<numberOfCourses;j++){
            string name;
            int credits;
            string grade;
            cout<<"Enter for the course "<<j+1<<":"<<endl;
            cout<<"Enter the name of the course:";
            cin>>name;
            cout<<"Enter the credits offered by course:";
            cin>>credits;
            cout<<"Enter grade earned in course:";
            cin>>grade;
            Course c=Course(name,credits,grade);    //course object for storing course                                     //data
            x[i].v.push_back(c);          //each sem has a vector of courses. this //adds the course content in each semester object
            
        }
        cout<<"GPA of semester"<<i+1<<":";
        cout<<x[i].getSemGpa()<<endl;   //displays each semester's gpa
    }
    double overallGpa=0.0;
    double totalCreditsOfAllSem=0.0;
    double weightedGradePointsEarned=0.0;
    for(int i=0;i<num;i++){
        totalCreditsOfAllSem+=x[i].totalCreditsOfSem;   //finding total credits taken //by user for all semesters
        weightedGradePointsEarned+=x[i].getSemGpa()*x[i].totalCreditsOfSem;
    }
    overallGpa=weightedGradePointsEarned/totalCreditsOfAllSem; //calculating overall                                                          //gpa
    cout<<"Overall gpa of student:"<<overallGpa<<endl;
    char choice; //asking whether to generate a transcript
    cout<<"Would you like to generate a transcript? Y or N:";
    cin>>choice;
    if(choice=='y'|| choice=='Y'){
        writeInFile(x,overallGpa,user);
    }
    cout<<"Program end."<<endl;
    return 0;
}

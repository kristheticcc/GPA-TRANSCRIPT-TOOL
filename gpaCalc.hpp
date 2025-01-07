//
//  gpaCalc.hpp
//  GPACalculatorProj
//
//  Created by Krish Makwana on 1/6/25.
//

#ifndef gpaCalc_hpp
#define gpaCalc_hpp
#include <stdio.h>  //including libraries
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
using namespace std;
map<string,double> gradePoints={{"A",4.0},{"A-",3.7},{"B+",3.3},{"B",3.0},{"B-",2.7},{"C+",2.3},{"C",2.0},{"C-",1.7},{"D+",1.3},{"D",1.0},{"F",0.0}}; //for generating values //from grades entered to perform calculations

class Course{           //class for course with course details
private:
    string name;
    int credits;
    string grade;
    double gradePoint;
public:
    Course(string name="unknown",int credits=0,string grade="unknown"); //constructor
    void setName(string name);          //mutators
    void setCredits(int credits);
    void setGrade(string grade);
    string getName(){return name;}      //accessors
    int getCredits(){return credits;}
    string getGrade(){return grade;}
    double getGradePoint(){return gradePoint;}
    double creditsEarned(){return gradePoint*credits;}
    friend ofstream & operator<<(ofstream &of, Course &c);  //operator overloading
    ~Course(){}
};
Course::Course(string name,int credits,string grade){
    setName(name);
    setCredits(credits);
    setGrade(grade);
    map<string,double>::iterator itr;
    itr=gradePoints.find(grade);    //finding corresponding grade value from grade
    this->gradePoint=itr->second;
}
void Course::setName(string name){
    if(name==" "){
        this->name="unknown";   //default value
    }
    else{
        this->name=name;
    }
}
void Course::setCredits(int credits){
    if(credits<=0){
        this->credits=0;        //default value
    }
    else{
        this->credits=credits;
    }
}
void Course::setGrade(string grade){
    if(grade==" "){
        this->grade="F";        //default value
    }
    else{
        this->grade=grade;
    }
}
ofstream & operator<<(ofstream &of, Course &c){
    of<<c.name<<" "<<c.credits<<" "<<c.grade<<endl; //for writing the course object into //file
    return of;
}
class Semester{
private:
    int numberOfCourses;
public:
    vector<Course> v;   //vector for storing each course of semester
    double semGpa;      //semester's gpa
    double totalGradePointsByStudent;
    double totalCreditsOfSem;       //total credits taken
    Semester(int numberOfCourses);
    void setNumberOfCourses(int numberOfCourses);
    int getNumberOfCourses(){return numberOfCourses;}
    double getSemGpa();
    friend ofstream & operator<<(ofstream &of, Semester &s);  //operator overloading
    ~Semester(){}
};
Semester::Semester(int numberOfCourses){
    setNumberOfCourses(numberOfCourses);
}
void Semester::setNumberOfCourses(int numberOfCourses){
    if(numberOfCourses<=0){
        this->numberOfCourses=0;
    }
    else{
        this->numberOfCourses=numberOfCourses;
    }
}
double Semester::getSemGpa(){
    semGpa=0.0;
    totalGradePointsByStudent=0;    //grade points earned by student for semester
    totalCreditsOfSem=0;            //total credits taken in semester
    for(int i=0;i<numberOfCourses;i++){
        totalGradePointsByStudent=totalGradePointsByStudent+v[i].creditsEarned(); //adding each course's credits earned
        //counting total units taken
        totalCreditsOfSem=totalCreditsOfSem+v[i].getCredits();
    }
    semGpa=totalGradePointsByStudent/totalCreditsOfSem;  //calculating gpa
    return semGpa;
}
ofstream & operator<<(ofstream &of, Semester &s){
    for(int i=0;i<s.numberOfCourses;i++){
        of<<s.v[i];                         //for writing whole semester i.e all                                       //courses into file
    }
    return of;
}
#endif /* gpaCalc_hpp */

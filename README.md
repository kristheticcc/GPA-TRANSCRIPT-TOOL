GPA-TRANSCRIPT TOOL

Overview

The GPA-Transcript Tool is a C++ program that helps students calculate GPAs for multiple semesters and generates a transcript in a .txt file. It allows users to input course details, calculate semester and overall GPAs, and generate a transcript with complete course information.

Features

GPA Calculation: Calculates semester-wise and overall GPA.
Transcript Generation: Outputs a detailed transcript file.
Customizable Input: Accepts user name, semesters, and course details.
Concepts Used

STL Vectors: For dynamic storage of courses.
STL Maps: For grade-to-point mapping.
Operator Overloading: For file handling with custom objects.
File Handling: Generates a transcript.txt file.
OOP Principles: Organized with classes (Course and Semester).
How It Works

Enter your name and number of semesters.
Input courses with their name, credits, and grades for each semester.
View calculated GPA for each semester and overall GPA.
Generate a transcript file (transcript.txt).

Example Output
Enter your name:krish Makwana
Enter the number of semesters to find GPA:2
--------------------------------------------------
Enter the number of courses you took in semester 1:6
Enter details for each course:
Enter for the course 1:
Enter the name of the course:GS101A
Enter the credits offered by course:1
Enter grade earned in course:A
Enter for the course 2:
Enter the name of the course:MATH130
Enter the credits offered by course:4
Enter grade earned in course:A
Enter for the course 3:
Enter the name of the course:ENG103
Enter the credits offered by course:3
Enter grade earned in course:A-
Enter for the course 4:
Enter the name of the course:ENG109
Enter the credits offered by course:1
Enter grade earned in course:A
Enter for the course 5:
Enter the name of the course:ENG106
Enter the credits offered by course:3
Enter grade earned in course:A-
Enter for the course 6:
Enter the name of the course:MLL111
Enter the credits offered by course:3
Enter grade earned in course:A-
GPA of semester1:3.82
--------------------------------------------------
Enter the number of courses you took in semester 2:5
Enter details for each course:
Enter for the course 1:
Enter the name of the course:MATH131
Enter the credits offered by course:3
Enter grade earned in course:A
Enter for the course 2:
Enter the name of the course:PHY135
Enter the credits offered by course:4
Enter grade earned in course:A
Enter for the course 3:
Enter the name of the course:CS201
Enter the credits offered by course:4
Enter grade earned in course:A
Enter for the course 4:
Enter the name of the course:CS211
Enter the credits offered by course:3
Enter grade earned in course:A
Enter for the course 5:
Enter the name of the course:ENG200
Enter the credits offered by course:3
Enter grade earned in course:A
GPA of semester2:4
Overall gpa of student:3.91563
Would you like to generate a transcript? Y or N:Y
Transcript has been generated in a file named transcript.txt
Program end.
Program ended with exit code: 0

Requirements

C++ Compiler supporting C++11.
Libraries: <iostream>, <vector>, <string>, <map>, <fstream>.
File Structure

gpaCalc.cpp: Main logic.
gpaCalc.hpp: Class and function definitions.

License

This project is open source and free to use.

Developed by Krish Makwana

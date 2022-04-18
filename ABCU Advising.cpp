// ABCU Advising.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


class Course {  // Course class definintions: Brandie Sheppard 4/12/22
    public:
        string courseNum;
        string courseName;
        vector<string>preReq;
};

vector<string> tokenize(string s, string del = "") {  // Function to split string into a list: Brandie Sheppard 4/12/2022
    vector<string>stringArray;
    int start = 0;
    int end = s.find(del);

    while (end != -1) {
        stringArray.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }

    stringArray.push_back(s.substr(start, end - start));
        return stringArray;
 }

vector<Course> LoadDataStructure() {

    ifstream fin("ABCU Advising.txt", ios::in);  // opening text file to read : S. Samual (02-Apr-2019) tutorialspoint.com
    vector<Course> courses;
    string line;

    while (getline(fin, line)) {  // infinite loop
        if (line == "-1")   //  if end of file is reached then break the loop: Brandie Sheppard 4/12/22
            break;

        Course course;

        vector<string> tokenizedinformation = tokenize(line, ",");   // getting tokenized information that will be separated by commas: cmacboyd (May 29, 2020) stackoverflow.com

      // Storing informtion
        course.courseNum = tokenizedinformation[0];
        course.courseName = tokenizedinformation[1];

        for (int i = 2; i < tokenizedinformation.size(); i++) {
            course.preReq.push_back(tokenizedinformation[i]);
        }
        courses.push_back(course);
    }

    fin.close();
    return courses;  // Will return the list of courses
}

void printCourse(Course course) {  // Printing course info in correct structure: cmacboyd (May 29, 2020) stackoverflow.com
    string courseNum = course.courseNum;
    string courseName = course.courseName;
    vector<string>preReq = course.preReq;

    cout << "Course Number: " << courseNum ;
    cout << "Course Name: " << courseName ;
    cout << "Prerequisites: " << endl;
    for (int i = 0; i < preReq.size(); i++) {
        cout << preReq[i] << " " << endl;
    }

}

void printCourseList(vector<Course> courses) {  // printing course info in correct format: cmacboyd (May 29, 2020) stackoverflow.com
    int x = courses.size();

    for (int i = 0; i < x - 1; i++) {  
        for (int y = 0; y < x - i - 1; i++) {
            if (courses[y].courseNum > courses[y + 1].courseNum) {
                swap(courses[y + 1], courses[y]);
            }
        }
    }
    for (int i = 0; i < x; i++) {
        printCourse(courses[i]);
    }
}

void searchCourse(vector<Course>courses) {
    int n = courses.size();
    string courseNum;
    int f = 0;

    cout << "Enter Course Number: ";
    cin >> courseNum;

    for (int i = 0; i < n; i++) {
        if (courses[i].courseNum == courseNum) { //  cmacboyd (May 29, 2020) stackoverflow.com
            f = 1;
            printCourse(courses[i]);
            break;
        }
    }
    if (f == 0) {
        cout << "Course not found" << endl;
    }
}

int main(int argc, char** argv) {  // Designing the display menu: Brandie Sheppard 4/11/22
    vector<Course>courses;
    // NA (02 Jun, 2021) geeksforgeeks.com
    cout << "1. Load Data Structure" << endl;
    cout << "2. Print Course List" << endl;
    cout << "3. Print Course" << endl;
    cout << "4. Exit" << endl;

    int ch;

    // Loop will break when "exit" is chosen: Brandie Sheppard 4/16/22

    do {
        cout << "Enter choice: ";
        cin >> ch;   // User enters choice: Brandie Sheppard 4/16/22

        switch (ch) {
            case 1: courses = LoadDataStructure();
            case 2: printCourseList(courses); 
            case 3: searchCourse(courses); 
            case 4: cout << "Exit" << endl;
                
            break;

            default: cout << "Invalid choice" << endl;
        }
    }

    while (ch != 4);

    return 0;
}

/* REFERENCES
S. Samual (02-Apr-2019) tutorialspoint.com
cmacboyd (May 29, 2020) stackoverflow.com
NA (02 Jun, 2021) geeksforgeeks.com
*/

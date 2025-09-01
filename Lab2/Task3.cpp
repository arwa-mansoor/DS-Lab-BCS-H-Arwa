#include <iostream>
using namespace std;

int main(){
    int totalStudents;
    cout << "Enter the total number of students: ";
    cin >> totalStudents;
    int *courses = new int[totalStudents];
    int **marks = new int*[totalStudents];
    for(int i = 0; i < totalStudents; i++){
        cout << "Enter the number of courses for Student " << i + 1 << ": ";
        cin >> courses[i];
    }
    for(int i = 0; i < totalStudents; i++){
        marks[i] = new int[courses[i]];
    }
    for(int i = 0; i < totalStudents; i++){
        cout << "Enter the marks for Student " << i + 1 << ":\n";
        for(int j = 0; j < courses[i]; j++){
            cout << "Course " << j + 1 << ": ";
            cin >> marks[i][j];
        }
    }
    int totalMarks = 0;
    cout << "Students' Average Marks:\n";
    for(int i = 0; i < totalStudents; i++){
        cout << "Student " << i + 1 << ": ";
        for(int j = 0; j < courses[i]; j++){
            totalMarks += marks[i][j];
        }
        cout << totalMarks / courses[i] << endl;
        totalMarks = 0;
    }
    delete[] courses;
    for(int i = 0; i < totalStudents; i++){
        delete[] marks[i];
    }
    delete[] marks;
    return 0;
}
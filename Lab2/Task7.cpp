#include <iostream>
using namespace std;

int main(){
    int totalDepartments;
    cout << "Enter the total number of departments: ";
    cin >> totalDepartments;

    int* noOfEmployees = new int[totalDepartments];
    for(int i = 0; i < totalDepartments; i++){
        cout << "Enter the number of employees for Department " << i + 1 << ": ";
        cin >> noOfEmployees[i];
    }

    int** departments = new int*[totalDepartments];
    for(int i = 0; i < totalDepartments; i++){
        departments[i] = new int[noOfEmployees[i]]();
    }

    for(int i = 0; i < totalDepartments; i++){
        cout << "Department " << i + 1 << ":\n";
        for(int j = 0; j < noOfEmployees[i]; j++){
            cout << "Enter salary for Employee " << j + 1 << ": ";
            cin >> departments[i][j];
        }
    }

    int total = 0;
    int max = -1;
    for(int i = 0; i < totalDepartments; i++){
        cout << "Department " << i + 1 << ":\n";
        for(int j = 0; j < noOfEmployees[i]; j++){
            total += departments[i][j];
            if(departments[i][j] > max){
                max = departments[i][j];
            }
        }
        cout << "Highest Salary: " << max << endl;
        cout << "Average Salary: " << total / noOfEmployees[i] << endl;
        max = -1;
        total = 0;
    }

}
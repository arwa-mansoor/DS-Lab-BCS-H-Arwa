#include<iostream>
using namespace std;

int main()
{
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;
    
    int** matrix = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols]();
    }
    
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "Enter value for [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
   for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "[" << i + 1 << "][" << j + 1 << "] = " << matrix[i][j] << endl;
        }
    }
   for(int i = 0; i < rows; i++){
       delete matrix[i];
   }
   delete[] matrix; 
   return 0;
}
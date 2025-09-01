#include <iostream>
using namespace std;
 
int** addition(int** arr1, int** arr2, int rows, int cols)
{
    int** result = new int*[rows];
    for(int i = 0; i < rows; i++){
        result[i] = new int[cols]();
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return result;
}
int** subtraction(int** arr1, int** arr2, int rows, int cols)
{
    int** result = new int*[rows];
    for(int i = 0; i < rows; i++){
        result[i] = new int[cols]();
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
    return result;
}

void printMatrix(int** arr, int rows, int cols){
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
    }
}

int main(){
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;
    int** matrix1 = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix1[i] = new int[cols]();
    }
    int** matrix2 = new int*[rows];
    for(int i = 0; i < rows; i++){
        matrix2[i] = new int[cols]();
    }
    int** result = new int*[rows];
    for(int i = 0; i < rows; i++){
        result[i] = new int[cols]();
    }
    int val;
    for(int i = 1; i <= 2; i++){
        cout << "Matrix " << i << ":\n";
        for(int j = 0; j < rows; j++){
            for(int k = 0; k < cols; k++){
                cout << "Enter the value for [" << j + 1 << "][" << k + 1 << "]: ";
                cin >> val;
                if(i == 1){
                    matrix1[j][k] = val;
                }
                else{
                    matrix2[j][k] = val;
                }
            }
        }
    }
    cout << "Matrix 1:\n";
    printMatrix(matrix1, rows, cols);

    cout << "Matrix 2:\n";
    printMatrix(matrix2, rows, cols);

    cout << "Result for Addition:\n";
    printMatrix(addition(matrix1, matrix2, rows, cols), rows, cols);

    cout << "Result for Subtraction:\n";
    printMatrix(subtraction(matrix1, matrix2, rows, cols), rows, cols);

    for(int i = 0; i < rows; i++){
        delete matrix1[i];
        delete matrix2[i];
        delete result[i];
    }
    delete[] matrix1;
    delete[] matrix2;
    delete[] result;
    return 0;
}
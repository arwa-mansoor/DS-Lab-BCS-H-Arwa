#include <iostream>
using namespace std;

int* resizeArray(int *arr, int oldSize, int newMonths){
    int *newArr = new int[newMonths + oldSize];
    for(int i = 0; i < oldSize; i++){
        newArr[i] = arr[i];
    }
    for(int i = oldSize; i < newMonths + oldSize; i++){
        newArr[i] = 0;
    }
    delete[] arr;
    return newArr;
}
int* addExpense(int *arr, int n){
    int index, expense, flag = 0;
    while(!flag){
        cout << "Enter the month number to add expenses: ";
        cin >> index;
        if(index > 0 && index <= n){
            cout << "Enter the expense for month " << index << ": ";
            cin >> expense;
            arr[index - 1] += expense;
            flag = 1;
        }
        else{
            cout << "Please enter the month number from 1 to " << n << endl;
        }        
    }


    return arr;
}
int main(){
    int n;
    cout << "Enter the total number of months: ";
    cin >> n;
    int *monthlyExpenses = new int[n];
    for(int i = 0; i < n; i++){
        monthlyExpenses[i] = 0;
    }
    int exit = 0, option, nMonths, totalExpenses = 0;
    while(exit == 0){
        cout << "Menu:\n";
        cout << "1 : Add Expenses\n";
        cout << "2 : Display Total and Average Expenses\n";
        cout << "3 : Add more months\n";
        cout << "0 : Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        switch(option){
            case 1:
                monthlyExpenses = addExpense(monthlyExpenses, n);
                break;
            case 2:
                for(int i = 0; i < n; i++){
                    totalExpenses += monthlyExpenses[i];
                }
                cout << "Total Expenses: " << totalExpenses << endl;
                cout << "Average Expenses: " << totalExpenses / n << endl;
                totalExpenses = 0;
                break;
            case 3:
                cout << "Enter the number of months to add: ";
                cin >> nMonths;
                monthlyExpenses = resizeArray(monthlyExpenses, n, nMonths);
                n += nMonths;
                break;
            case 0:
                cout << "Exiting...\n";
                exit = 1;
                break;
            default:
                cout << "Please enter the choices from 0 to 3\n";
        }
    }
    delete[] monthlyExpenses;
    return 0;
}
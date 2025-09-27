#include <iostream>
using namespace std;

void printNumbers(int n)
{
    if(n == 0)
    {
        cout << endl;
        return;
    }
    cout << " " << n;
    return printNumbers(n - 1);
}

void functionB(int n);

void functionA(int n)
{
    if(n == 0)
    {
        cout << endl;
        return;
    }
    cout << " " << n;
    return functionB(n - 1);
}

void functionB(int n)
{
    if(n == 0)
    {
        cout << endl;
        return;
    }
    cout << " " << n;
    return functionA(n - 1);
}

int main()
{
    int value;
    cout << "Enter a value: ";
    cin >> value;

    cout << "printNumber:";
    printNumbers(value);

    cout << "functionA:";
    functionA(value);

    cout << "functionB:";
    functionB(value);
    
    return 0;
}

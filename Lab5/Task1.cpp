#include <iostream>
using namespace std;

int calculateFactorial(int n)
{
    if(n == 0|| n == 1)
    {
        return 1;
    }
    
    return n * calculateFactorial(n - 1);
}

int main(){
    int value;
    cout << "Enter a value to find factorial: ";
    cin >> value;
    cout << "Factorial of " << value << " is " << calculateFactorial(value) << endl;
    return 0;
}

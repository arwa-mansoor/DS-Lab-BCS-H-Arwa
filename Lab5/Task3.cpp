#include <iostream>
using namespace std;

int sumTail(int n, int total)
{
    if(n == 0)
    {
        return total;
    }
    return sumTail(n - 1, total + n);
} 

int sumNonTail(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return n + sumNonTail(n - 1);
}

int main()
{
    int value;
    cout << "Enter a value: ";
    cin >> value;
    cout << "The sum of numbers from 1 to n using tail recursion is " << sumTail(value, 0) << endl;
    cout << "The sum of numbers from 1 to n using non-tail recursion is " << sumNonTail(value) << endl;

    return 0;
}

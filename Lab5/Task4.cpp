#include <iostream>
using namespace std;

int ackermann(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    if (m > 0 && n == 0)
    {
        return ackermann(m - 1, 1);
    }
    if (m > 0 && n > 0)
    {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
    return 0;
}

int main()
{
    int value1, value2;
    cout << "Enter the two values: ";
    cin >> value1 >> value2;
    cout << "Ackermann: " << ackermann(value1, value2);
    return 0;
}

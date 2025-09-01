#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = 0;
    }

    int pos;
    int flag = 1;
    int value;

    while (flag == 1)
    {
        cout << "Do you want to update value?(Enter '0' for 'No' or '1' for 'Yes'): ";
        cin >> flag;
        if (flag == 1)
        {
            cout << "Enter the position(1 to " << n << ") to update the value: ";
            cin >> pos;
            if (pos > 0 && pos <= n)
            {
                cout << "Enter the value: ";
                cin >> value;
                arr[pos - 1] = value;
            }
            else
            {
                cout << "Please enter the position 1 to " << n << " only.\n";
            }
        }
        else if (flag == 0)
        {
            cout << "Array:\n";
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " : " << arr[i] << endl;
            }
        }
        else
        {
            cout << "Please enter '0' for 'No' or '1' for 'Yes'.\n";
        }
    }
    delete[] arr;
    return 0;
}
#include <iostream>
using namespace std;

int linearSearch(int *arr, int searchValue)
{
    int index = 0;
    while (index < sizeof(arr)/sizeof(arr[0]))
    {
        if (searchValue == arr[index])
        {
            return index;
        }
        index++;
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *array = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }

    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    int index = linearSearch(array, value);

    if (index == -1)
    {
        cout << value << " not found in the array\n";
    }
    else
    {
        cout << value << " found at index " << index + 1 << " \n";
    }
    delete[] array;
    return 0;
}

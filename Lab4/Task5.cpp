#include <iostream>
using namespace std;

void displayArray(int *arr, int arrSize)
{
    int index = 0;
    while (index < arrSize)
    {
        cout << arr[index] << " ";
        index++;
    }
    cout << endl;
}

int interpolationSearch(int *arr, int arrSize, int searchValue)
{
    int left = 0, right = arrSize - 1;
    while(left <= right && searchValue >= arr[left] && searchValue <= arr[right])
    {
        if(left == right){
            if(arr[left] == searchValue)
            {
                return left;
            }
            return -1;
        }
        int pos = left + ((searchValue - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if(arr[pos] == searchValue)
        {
            return pos;
        }
        else if(searchValue > arr[pos])
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }
    return -1;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *array = new int[size];
    cout << "Enter sorted array\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }

    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    cout << "Array: ";
    displayArray(array, size);

    int index = interpolationSearch(array, size, value);

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

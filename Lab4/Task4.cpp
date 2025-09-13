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

void insertionSort(int *arr, int arrSize)
{
    for (int i = 1; i < arrSize; i++)
    {
        int value = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > value)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
}

int binarySearch(int *arr, int arrSize, int searchValue){
    int left = 0, right = arrSize - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == searchValue)
        {
            return mid;
        }
        else if (searchValue > arr[mid])
        {
            left = mid + 1;
        }
        else{
            right = mid - 1;
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

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array[i];
    }
    cout << "Unsorted Array: ";
    displayArray(array, size);

    insertionSort(array, size);
    cout << "Sorted Array: ";
    displayArray(array, size);

    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    int index = binarySearch(array, size, value);

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

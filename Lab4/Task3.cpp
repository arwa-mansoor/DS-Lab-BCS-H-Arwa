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

void selectionSort(int *arr, int arrSize)
{
    for(int i = 0; i < arrSize - 1; i++)
    {
        int index = i;
        for(int j = i + 1; j < arrSize; j++)
        {
            if(arr[j] < arr[index])
            {
                index = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
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

    selectionSort(array, size);
    cout << "Sorted Array: ";
    displayArray(array, size);

    delete[] array;

    return 0;
}

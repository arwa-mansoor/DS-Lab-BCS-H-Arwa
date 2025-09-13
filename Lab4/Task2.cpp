#include <iostream>
using namespace std;

void displayArray(int *arr, int arrSize)
{
    int index = 0;
    while(index < arrSize)
    {
        cout << arr[index] << " ";
        index++;
    }
    cout << endl;   
}

void bubbleSort(int *arr, int arrSize)
{
    bool swap = true;
    int max = arrSize;
    while(swap)
    {
        swap = false;
        for(int i = 0; i < max - 1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }
        max--;
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
    
    bubbleSort(array, size);
    cout << "Sorted Array: ";
    displayArray(array, size);

    delete[] array;

    return 0;
}

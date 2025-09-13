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

void combSort(int *arr, int arrSize)
{
    float shrink = 1.3;
    int gap = arrSize, swapCount = 0, comparisonsCount = 0;
    bool swap = true;
    while(gap > 1 || swap == true)
    {
        gap /= shrink;
        if(gap < 1)
        {
            gap = 1;
        }
        swap = false;
        for (int i = 0; i + gap < arrSize; i++)
        {
            comparisonsCount++;
            if(arr[i] > arr[i + gap])
            {
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swap = true;
                swapCount++;
            }
        }
    }
    cout << "Total number of swaps: " << swapCount << endl;
    cout << "Total number of comparisons: " << comparisonsCount << endl;
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

    combSort(array, size);
    cout << "Sorted Array: ";
    displayArray(array, size);

    delete[] array;

    return 0;
}

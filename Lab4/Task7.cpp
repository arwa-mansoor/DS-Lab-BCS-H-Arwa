#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

void shellSort(int *arr, int arrSize)
{
    auto start = high_resolution_clock::now();
    int comparisonCount = 0, swapCount = 0;
    for(int gap = arrSize / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < arrSize; i++)
        {
            int temp = arr[i];
            int index = i;
            while(index >= gap && arr[index - gap] > temp)
            {
                comparisonCount++;
                arr[index] = arr[index - gap];
                swapCount++;
                index -= gap;
            }
            arr[index] = temp;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Total number of swaps: " << swapCount << endl;
    cout << "Total number of comparisons: " << comparisonCount << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}

void insertionSort(int *arr, int arrSize)
{
    auto start = high_resolution_clock::now();
    int swapCount = 0;
    for (int i = 1; i < arrSize; i++)
    {
        int value = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > value)
        {
            swapCount++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = value;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Total number of swaps: " << swapCount << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}

void bubbleSort(int *arr, int arrSize)
{
    auto start = high_resolution_clock::now();
    int comparisonCount = 0, swapCount = 0;
    bool swap = true;
    int max = arrSize;
    while (swap)
    {
        swap = false;
        for (int i = 0; i < max - 1; i++)
        {
            comparisonCount++;
            if (arr[i] > arr[i + 1])
            {
                swapCount++;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap = true;
            }
        }
        max--;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "Total number of swaps: " << swapCount << endl;
    cout << "Total number of comparisons: " << comparisonCount << endl;
    cout << "Time taken: " << duration.count() << " microseconds" << endl;
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    int *array1 = new int[size];
    int *array2 = new int[size];
    int *array3 = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter element " << i + 1 << ": ";
        cin >> array1[i];
    }
    for(int i = 0; i < size; i++){
        array2[i] = array3[i] = array1[i];
    }
    
    cout << endl;
    cout << "Unsorted Array: "; 
    displayArray(array1, size);
    cout << endl;

    cout << "Shell Sort\n";
    shellSort(array1, size);
    cout << endl;

    cout << "Bubble Sort\n";
    bubbleSort(array2, size);
    cout << endl;

    cout << "Insertion Sort\n";
    insertionSort(array3, size);
    cout << endl;

    cout << "Sorted Array: ";
    displayArray(array1, size);

    delete[] array1;
    delete[] array2;
    delete[] array3;

    return 0;
}

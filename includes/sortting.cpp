#include <iostream>
using namespace std;

extern int count_compare, count_assign;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; ++count_compare && i < n - 1; ++i && ++count_assign)
    {
        for (int j = i + 1; ++count_compare && j < n; ++count_assign && ++j)
        {
            if (++count_compare && arr[j] > arr[i])
            {
                swap(arr[i], arr[j]);
                count_assign += 3;    
                //int temp = arr[i];
                //arr[i] = arr[j];
                //arr[j] = temp;
            }
        }
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void insertionSort(int arr[], int n)
{
    int i = 1;
    while(i < n)
    {
        int j = i;
        int choose = arr[i];
        bool check = false;
        while(j > 0 && choose > arr[j - 1])
        {
            check = true;
            j--;
        }
        if (check)
        {
            for (int k = i; k > j; --k)
            {
                arr[k] = arr[k - 1];
            }
            arr[j] = choose;
        }
        i++;
    }
}

void shorterInsertionSort(int arr[], int n)
{
    for (int i = 1; ++count_compare && i < n; ++count_assign && ++i)
    {
        int choose = arr[i]; ++count_assign;
        int j = i - 1; ++count_assign;
        while(++count_compare && choose > arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j]; ++count_assign;
            j--; ++count_assign;
        }
        arr[j + 1] = choose; ++count_assign;
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int max = arr[i];
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] > max)
            {
                swap(arr[j], max);
                //int temp = max;
                //max = arr[j];
                //arr[j] = temp;
            }
        }
        arr[i] = max;
    }
}

void maxHeapRebuild(int arr[], int n, int pos)
{
    bool isHeap = false; 
    while(!isHeap && 2 * pos + 1 < n)
    {
        int child_index = 2 * pos + 1;                     
        int child = arr[child_index];                      
        if (child_index < n - 1)
            if (child < arr[child_index + 1]) child_index++;   
                                                           
        if (arr[pos] >= arr[child_index]) isHeap = true;    
        else                                               
        {                                                  
            swap(arr[pos], arr[child_index]);              
            pos = child_index;       //go to the child node to recreate max heap                      
        }                                                  
    }
}

void minHeapRebuild(int arr[], int n, int pos)
{
    bool isHeap = false; 
    while(!isHeap && 2 * pos + 1 < n)
    {
        int child_index = 2 * pos + 1;                     
        int child = arr[child_index];                      
        if (child_index < n - 1)
            if (child > arr[child_index + 1]) child_index++;   
                                                           
        if (arr[pos] <= arr[child_index]) isHeap = true;    
        else                                               
        {                                                  
            swap(arr[pos], arr[child_index]);              
            pos = child_index;       //go to the child node to recreate max heap                      
        }                                                  
    }
}


void heapConstruction(int arr[], int n)
{
    int index = n / 2 - 1; //make the heap from the middle of the arr to the first item
    while(index >= 0)
    {
        //maxHeapRebuild(arr, n, index);
        minHeapRebuild(arr, n , index);
        index--;
    }
}

void heapSort(int arr[], int n)
{
    heapConstruction(arr, n);
    int r = n - 1;
    while(r > 0)
    {
        swap(arr[0], arr[r]);
        cout << "Before sort:\n"; printArr(arr, n);

        //maxHeapRebuild(arr, r, 0); //maxHeap will make a ascending sort and vice versa
        minHeapRebuild(arr, r, 0);

        cout << "After sort:\n"; printArr(arr, n);
        r--;
    }
}

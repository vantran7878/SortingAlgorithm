#include "includes/includes.h"
#include "includes/generateData.h"

using namespace std;

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


void longerInsertionSort(int arr[], int n)
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

void insertionSort(int arr[], int n)
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
    bool isHeap = false; count_assign++;
    while(++count_compare && !isHeap && 2 * pos + 1 < n)
    {
        int child_index = 2 * pos + 1; count_assign++; 
        int child = arr[child_index]; count_assign++;      
        if (++count_compare && child_index < n - 1)
            if (++count_compare && child > arr[child_index + 1]) 
            {
                child_index++;   ++count_assign;
            }
        if (++count_compare && arr[pos] <= arr[child_index]) 
        {
            isHeap = true;      ++count_assign; 
        }
        else                                               
        {                                                  
            swap(arr[pos], arr[child_index]); count_assign += 3; 
            pos = child_index;  ++count_assign;    //go to the child node to recreate max heap                      
        }                                                  
    }
}


void heapConstruction(int arr[], int n)
{
    int index = n / 2 - 1; count_assign++; //make the heap from the middle of the arr to the first item
    while(++count_compare && index >= 0)
    {
        //maxHeapRebuild(arr, n, index);
        minHeapRebuild(arr, n , index);
        index--; ++count_assign;
    }
}

void heapSort(int arr[], int n)
{
    heapConstruction(arr, n);
    int r = n - 1; count_assign++;
    while(++count_compare && r > 0)
    {
        swap(arr[0], arr[r]);
        count_assign += 3; 

        //maxHeapRebuild(arr, r, 0); //maxHeap will make a ascending sort and vice versa
        minHeapRebuild(arr, r, 0);
        r--;
        ++count_assign;
    }
}

int Partition(int* arr, int first, int last)
{
    int pivotIndex = first, pivot = arr[pivotIndex], lastS1 = first, firstUnknown = first + 1;    count_assign += 4;
    while(++count_compare && firstUnknown <= last)
    {
        if (++count_compare && arr[firstUnknown] > pivot)
        {
            lastS1++;
            swap(arr[lastS1], arr[firstUnknown]);
            count_assign += 4;
        }
        ++firstUnknown; ++count_assign;
    }
    swap(arr[first], arr[lastS1]);
    pivotIndex = lastS1;
    count_assign += 4;
    return pivotIndex;
}

void makeQuickSort(int* arr, int first, int last)
{
    if (++count_compare && first < last)
    {
        int pivotIndex = Partition(arr, first, last); ++count_assign;
        makeQuickSort(arr, first, pivotIndex - 1);
        makeQuickSort(arr, pivotIndex + 1, last);
    }
}

void quickSort(int* arr, int n)
{
    makeQuickSort(arr, 0, n - 1);
}

int* merging(int* arr_left, int* arr_right, int n_left, int n_right)
{
    int* new_arr = new int[n_left + n_right];
    int i_new = 0, i_left = 0, i_right = 0;

    while(i_left < n_left && i_right < n_right)
    {
        if (arr_left[i_left] >= arr_right[i_right])
        {
            new_arr[i_new] = arr_left[i_left];
            i_left++;
        }
        else 
        {
            new_arr[i_new] = arr_right[i_right];
            i_right++;
        }
        i_new++;
    }
    
    while(i_left < n_left)
    {
        new_arr[i_new] = arr_left[i_left];
        i_left++;
        i_new++;
    }

    while(i_right < n_right)
    {
        new_arr[i_new] = arr_right[i_right];
        i_right++;
        i_new++;
    }
    return new_arr;
}

void Merge(int* arr, int left, int mid, int right)
{
    int n_left = mid - left + 1, n_right = right - mid;
    
    int* arr_left = new int[n_left];
    int* arr_right = new int[n_right];

    for (int i = 0; i < n_left; ++i)
        arr_left[i] = arr[left + i];
    for (int j = 0; j < n_right; ++j)
        arr_right[j] = arr[mid + j + 1];

    int i = 0, j = 0, k = left;    
    while(i < n_left && j < n_right)
    {
        if (arr_left[i] >= arr_right[j])
        {
            arr[k] = arr_left[i];
            i++;
        }
        else
        {
            arr[k] = arr_right[j];
            j++;
        }
        k++;
    }

    while(i < n_left)
    {
        arr[k] = arr_left[i];
        i++;
        k++;
    }
    
    while(j < n_right)
    {
        arr[k] = arr_right[j];
        j++;
        k++;
    }
    delete[] arr_left;
    delete[] arr_right;
}

void mergeSortProcess(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSortProcess(arr, left, mid);
        mergeSortProcess(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

void mergeSort(int* arr, int n)
{
    mergeSortProcess(arr, 0, n - 1);
}


void countingSort(int* arr, int n, int exp)
{
    int count[10] = {0}, output[n], i;
    for (i = 0; i < n; ++i) 
    {
        count[(arr[i] / exp) % 10]++; 
    }
    for (i = 1; i < 10; ++i)
    {
        count[i] += count[i - 1];
    }

    for (i = n - 1; i >= 0; --i)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; ++i)
        arr[i] = output[i];
}

int findMax(int* arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max) max = arr[i];
    return max;
}

int findMin(int* arr, int n)
{
    int min = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] < min) min = arr[i];
    return min;
}

void radixSort(int* arr, int n)
{
    int m = findMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10) 
        countingSort(arr, n, exp);
}
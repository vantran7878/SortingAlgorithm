#include <iostream>
#include "includes/sortting.h"
using namespace std;

int count_compare, count_assign;
/// sort descending: max at first



int main()
{
    int arr[7] = {5, 8, 7, 1, 9, 6, 3};
    int n = 7;

    count_compare = 0; count_assign = 0;
    //bubbleSort(arr, n);
    //insertionSort(arr, n);
    //shorterInsertionSort(arr, n);
    //selectionSort(arr, n);
    heapSort(arr, n);
    //heapConstruction(arr, n);
    printArr(arr, n);
    cout << count_compare << '\n' << count_assign <<'\n';

    return 0;
}
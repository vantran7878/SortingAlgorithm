#include <iostream>
#include "includes/sortting.h"
using namespace std;

int count_compare, count_assign;
/// sort descending: max at first



int main(int argc, char* argv[])
{
    int arr[7] = {5, 8, 7, 1, 9, 6, 3};
    int n = 7;

    string algorithm= argv[2];
    int inputSize = stoi(argv[3]);
    string outputParam = argv[4];

    cout << "Algorithm: " << algorithm << '\n';
    cout << "Input Size: " << inputSize << '\n';
    cout << "Output Parameter: " << outputParam << '\n';
    
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
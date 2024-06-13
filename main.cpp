#include <iostream>
#include "includes/sortting.h"
#include "includes/AlgorithmMode.h"
using namespace std;

int count_compare, count_assign;
typedef void (*function)(int*, int);

/// sort descending: max at first

int main(int argc, char* argv[])
{
    int arr[7] = {5, 8, 7, 1, 9, 6, 3};
    int n = 7;
    count_compare = 0; count_assign = 0;
    function sortFunc = chooseAlgorithm(argv[2]);
    sortFunc(arr, n);
//    int inputSize = stoi(argv[3]);
//    string outputParam = argv[4];
    
    printArr(arr, n);
    cout << count_compare << '\n' << count_assign <<'\n';

    return 0;
}
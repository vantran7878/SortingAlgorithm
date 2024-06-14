#include "includes/includes.h"
using namespace std;

unsigned long count_compare, count_assign;
typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int n);

/// sort descending: max at first

int main(int argc, char* argv[])
{
    //----------------initializing and access the MODE
    srand(time(0));
    char mode = argv[1][1];
    if (mode == 'a') displayAlgorithm(argv);
    else if (mode == 'c') displayComparison(argv);
    else if (mode == 'e') displayEntire(argv);

    //int arr[7] = {5, 4, 7, 8, 1, 3, 0};
    //quickSort(arr, 7);
    //printArr(arr, 7);
    return 0;
}
#include "includes/includes.h"
using namespace std;

unsigned long count_compare, count_assign;
typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int n);

const char* err_msg = "Wrong Input Command Line";
/// sort descending: max at first

char getCharMode(int argc, char** argv)
{
    bool checkCmdLine = false;
    for (int i = 0; i < argc; ++i)
    {
        if (argv[i][0] == '-' && !argv[i][2]) 
        {
            checkCmdLine = true;
            return argv[i][1];
        }
    }
    if (!checkCmdLine) 
    {
        cerr << err_msg; 
        return '\0';
    }
    return '\0';
}

int main(int argc, char* argv[])
{
    //----------------initializing and access the MODE
    srand(time(0));
    char mode = getCharMode(argc, argv);

    if (mode == 'a') displayAlgorithm(argc, argv);
    else if (mode == 'c') displayComparison(argc, argv);
    else if (mode == 'e') displayEntire(argc, argv);
    else if (mode == '\0') return -1;

    //int arr[7] = {5, 4, 7, 8, 1, 3, 0};
    //int arr2[8] = {6, 2, 9, 12, 15, 10, 18, 20};
    //radixSort(arr, 7);
    ////quickSort(arr, 7);
    //printArr(arr, 7);
    return 0;
}
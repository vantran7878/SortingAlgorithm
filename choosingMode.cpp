#include "includes/includes.h"
const char* QUICK = "quick";
const char* MERGE = "merge";
const char* BUBBLE = "bubble";
const char* INSERT = "insert";
const char* SELECT = "select";
const char* HEAP = "heap";
const char* RANDOM = "random";
const char* SORTED = "sorted";
const char* REVERSED = "reversed"; 

typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int);

func chooseAlgorithm(char* argv)
{
    if (strcmp(argv, HEAP) == 0) return heapSort;
    else if (strcmp(argv, BUBBLE) == 0) return bubbleSort;
    else if (strcmp(argv, INSERT) == 0) return insertionSort;
    else if (strcmp(argv, SELECT) == 0) return selectionSort;
    else if (strcmp(argv, QUICK) == 0) return quickSort;
    return NULL;
}

generateFunc chooseOrder(char* argv)
{
    if (strcmp(argv, RANDOM) == 0) return generateRandom;               
    else if (strcmp(argv, SORTED) == 0) return generateSorted;
    else if (strcmp(argv, REVERSED) == 0) return generateReversed;
    return NULL;
}
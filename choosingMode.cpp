#include "includes/includes.h"
const char* QUICK = "quick";
const char* MERGE = "merge";
const char* BUBBLE = "bubble";
const char* INSERT = "insert";
const char* SELECT = "select";
const char* RADIX = "radix";
const char* HEAP = "heap";
const char* RANDOM = "-rand";
const char* SORTED = "-sorted";
const char* REVERSED = "-rev"; 
const char* NEARLY = "-nsorted";


typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int);

func chooseAlgorithm(int argc, char** argv)
{
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], HEAP) == 0) return heapSort;
        else if (strcmp(argv[i], BUBBLE) == 0) return bubbleSort;
        else if (strcmp(argv[i], INSERT) == 0) return insertionSort;
        else if (strcmp(argv[i], SELECT) == 0) return selectionSort;
        else if (strcmp(argv[i], QUICK) == 0) return quickSort;
        else if (strcmp(argv[i], RADIX) == 0) return radixSort;
        else if (strcmp(argv[i], MERGE) == 0) return mergeSort;
    }
    return NULL;
}

func choose2Algorithm(int argc, char** argv, func prev_func)
{
    for (int i = 1; i < argc; ++i)
    {
        if (strcmp(argv[i], HEAP) == 0) return heapSort;
        else if (strcmp(argv[i], BUBBLE) == 0) return bubbleSort;
        else if (strcmp(argv[i], INSERT) == 0) return insertionSort;
        else if (strcmp(argv[i], SELECT) == 0) return selectionSort;
        else if (strcmp(argv[i], QUICK) == 0) return quickSort;
        else if (strcmp(argv[i], RADIX) == 0) return radixSort;
        else if (strcmp(argv[i], MERGE) == 0) return mergeSort;
    }
    return NULL;
}

generateFunc chooseOrder(int argc, char** argv)
{
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], RANDOM) == 0) return generateRandom;               
        else if (strcmp(argv[i], SORTED) == 0) return generateSorted;
        else if (strcmp(argv[i], REVERSED) == 0) return generateReversed;
        else if (strcmp(argv[i], NEARLY) == 0) return generateNearlySorted;
    }
    return NULL;
}
#include <cstring>
#include "includes/sortting.h"
const char* QUICK = "quick";
const char* MERGE = "merge";
const char* BUBBLE = "bubble";
const char* INSERT = "insert";
const char* SELECT = "select";
const char* HEAP ="heap";

typedef void (*function)(int*, int);

function chooseAlgorithm(char* argv)
{
    if (strcmp(argv, HEAP) == 1) return heapSort;
    else if (strcmp(argv, BUBBLE)) return bubbleSort;
    else if (strcmp(argv, INSERT)) return insertionSort;
    else if (strcmp(argv, SELECT)) return selectionSort;
}
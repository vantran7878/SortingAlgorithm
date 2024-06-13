#include "includes/includes.h"
const char* QUICK = "quick";
const char* MERGE = "merge";
const char* BUBBLE = "bubble";
const char* INSERT = "insert";
const char* SELECT = "select";
const char* HEAP ="heap";

typedef void (*function)(int*, int);

function chooseAlgorithm(char* argv)
{
    if (strcmp(argv, HEAP) == 0) return heapSort;
    else if (strcmp(argv, BUBBLE) == 0) return bubbleSort;
    else if (strcmp(argv, INSERT) == 0) return insertionSort;
    else if (strcmp(argv, SELECT) == 0) return selectionSort;
}
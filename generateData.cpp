#include "includes/includes.h"

int* generateRandom(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % n;
    }
    return arr;
}
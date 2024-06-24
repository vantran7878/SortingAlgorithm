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

int* generateReversed(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    return arr;
}

int* generateSorted(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = n - i;
    }
    return arr;
}

int* generateNearlySorted(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = n - i;
    }

    int random = rand() % 1000;
    for (int i = 0; i < random; ++i)
    {
        arr[rand() % n] = rand() % n;
    }
    return arr;
}

int* duplicateArray(int* arr, int n)
{
    int* new_arr = new int [n]; 
    for (int i = 0; i < n; ++i)
    {
        new_arr[i] = arr[i];
    }
    return new_arr;
}

void copyArray(int* src, int* des, int n)
{
    for (int i = 0; i < n; ++i)
    {
        des[i] = src[i];
    }
    return;
}
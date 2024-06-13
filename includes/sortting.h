#pragma once
#include <string>

extern unsigned long count_assign, count_compare;

void bubbleSort(int arr[], int n);

void printArr(int arr[], int n);

void insertionSort(int arr[], int n);

void shorterInsertionSort(int arr[], int n);

void heapRebuild(int arr[], int n, int pos);

void heapConstruction(int arr[], int n);

void heapSort(int arr[], int n);

void selectionSort(int arr[], int n);
#include "includes/includes.h"

const char* COMPARE = "-comp";
const char* TIME = "-time";
const char* BOTH = "-both";
extern char* err_msg;

typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int n);

int getNumber(int n, char** s) //return the index of the string\, -1 for wrong
{
    for (int i = 0; i < n; ++i)
    {
        if (s[i][0] >= '0' && s[i][0] <='9')
        return stoi(s[i]);
    }
    return -1;
}

char* getName(func function)
{
    char* name = new char[20];
    if (function == bubbleSort) strcpy(name, "BUBBLESORT");
    else if (function == insertionSort) strcpy(name, "INSERTIONSORT");
    else if (function == heapSort) strcpy(name, "HEAPSORT");
    else if (function == mergeSort) strcpy(name, "MERGESORT");
    else if (function == quickSort) strcpy(name, "QUICKSORT");
    else if (function == radixSort) strcpy(name, "RADIXSORT");
    else if (function == selectionSort) strcpy(name, "SELECTIONSORT");
    else return NULL;
    return name;
}

char* getOutputMode(int argc, char** argv)
{
    char* outputMode = new char[20];
    for (int i = 0; i < argc; ++i)
    {
        if (strcmp(argv[i], TIME) == 0) 
        {
            strcpy(outputMode, "-time");
            break;
        }
        else if (strcmp(argv[i], COMPARE) == 0)
        {
            strcpy(outputMode, "-comp");
            break;
        } 
        else if (strcmp(argv[i], BOTH) == 0) 
        {
            strcpy(outputMode, "-both");
            break;
        } 
        else strcpy(outputMode, "NULL"); 
    }
    return outputMode;
}


void displayAlgorithm(int argc, char* argv[])
{
    func sortFunc = chooseAlgorithm(argc, argv);
    if (!sortFunc) 
    {
        cerr << err_msg;
        return;
    }
    generateFunc order = chooseOrder(argc, argv);
    if (!order) 
    {
        cerr << err_msg;
        return;
    } 

    int n = getNumber(argc, argv);
    if (n == -1)
    {
        cerr << err_msg;
        return;
    } 

    int* org_arr = order(n);
    int* arr = duplicateArray(org_arr, n);
    count_compare = 0; count_assign = 0;

    //-----------------Sort and then calculate the time between them
    auto start = chrono::system_clock::now();
    sortFunc(arr, n);
    auto end = chrono::system_clock::now();

    auto millis = chrono::duration_cast <chrono::milliseconds>(end - start).count();
    auto seconds = millis / 1000;
    auto milliseconds = millis % 1000;
    //--------------------print the result    
    char* outputMode = getOutputMode(argc, argv);
    if (outputMode == "NULL")
    {
        cerr << "Wrong input command line";
        return;
    }
    cout << "ALGORITHM MODE:\n" << getName(sortFunc) << ":\n";
    if (strcmp(outputMode, "-time") == 0) 
        cout << "Time: " << seconds << "." << setw(3) << setfill('0') << milliseconds << " seconds" << '\n';
    else if (strcmp(outputMode, "-comp") == 0) 
        cout << "Comparison: " << count_compare << '\n' << "Assignment: " << count_assign <<'\n';
    else if (strcmp(outputMode, "-both") == 0)
    {
        cout << "Time: " << seconds << "." << setw(3) << setfill('0') << milliseconds << " seconds" << '\n'; 
        cout << "Comparison: " << count_compare << '\n' << "Assignment: " << count_assign <<'\n';
    }
    delete arr;
    delete outputMode;
    delete org_arr;
}

auto calcTime(func sortFunc, int* arr, int n)
{
    auto start = chrono::system_clock::now();
    sortFunc(arr, n);
    auto end = chrono::system_clock::now();

    auto millis = chrono::duration_cast <chrono::milliseconds>(end - start).count();
    return millis;
}

void printResultAll(auto seconds, auto milliseconds)
{
    cout << "Time: " << seconds << "." << setw(3) << setfill('0') << milliseconds << " seconds" << '\n'; 
    cout << "Comparison: " << count_compare << '\n' << "Assignment: " << count_assign <<'\n';
}

void displayEntire(int argc, char* argv[])
{
    // main.cpp -e 50000 random
    generateFunc order = chooseOrder(argc, argv);
    int n = stoi(argv[2]);
    int* org_arr = order(n);
    int* arr = duplicateArray(org_arr, n);
    count_compare = 0; count_assign = 0;

    func arr_func[7] = {bubbleSort, selectionSort, insertionSort, heapSort, mergeSort, quickSort, radixSort};

    for (int i = 0; i < 7; ++i)
    {
        auto millis = calcTime(arr_func[i], arr, n);
        auto seconds = millis / 1000;
        auto milliseconds = millis % 1000;
        cout << getName(arr_func[i]) << '\n';
        printResultAll(seconds, milliseconds);
        copyArray(org_arr, arr, n);
        count_assign = 0;
        count_compare = 0;
    }
    delete[] arr;
    delete[] org_arr;
}


void displayComparison(int argc, char* argv[])
{
    generateFunc order = chooseOrder(argc, argv);
    if (!order) 
    {
        cout << err_msg;
        return;
    }
    func sortFunc1 = chooseAlgorithm(argc, argv);
    if (!sortFunc1) 
    {
        cerr << err_msg;
        return;
    }
    func arr_func[2] = {chooseAlgorithm(argc, argv), chooseAlgorithm(argc, argv)};

    int n = getNumber(argc, argv);
    int* org_arr = order(n);
    int* arr = duplicateArray(org_arr, n);
    count_compare = 0; int count_compare1 = 0, count_compare2 = 0;


    cout << "COMPARISON MODE\n";
    cout << "Algorithm: " << getName(arr_func[0]) << " | " << getName(arr_func[1]) <<'\n';
    cout << "Input size: " << n << '\n';
    cout << "Input order: " << order << '\n';
    cout << "----------------------\n";
    cout << "Running time: ";
    auto millis = calcTime(arr_func[0], arr, n);
    auto seconds = millis / 1000;
    auto milliseconds = millis % 1000;
    cout << seconds << "." << setw(3) << setfill('0') << milliseconds << " s" << " | "; 
    copyArray(org_arr, arr, n);
    count_compare1 = count_compare; count_compare = 0;

    millis = calcTime(arr_func[1], arr, n);
    seconds = millis / 1000;
    milliseconds = millis % 1000;
    cout << seconds << "." << setw(3) << setfill('0') << milliseconds << " s" << '\n'; 
    count_compare2 = count_compare;

    cout<< "Comparisons: " << count_compare1 << '|' << count_compare2 << '\n';

    delete[] arr;
    delete[] org_arr;

}






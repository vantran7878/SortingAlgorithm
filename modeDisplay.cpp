#include "includes/includes.h"

const char* COMPARE = "-comp";
const char* TIME = "-time";
const char* BOTH = "-both";

typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int n);

void displayAlgorithm(char* argv[])
{
    func sortFunc = chooseAlgorithm(argv[2]);
    generateFunc order = chooseOrder(argv[4]);
    int n = stoi(argv[3]);
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
    argv[2] = strupr(argv[2]);
    cout << "ALGORITHM MODE:\n" <<  argv[2] << ":\n";
    if (strcmp(argv[5], TIME) == 0) 
        cout << "Time: " << seconds << "." << setw(3) << setfill('0') << milliseconds << " seconds" << '\n';
    else if (strcmp(argv[5], COMPARE) == 0) 
        cout << "Comparison: " << count_compare << '\n' << "Assignment: " << count_assign <<'\n';
    else if (strcmp(argv[5], BOTH) == 0)
    {
        cout << "Time: " << seconds << "." << setw(3) << setfill('0') << milliseconds << " seconds" << '\n'; 
        cout << "Comparison: " << count_compare << '\n' << "Assignment: " << count_assign <<'\n';
    }
    delete arr;
}

void displayComparison(char* argv[])
{

}

void displayEntire(char* argv[])
{
    
}
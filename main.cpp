#include "includes/includes.h"
using namespace std;

unsigned long count_compare, count_assign;
typedef void (*func)(int*, int);

/// sort descending: max at first

int main(int argc, char* argv[])
{
    srand(time(0));
    int n = 30000;
    int* arr = generateRandom(n);
    count_compare = 0; count_assign = 0;
    func sortFunc = chooseAlgorithm(argv[2]);
    
    auto start = chrono::system_clock::now();
    sortFunc(arr, n);
    auto end = chrono::system_clock::now();

    auto millis = chrono::duration_cast <chrono::milliseconds>(end - start).count();

    auto seconds = millis / 1000;
    auto milliseconds = millis % 1000;
//    int inputSize = stoi(argv[3]);
//    string outputParam = argv[4];
    
    //printArr(arr, n);
    cout << "Time: " << seconds << "." << setw(10) << setfill('0') << milliseconds << " seconds" << '\n';
    cout << "Comparison: " << count_compare << '\n' << "Assignment: " << count_assign <<'\n';

    delete arr;
    return 0;
}
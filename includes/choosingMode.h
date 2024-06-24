typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int n);

func chooseAlgorithm(int argc, char** argv);
generateFunc chooseOrder(int argc, char** argv);
char* getFuncName(func sortFunc);

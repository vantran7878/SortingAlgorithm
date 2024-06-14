typedef void (*func)(int*, int);
typedef int* (*generateFunc)(int n);

func chooseAlgorithm(char* argv);
generateFunc chooseOrder(char* argv);

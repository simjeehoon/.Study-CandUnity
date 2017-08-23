#include "main.h"
void SimpleFuncOne(int *arr1, int *arr2){}
void SimpleFuncTwo(int (*arr3)[4], int (*arr4)[4]){}
int yunm180102() {
	int arr1[3];
	int arr2[4];
	int arr3[3][4];
	int arr4[2][4];

	SimpleFuncOne(arr1, arr2);
	SimpleFuncTwo(arr3, arr4);
	return 0;
}


void ComplexFuncOne(int ** arr1, int *(*arr2)[5]) {}
void ComplexFuncTwo(int *** arr3, int ***(*arr4)[5]) {}
int yunm180103() {
	int* arr1[3];
	int* arr2[3][5];
	int** arr3[5];
	int*** arr4[3][5];

	ComplexFuncOne(arr1, arr2);
	ComplexFuncTwo(arr3, arr4);
	return 0;
}

/*
	arr[i] == *(arr+i)
	
	3 2
	6 4
	5 2
	1 1
*/
/*
arr[i] == *(arr+i)
	arr[1][0][1] == (*(*(arr+1)+0))[1] == (*(*(arr+1)+0))[1] == *(*(*(arr+1)+0)+1)
	== *(*(arr[1]+0)+1) == *(arr[1][0]+1) == arr[1][0][1]

*/
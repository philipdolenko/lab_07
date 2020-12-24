// lab_07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int* getArray() {
	int size;

	cout << "Array size = ";
	cin >> size;

	int *a = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "arr[" << i << "] = ";
		cin >> a[i];
		cout << endl;
	}

	return a;
}

void moveElementBack(int *arr, int i)
{
	int buff;
	buff = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = buff;
}

void shakeSort(int *arr)
{
	int size = sizeof(arr);

	int start = 1;//comparing element with prev => ignoring index № 0 
	int end = size - 1;
	
	while (start <= end)
	{
		for (int i = end; i >= start; i--) {
			if (arr[i - 1] > arr[i]) {
				moveElementBack(arr, i);
			}
		}	
		start++;


		for (int i = start; i <= end; i++) {
			if (arr[i - 1] > arr[i]) {
				moveElementBack(arr, i);
			}
		}
		end--;
	}
}

void printArray(int *arr) {
	for (int i = 0; i < sizeof(arr); i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}
}

int main()
{
	int *array = getArray();

	shakeSort(array);

	printArray(array);

	return 0;
}
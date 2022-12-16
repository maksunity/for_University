#include <iostream> //
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;
int n;
int arr, F1, F2, F3;

void Merge_natural(int* A, int first, int last)
{
	int* mas = new int[n];
	int middle = (first + last) / 2;
	int start = first;
	int final = middle + 1;
	for (int i = first; i <= last; i++)
	{
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[i] = A[start];
			start++;
		}
		else
		{
			mas[i] = A[final];
			final++;
		}
	}
	for (int i = first; i <= last; i++)
	{
		A[i] = mas[i];
	}
	delete[]mas;
}

void MergeSort(int* A, int first, int last)
{
	if (first < last)
	{
		MergeSort(A, first, (first + last) / 2);
		MergeSort(A, (first + last) / 2 + 1, last);
		Merge_natural(A, first, last);
	}
}

int main()
{
	cout << "Enter size of array: ";
	cin >> n;
	srand(time(NULL));
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() / 100;
		cout << arr[i] << " ";
	}
    Merge_natural(arr, 0, n - 1);
	cout << endl << "After sort: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
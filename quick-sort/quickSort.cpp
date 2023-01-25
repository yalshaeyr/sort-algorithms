#include <iostream>
#include <fstream>
using namespace::std;

// Make generic
void swap(int arr[], int left, int right)
{
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp; 
}

void printArray(int arr[], int end, int start = 0)
{
	for (int i = start; i < end; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
}


int findPivot(int arr[], int start, int end)
{
	int data[3] = {arr[start], arr[(start+end)/2], arr[end]};
	
	for (int i = 0; i < 2; i++)
	{
		if (data[i] > data[i+1])
		{
			swap(data, i, i+1);
		}
	}

	if (data[1] == arr[start])
	{
		return start;
	}
	
	else if (data[1] == arr[(start+end)/2])
	{
		return (start+end)/2;
	}
			
	else if (data[1] == arr[end])
	{
		return end;
	}
	
	else
	{
		return -1;
	}
	
}


int partition(int arr[], int start, int end, int pivot)
{
	while (start <= end)
	{
		if (arr[start] >= arr[pivot] && arr[end] <= arr[pivot])
		{
			swap(arr, start, end);
		}
		
		if (arr[start] <= arr[pivot])
		{
			start++;
		}
		
		if (arr[end] > arr[pivot])
		{
			end--;
		}	
	}
	
	swap(arr, start, pivot);
	return start; 
}

void quickSort(int arr[], int start, int end)
{
	if ( start < end )
	{
		int pivot = findPivot(arr, start, end);
		//int pivot = (start+end)/2; 
		//cout << "Pivot determined as " << arr[pivot] << endl;
		swap(arr, pivot, end);
		//cout << "Moving pivot to the end: ";
		//printArray(arr, end+1, start);
		int rightStart = partition(arr, start, end-1, end);
		//cout << "After sort: ";
		//printArray(arr, end+1, start);
		quickSort(arr, start, rightStart-1);
		quickSort(arr, rightStart+1, end);
	}
}


void readFile()
{
	ifstream fin("test.txt");
	
	if (fin.fail())
	{
		cout << "Could not open text file" << endl;
	}
	
	else 
	{
		int n;
		fin >> n;
	
		for (int i = 0; i < n; i++)
		{
			int size;
			fin >> size;
			int data[2*size];

			for (int j = 0; j < 2*size; j++)
			{
				fin >> data[j]; 
			}
			
			cout << "Before sort: "; 
			printArray(data, 2*size-1);
			quickSort(data, 0, 2*size-1);
			cout << "After sort : ";
			printArray(data, 2*size-1);
			
		}
		
		fin.close();
	}
}



int main()
{
	readFile();
	return 0;
}
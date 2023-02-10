#include "QuickSort.h"

namespace SortLibrary
{
	// Name the object for debugging test results 
	QuickSort::QuickSort() : Sort("Quick Sort"){}

	template <class T> int QuickSort::findPivot(std::vector<T>& data, int start, int end)
	{
		int nums[3] = {data[start], data[(start+end)/2], data[end]};
		
		for (int i = 0; i < 2; i++)
		{
			if (nums[i] > nums[i+1])
			{
				int temp = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = temp; 
			}
		}

		if (nums[1] == data[start])
		{
			return start;
		}
		
		else if (nums[1] == data[(start+end)/2])
		{
			return (start+end)/2;
		}
				
		else if (nums[1] == data[end])
		{
			return end;
		}
		
		else
		{
			return -1;
		}
		
	}

	template <class T> int QuickSort::partition(std::vector<T> &data, int start, int end, int pivot, const bool desc)
	{		
		while (start <= end)
		{
			if (data[start] >= data[pivot] && data[end] <= data[pivot])
			{
				std::iter_swap(data.begin() + start, data.begin() + end);
			}
			
			if (data[start] <= data[pivot])
			{
				start++;
			}
			
			if (data[end] > data[pivot])
			{
				end--;
			}	
			
		}
		
		std::iter_swap(data.begin() + start, data.begin() + pivot);
		return start; 
	}
	
	template <class T> void QuickSort::quickSort(std::vector<T>& data, int start, int end, const bool desc)
	{
		if ( start < end )
		{
			int pivot = findPivot(data, start, end);
			std::iter_swap(data.begin() + pivot, data.begin() + end);
			int rightStart = partition(data, start, end-1, end, desc);
			quickSort(data, start, rightStart-1, desc);
			quickSort(data, rightStart+1, end, desc);
		}
	}

	template <class T> void QuickSort::sort(std::vector<T>& data, const bool desc)
	{
		quickSort(data, 0, data.size()-1, desc);
	}
}



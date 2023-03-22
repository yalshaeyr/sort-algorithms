#include "QuickSort.h"

namespace SortLibrary
{
	// Name the object for debugging test results 
	QuickSort::QuickSort() : Sort("Quick Sort"){}
	
	/*
	 * Picks the pivot and returns the index of the pivot 
	 * The pivot is the median of the first, middle and last element 
	 */
	template <class T> int QuickSort::findPivot(std::vector<T>& data, int start, int end)
	{
		// temp storage 
		std::vector<int> vals = {data[start], data[(start+end)/2], data[end]};
		std::vector<int> indices = {start, (start+end)/2, end};
		
		// Sort the first, middle and last element to find the middle
		for (int i = 0; i < 2; i++)
		{
			if (vals[i] > vals[i+1])
			{
				swap(vals, i, i+1);
				swap(indices, i, i+1);
			}
		}
		
		// return the index, not the actual value 
		// change to indices[0] or indices[2] to use first or last element instead 
		return indices[1]; 
	}
	
	/*
	 * Simply calls partition but wraps the functions with prints before/after
	 * Prints the unsorted/sorted partition 
	 */
	template <class T> int QuickSort::debugPartition(std::vector<T> &data, int start, int end, int pivot, const bool desc)
	{
		std::cout << "\n\tFor pivot = " << data[pivot] << ": " << std::endl;
		
		std::cout << "Full dataset before: ";
		displayData(data);
		
		std::cout << "Unsorted partition: ";
		displayData(data, start, pivot+1);
		
		int retVal = partition(data, start, end, pivot, desc);
				
		std::cout << "Sorted partition: ";
		displayData(data, start, pivot+1);
		
		std::cout << "Full dataset after: ";
		displayData(data);
		
		return retVal;
	}
	
	/*
	 * The workhorse of the sort 
	 * ensures all values left of the pivot are smaller and all values right are bigger
	 */
	template <class T> int QuickSort::partition(std::vector<T> &data, int start, int end, int pivot, const bool desc)
	{		

		while (start <= end)
		{
			if ((!desc && data[start] >= data[pivot] && data[end] <= data[pivot]) ||
				(desc && data[start] <= data[pivot] && data[end] >= data[pivot]))
			{
				std::iter_swap(data.begin() + start, data.begin() + end);
			}
			
			if ((!desc && data[start] <= data[pivot]) ||
				(desc && data[start] >= data[pivot]))
			{
				start++;
			}
			
			if ((!desc && data[end] > data[pivot]) ||
				(desc && data[end] < data[pivot]))
			{
				end--;
			}	
			
		}
		
		// swap the pivot back to its position 
		std::iter_swap(data.begin() + start, data.begin() + pivot);
		return start; 
	}
	
	/*
	 * A quick sort functions by picking a pivot, then ensuring elements on the left of the pivot
	 * are smaller than it, and elements on the right are larger. The dataset is then split into 
	 * two partitions: left and right, and the process is repeated. The process ends when the partitions 
	 * have a size of one.
	 */
	template <class T> void QuickSort::quickSort(std::vector<T>& data, int start, int end, const bool desc)
	{
		if ( start < end )
		{
			// pick the pivot 
			int pivot = findPivot(data, start, end);
			// move the pivot to the right hand side 
			std::iter_swap(data.begin() + pivot, data.begin() + end);
			// sort according to the pivot 
			int rightStart = partition(data, start, end-1, end, desc);
			// recursively call quickSort() on the left/right partitions 
			quickSort(data, start, rightStart-1, desc);
			quickSort(data, rightStart+1, end, desc);
		}
	}
	
	// The public function
	template <class T> void QuickSort::sort(std::vector<T>& data, const bool desc)
	{
		// call a quick sort on the entire data set
		quickSort(data, 0, data.size()-1, desc);
	}
}



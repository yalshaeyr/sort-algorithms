#include "BubbleSort.h"

namespace SortLibrary
{
	// Name the object for debugging test results 
	BubbleSort::BubbleSort() : Sort("Bubble Sort"){}
	
	// A simple bubble sort - O(n^2)
	template <class T> void BubbleSort::sort(std::vector<T>& data, bool desc)
	{
		// For each element 
		for (int i = 0; i < data.size(); i++)
		{
			// Compare it to remaining elements 
			for (int j = i+1; j < data.size(); j++)
			{
				// If it is larger, swap (reverse logic for descending sort)
				if (!desc && data[i] > data[j] || desc && data[i] < data[j])
				{
					std::iter_swap(data.begin() + i, data.begin() + j);
				}	
			}
		}
	}
}
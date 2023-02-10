#include "CountingSort.h"

#include <map>
#include <stdexcept>  

namespace SortLibrary
{
	// Name the object for debugging test results 
	CountingSort::CountingSort() : Sort("Counting Sort"){}
	
	// A counting sort - O(n)
	template <class T> void CountingSort::sort(std::vector<T>& data, const bool desc)
	{	
		// mapping of elem -> count 
		std::map<T, int> count; 
		
		// Create mapping 
		for (int i = 0; i < data.size(); i++)
		{
			try
			{
				count[data[i]]++;
			}
			
			catch (const std::out_of_range &oor) 
			{
				count[data[i]] = 1;
			}
		}
		
		// tracks current index 
		int i = desc ? data.size() - 1 : 0;
		
		// Recreate data using map 
		for (auto it = count.begin(); it != count.end(); it++)
		{
			for (int j = 0; j < it->second; j++)
			{
				data[i] = it->first;
				i += desc ? -1 : 1;
			}	
		}
	}
}
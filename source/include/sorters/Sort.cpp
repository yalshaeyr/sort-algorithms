#include "Sort.h"

#include <iostream>

namespace SortLibrary
{
	// Set display name 
	Sort::Sort(std::string s)
	{
		displayName = s;
	}
	
	// Retrieve display name 
	std::string Sort::getName()
	{
		return displayName;
	}
	
	// Swaps the position of two elements with indices a&b 
	template <class T> void Sort::swap(std::vector<T> &data, int a, int b)
	{
		T temp = data[a];
		data[a] = data[b];
		data[b] = temp; 
	}
	
	// Default function for unimplemented sorts 
	template <class T> void Sort::sort(std::vector<T> &data, bool desc)
	{
		std::cout << "This sort has not been implemented yet" << std::endl;
	}
	
	// Print data - used for debugging 
	template <class T> void Sort::displayData(std::vector<T> data, int start, int end)
	{	
		// if the end was not specified, default to the natural end of the vector
		end = end == -1 ? data.size() : end;
	
		for (int i = start; i < end; i++)
		{
			std::cout << data[i] << " ";
		}
		
		std::cout << std::endl;
	}
}
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
	
	// Default function for unimplemented sorts 
	template <class T> void Sort::sort(std::vector<T> &data, bool desc)
	{
		std::cout << "This sort has not been implemented yet" << std::endl;
	}
	
	// Print data - used for debugging 
	template <class T> void Sort::displayData(std::vector<T> data)
	{
		for (int i = 0; i < data.size(); i++)
		{
			std::cout << data[i] << " ";
		}
		
		std::cout << std::endl;
	}
}
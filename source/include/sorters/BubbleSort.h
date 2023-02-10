#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "Sort.h"

namespace SortLibrary
{
	// sort() function is a simple bubble sort 
	class BubbleSort: public Sort
	{
		public:
			BubbleSort();
			template <class T> static void sort(std::vector<T> &, const bool = false);
	};
}	

#endif /* BUBBLE_SORT_H */
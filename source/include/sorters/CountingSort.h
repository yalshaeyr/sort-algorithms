#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H

#include "Sort.h"

namespace SortLibrary
{
	// sort() function is a simple counting sort 
	class CountingSort: public Sort
	{
		public:
			CountingSort();
			template <class T> static void sort(std::vector<T> &, const bool = false);
	};
}
	
#endif /* COUNTING_SORT_H */
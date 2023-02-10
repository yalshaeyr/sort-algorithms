#ifndef QUICK_SORT_H
#define QUICK_SORT_H
	
#include "Sort.h"

namespace SortLibrary
{
	// sort() is a quick sort 
	class QuickSort: public Sort
	{
		private:
			template <class T> static int findPivot(std::vector<T> &, int, int);
			template <class T> static int partition(std::vector<T> &, int, int, int, const bool = false);
			template <class T> static void quickSort(std::vector<T> &, int, int, const bool = false);
		public: 
			QuickSort();
			template <class T> static void sort(std::vector<T> &, const bool = false);
			
	};	
}	


#endif /* QUICK_SORT_H */
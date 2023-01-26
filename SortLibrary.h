#ifndef SORT_LIBRARY_H
#define SORT_LIBRARY_H

#include <vector>

namespace SortLibrary 
{
	class Sort
	{
		public:
			static template <class T> void sort(std::vector<T>);
	}
	
	class BubbleSort extends Sort:
	{
		public:
			static template <class T> void sort(std::vector<T>]);
	}
}


#endif /* SORT_LIBRARY_H */
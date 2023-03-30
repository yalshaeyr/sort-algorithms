#ifndef SORT_H
#define SORT_H

#include <string>
#include <vector>

namespace SortLibrary 
{
	// Base sort class 
	class Sort
	{
		private:
			std::string displayName; 
		protected:
			template <class T> static void swap(std::vector<T> &, int, int);
		public:
			Sort(std::string);
			std::string getName();
			template <class T> std::vector<T> generateRandomData(int, const T);
			template <class T> static void displayData(std::vector<T>, int = 0, int = -1);
			// most important component - the static sort function
			template <class T> static void sort(std::vector<T> &, const bool = false);
			
	};
	
	/* Will move to separate files once implemented */
		
	class BucketSort: public Sort
	{
	};
	
	class HeapSort: public Sort 
	{
	};
	
	class InsertionSort: public Sort
	{
	};
	
	class MergeSort: public Sort 
	{
	};
	
	class RadixSort: public Sort
	{
	};
	
	class SelectionSort: public Sort 
	{
	};	
	
	class ShellSort: public Sort
	{
	};

	class TimSort: public Sort 
	{
	};
}


#endif /* SORT_H */
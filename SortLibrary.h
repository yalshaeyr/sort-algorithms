#ifndef SORT_LIBRARY_H
#define SORT_LIBRARY_H

#include <string>
#include <vector>
#include <unordered_map>

namespace SortLibrary 
{
	class Sort
	{
		private:
			std::string displayName; 
			template <class T> void displayData(std::vector<T>);
		public:
			Sort(std::string);
			std::string getName();
			template <class T> static void sort(std::vector<T> &, bool = false);
			
	};
	
	class SortTester
	{
		private:
			static const int NUM_TEST_CASES;
			typedef std::unordered_map<int, bool> testCaseMap;
			typedef std::unordered_map<int, testCaseMap> resultsMap;
			resultsMap results;
			template <class T> void reportResults(T);
			template <class T> void runTests(T);
		public:
			template <class T> void test(T);
	};
		
	class BucketSort: public Sort
	{
	};
	
	class BubbleSort: public Sort
	{
		public:
			BubbleSort();
			template <class T> static void sort(std::vector<T> &, bool = false);
	};
	
	class CountingSort: public Sort
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
		
	class QuickSort: public Sort
	{
	};	

}


#endif /* SORT_LIBRARY_H */
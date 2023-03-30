/* Will modify when project is near completion */
#include "include/sorters/Sort.cpp"
#include "include/sorters/BubbleSort.cpp"
#include "include/sorters/CountingSort.cpp"
#include "include/sorters/QuickSort.cpp"
#include "include/tools/SortTester.cpp"
#include "include/tools/SortReporter.cpp"

int main()
{
	// Sorters
	SortLibrary::QuickSort quick;
	
	// Test each sort 
/* 	SortLibrary::SortTester tester;
	
	tester.test(quick, true, false); */
	
	// Report efficiency
	SortLibrary::SortReporter reporter;
	reporter.report(quick, false);
	
	return 0;
}
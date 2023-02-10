/* Will modify when project is near completion */
#include "include/sorters/Sort.cpp"
#include "include/sorters/BubbleSort.cpp"
#include "include/sorters/CountingSort.cpp"
#include "include/sorters/QuickSort.cpp"
#include "include/tools/SortTester.cpp"

int main()
{
	// Sorters
	//SortLibrary::BubbleSort bubbler;
	//SortLibrary::CountingSort counter;
	SortLibrary::QuickSort quick;
	
	// Test each sort 
	SortLibrary::SortTester tester;
	
	//tester.test(bubbler, true);
	//tester.test(counter, true);
	tester.test(quick, true);
	
	return 0;
}
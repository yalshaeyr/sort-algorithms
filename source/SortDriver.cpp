/* Will modify when project is near completion */
#include "include/sorters/Sort.cpp"
#include "include/sorters/BubbleSort.cpp"
#include "include/sorters/CountingSort.cpp"
#include "include/tools/SortTester.cpp"

int main()
{
	// Sorters
	SortLibrary::BubbleSort bubbler;
	SortLibrary::CountingSort counter;
	
	// Test each sort 
	SortLibrary::SortTester tester;
	
	tester.test(bubbler, true);
	tester.test(counter, true);
	
	return 0;
}
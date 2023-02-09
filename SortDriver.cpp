#include "SortLibrary.cpp"
#include <tuple>

int main()
{
	// Sorters
	SortLibrary::BubbleSort bubbler;
	SortLibrary::CountingSort counter;
	
	// Test each sort 
	SortLibrary::SortTester tester;
	
	tester.test(bubbler);
	tester.test(counter);
	
	return 0;
}
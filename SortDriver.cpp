#include "SortLibrary.cpp"
#include <tuple>

int main()
{
	// Sorters
	SortLibrary::BubbleSort bubbler;
	
	// Test each sort 
	SortLibrary::SortTester tester;
	
	tester.test(bubbler);
	
	return 0;
}
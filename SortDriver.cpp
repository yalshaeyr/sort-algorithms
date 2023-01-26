#include "SortLibrary.cpp"

int main()
{
	SortLibrary::SortTester tester;
	SortLibrary::BubbleSort bubbler;
	
	tester.test(bubbler);
	
	return 0;
}
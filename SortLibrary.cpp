#include "SortLibrary.h"

#include <iostream>
#include <fstream>

namespace SortLibrary
{
	Sort::Sort(std::string s)
	{
		displayName = s;
	}
	
	std::string Sort::getName()
	{
		return displayName;
	}
	
	template <class T> void Sort::sort(std::vector<T> &data)
	{
		std::cout << "This sort has not been implemented yet" << std::endl;
	}
	
	template <class T> void Sort::displayData(std::vector<T> data)
	{
		for (int i = 0; i < data.size(); i++)
		{
			std::cout << data[i] << " ";
		}
		
		std::cout << std::endl;
	}
	
	const int SortTester::NUM_TEST_CASES = 1;
	
	template <class T> void SortTester::reportResults(T sorter)
	{
		for (resultsMap::iterator it = results.begin(); 
				it != results.end(); it++)
		{
			bool allPassed = true;
			
			for (testCaseMap::iterator innerIt = it->second.begin();
					innerIt != it->second.end(); innerIt++)
			{
				if (!innerIt->second)
				{
					std::cout << "For test_case_" << it->first << ": "
							  << "Case " << innerIt->first << " failed " 
							  << std::endl;
					allPassed = false; 
				}
			}
			
			if (allPassed)
			{
				std::cout << sorter.getName() << " passed all cases in test_case_" 
						  << it->first << "!" << std::endl;
			}
		}	
	}
	
	template <class T> void SortTester::runTests(T sorter)
	{
		for (int testCase = 1; testCase <= NUM_TEST_CASES; testCase++)
		{
			std::string testFileName = "Tests/test_case_" + std::to_string(testCase) + ".txt";
			std::string resultFileName = "Tests/test_case_" + std::to_string(testCase) + "_output.txt";
			std::ifstream test(testFileName);
			std::ifstream result(resultFileName);
			
			if (test.fail())
			{
				std::cout << "Could not open " << testFileName << std::endl;
			} 
			
			else if (result.fail())
			{
				std::cout << "Could not open " << resultFileName << std::endl;
			}
			
			else 
			{
				int n;
				test >> n;
	
				for (int i = 0; i < n; i++)
				{
					int size;
					test >> size;
					std::vector<int> data; 
					std::vector<int> desired;
					
					for (int j = 0; j < size; j++)
					{
						int testElem, desiredElem;
						test >> testElem; 
						result >> desiredElem; 
						data.push_back(testElem);
						desired.push_back(desiredElem);
					}
					
					sorter.sort(data);
					results[testCase][i+1] = data != desired ? false : true;
				}
				
				test.close();
				result.close();
			}
			
			
		}
	}
	
	template <class T> void SortTester::test(T sorter)
	{
		runTests(sorter);
		reportResults(sorter);
	}
	
	template <class T> void BubbleSort::sort(std::vector<T>& data)
	{
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = i+1; j < data.size(); j++)
			{
				if (data[i] > data[j])
				{
					std::iter_swap(data.begin() + i, data.begin() + j);
				}	
			}
		}
	}
	
	BubbleSort::BubbleSort() : Sort("Bubble Sort"){}
}
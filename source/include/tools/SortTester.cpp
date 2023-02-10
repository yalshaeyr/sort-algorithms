#include "SortTester.h"

#include <vector>
#include <iostream>
#include <fstream> 

namespace SortLibrary
{
	// the number of test cases
	const int SortTester::NUM_TEST_CASES = 1;
	// containing folder 
	const std::string SortTester::TEST_FOLDER = "tests/";
	// standard name for test set 
	const std::string SortTester::TEST_SET_NAME = "test_set_";
	// determines whether the output is descending 
	const std::string SortTester::DESC_PREFIX = "desc_";
	// determines whether the file is an output file 
	const std::string SortTester::OUTPUT_SUFFIX = "_output.txt";
	
	/*
	 * Report the results on each individual test case within a set 
	 * Based on whether the sort was descending 
	 * Separate from running tests 
	 */
	template <class T> void SortTester::reportResults(T sorter, const bool desc)
	{
		// Name of test set to print 
		std::string name = desc ? DESC_PREFIX : "";
		name += TEST_SET_NAME; 
		
		// Loop through each test set 
		for (resultsMap::iterator it = results.begin(); 
				it != results.end(); it++)
		{
			// Assume all test sets are passed 
			bool allPassed = true;
			
			// Loop through each case in the test set 
			for (testCaseMap::iterator innerIt = it->second.begin();
					innerIt != it->second.end(); innerIt++)
			{
				// If failed, report result. Otherwise, assume it was passed. 
				if (!innerIt->second)
				{
					std::cout << name << it->first
							  << ", case " << innerIt->first 
							  << ": " << sorter.getName() 
							  << " failed." << std::endl;
					allPassed = false; 
				}
			}
			
			// If all were passed, print a message. 
			if (allPassed)
			{
				std::cout << sorter.getName() << " passed all cases in "
						  << name << it->first << "!" << std::endl;
			}
		}	
	}
	
	/* 
	 * Compare the results of a sort to the pre-determined output 
	 */
	template <class T> void SortTester::runTests(T sorter, const bool desc)
	{
		
		// Loop through each test case 
		for (int testCase = 1; testCase <= NUM_TEST_CASES; testCase++)
		{
			// Set the test file and result file names 
			std::string testFileName = TEST_FOLDER + TEST_SET_NAME + std::to_string(testCase) + ".txt";
			std::string resultFileName = TEST_FOLDER;
			resultFileName += desc ? DESC_PREFIX : "";
			resultFileName += TEST_SET_NAME + std::to_string(testCase) + OUTPUT_SUFFIX; 
			// Open each file 
			std::ifstream test(testFileName); 
			std::ifstream result(resultFileName);
			
			// Do not proceed if they could not be opened 
			if (test.fail())
			{
				std::cout << "Could not open " << testFileName << std::endl;
			} 
			
			else if (result.fail())
			{
				std::cout << "Could not open " << resultFileName << std::endl;
			}
			
			// If successfully opened 
			else 
			{
				int n;
				test >> n;
				
				// Loop through the test case 
				for (int i = 0; i < n; i++)
				{
					int size;
					test >> size;
					std::vector<int> data; 
					std::vector<int> desired;
					
					// set the input and the desired (sorted) vector 
					for (int j = 0; j < size; j++)
					{
						int testElem, desiredElem;
						test >> testElem; 
						result >> desiredElem; 
						data.push_back(testElem);
						desired.push_back(desiredElem);
					}
					
					// Attempt to sort the data 
					sorter.sort(data, desc);
					// Check if properly sorted 
					results[testCase][i+1] = data != desired ? false : true;
				}
				
				// Close the opened files 
				test.close();
				result.close();
			}
			
			
		}
	}
	
	// Main function which tests and reports results - used for debugging 
	template <class T> void SortTester::test(T sorter, const bool desc)
	{
		runTests(sorter, desc);
		reportResults(sorter, desc);
	}
}
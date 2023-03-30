#ifndef SORT_TESTER_H
#define SORT_TESTER_H

#include <string>
#include <vector>
#include <unordered_map>

namespace SortLibrary
{
	class SortTester
	{
		private:	
			// based on local test files 		
			static const int NUM_TEST_CASES;
			static const std::string TEST_FOLDER;
			static const std::string TEST_SET_NAME;
			static const std::string DESC_PREFIX;
			static const std::string OUTPUT_SUFFIX;
			// baseline comparator for automatic tests 
			static const SortLibrary::CountingSort BASELINE;
			// define maps of test_set_X -> pass/fail 
			typedef std::unordered_map<int, bool> testCaseMap;
			// define maps of test_case_X -> test_set_X 
			typedef std::unordered_map<int, testCaseMap> resultsMap;
			resultsMap results;
			// Helper functions to test sorts 
			template <class T> void checkResults(T, const bool = false);
			template <class T> void runManualTests(T, const bool = false);
			template <class T> void runAutomaticTests(T, const bool = false);
			template <class T> void runTests(T, const bool, const bool = false);
		public:
			// Test a sorting class (i.e. the sort function)
			template <class T> void test(T, const bool = true, const bool = false);
	};
}


#endif /* SORT_TESTER_H */
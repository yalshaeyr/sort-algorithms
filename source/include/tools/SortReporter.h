#ifndef SORT_REPORTER_H
#define SORT_REPORTER_H

#include <string>
#include <map> 

namespace SortLibrary
{
	class SortReporter
	{
		private:
			std::string DIRECTORY = "results/";
			std::string FILE_NAME = "sort_results";
			std::string INVOKE_PYTHON = "python scripts/visualiseSorts.py";
			std::string getCurrentDateTime();
			template <class F> float timer(F, std::vector<int>&, const bool = false);
			template <class T> std::map<int, float> runSort(T, const bool = false);
			void exportResults(std::map<int, float>, std::string);
			void visualise();
		public:
			template <class T> void report(T, const bool = false);
	};
}


#endif /* SORT_REPORTER_H */
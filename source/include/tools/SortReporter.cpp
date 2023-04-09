#include "SortReporter.h"

#include <ctime>
#include <chrono>
#include <sstream>
#include <fstream>
#include <iostream> 
#include <iomanip>


namespace SortLibrary
{
	/*
	 * Convert the current time into a date-time format that 
	 * is human readable 
	 */
	std::string getCurrentDateTimeInFormat() 
	{
		std::time_t currentTime = std::time(nullptr);
		std::tm* localTime = std::localtime(&currentTime);

		std::stringstream ss;
		ss << std::setfill('0') << std::setw(2) << localTime->tm_mday << "-"
		   << std::setfill('0') << std::setw(2) << (localTime->tm_mon + 1) << "-"
		   << std::setfill('0') << std::setw(2) << (localTime->tm_year % 100) << " "
		   << std::setfill('0') << std::setw(2) << localTime->tm_hour << "h"
		   << std::setfill('0') << std::setw(2) << localTime->tm_min << "m"
		   << std::setfill('0') << std::setw(2) << localTime->tm_sec << "s";

		return ss.str();
	}
	
	/*
	 * A timer wrapper
	 * Simply records and returns the real time taken to run func() 
	 */
	template <class F> float SortReporter::timer(F func, std::vector<int>& data, const bool desc)
	{
		auto start = std::chrono::high_resolution_clock::now();
		func(data, desc);
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
		return static_cast<float>(duration.count()) / 1000000.0f;
	}
	
	
	
	/*
	 * Runs the given sort for random datasets of gradually-increasing size n
	 */
	template <class T> std::map<int, float> SortReporter::runSort(T sorter, const bool desc)
	{
		// initialise the results 
		std::map<int, float> results; 
		
		const int LARGEST_SIZE = 1000; // n, size of dataset 
		const int MAX_VAL = 1000; // largest element in dataset 
		
		// set seed 
		srand(time(NULL));
		
		for (int n = 1; n <= LARGEST_SIZE; n++)
		{
			// generate a random vector 
			std::vector<int> randomData = sorter.generateRandomData(n, MAX_VAL);
			// sort the data with the sorter being tested 
			results[n] = timer([&sorter](std::vector<int>& data, const bool desc) { sorter.sort(data, desc); }, randomData, desc);
		}
		
		return results; 
	}
	
	
	/*
	 * Export the results to a file for later use 
	 */
	void SortReporter::exportResults(std::map<int, float> results, std::string name)
	{
		// The name of the file 
		std::string fileName = DIRECTORY + name + " " + FILE_NAME + " " +
							   getCurrentDateTimeInFormat() + ".csv";
		// Open the file 
		std::ofstream outputFile(fileName);

		// If unable to open, do not proceed 
		if (outputFile.fail()) 
		{
			std::cerr << "Unable to open file: " << fileName << std::endl;
		}
		
		else 
		{
			// Write header
			outputFile << "n,time" << std::endl;

			// Write map content
			for (const auto& entry : results) {
				outputFile << entry.first << "," << entry.second << std::endl;
			}

			// Close the file and inform the user 
			outputFile.close();
			std::cout << "Data successfully exported to: " << fileName << std::endl;
		}


	}
	
	/*
	 * Invokes a Python script to visualise the sort 
	 */
	void SortReporter::visualise()
	{
		if ( std::system(INVOKE_PYTHON.c_str()) != 0 )
		{
			std::cerr << "Failed to invoke Python script" << std::endl;
			return; 
		}
	}
	
	/*
	 * Collects, stores and visualises performance data of the given sort 
	 */
	template <class T> void SortReporter::report(T sorter, const bool desc)
	{
		// Run the sort and export the results 
		exportResults(runSort(sorter, desc), sorter.getName());
		// visualise in Python 
		visualise();
	}
	
	
}
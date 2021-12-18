/*
  Name: Wei Da Chen
  Date: 11/22/2021
	File: test_sorting_algorithms.cc
*/

/*
This assignment compares the various sorting algorithms in addition to experimenting
with algorithmic variations. The algorithms will be modified in order for a
Comparator class to be used for comparisons.
	- VerifyOrder function verifies that a collection is in sorted order.
	- GenerateRandomVector function generates a random vector of a specific size and
		returns it
	- GenerateSortedVector function generates a random sorted vector of a specific size,
		generates a vector of increasing or decreasing values based on bool smaller_to_larger,
		and returns it.
*/

#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include "Sort.h"
using namespace std;

// Computes duration given a start time and a stop time in nano seconds.
// Keep it in.
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Test function that shows how you can time a piece of code.
// Just times a simple loop. Remove for final submission.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin_time = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i)
    sum++;
  // End of piece of code to time.
  const auto end_time = chrono::high_resolution_clock::now();
  cout << ComputeDuration(begin_time, end_time) << "ns" << endl;
}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
  // Add code
	vector<int> randomVector;
	srand(time(0)); // seeds rand with a new starting value each time

	for (unsigned int i = 0; i < size_of_vector; i++) {
		randomVector.push_back(rand());
	}

	return randomVector;
}

// Generates and returns sorted vector of size @size_of_vector.
// If @smaller_to_larger is true, returns vector sorted from small to large.
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  vector<int> sorted_vector;
  if (smaller_to_larger) {
    for (unsigned i = 0; i < size_of_vector; i++) {
      sorted_vector.push_back(i);
    }
  }
  else {
    for (unsigned i = size_of_vector; i > 0; i--) {
      sorted_vector.push_back(i);
    }
  }
  
  return sorted_vector;
}

// Verifies that a vector is sorted given a comparator.
// I.e. it applies less_than() for consecutive pair of elements and returns true
// iff less_than() is true for all pairs.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  for (unsigned i = 1; i < input.size(); i++) {
    if (input[i] != input[i - 1] && less_than(input[i], input[i - 1]))
      return false;
  }
  return true;
}

// Wrapper function to test different sorting algorithms. See homework's PDF for details.
void testSortingWrapper(int argc, char **argv) {
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small") {
    cout << "Invalid input type" << endl;
    return;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return;
  }

  // This block of code to be removed for your final submission.
  // TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;
	vector<int> heap_sortVector;
	vector<int> merge_sortVector;
	vector<int> quick_sortVector;
	vector<int> quick_sortVector2;
	vector<int> quick_sortVector3;

  if (input_type == "random") {
    // Generate random vector @input_vector.
		heap_sortVector = GenerateRandomVector(input_size);
		merge_sortVector = GenerateRandomVector(input_size);
		quick_sortVector = GenerateRandomVector(input_size);
		quick_sortVector2 = GenerateRandomVector(input_size);
		quick_sortVector3 = GenerateRandomVector(input_size);
  }
  else {
    // Generate sorted vector @input_vector.
		bool smaller_to_larger = (input_type == "sorted_small_to_large" ? true : false);
    heap_sortVector = GenerateSortedVector(input_size, smaller_to_larger);
    merge_sortVector = GenerateSortedVector(input_size, smaller_to_larger);
    quick_sortVector = GenerateSortedVector(input_size, smaller_to_larger);
    quick_sortVector2 = GenerateSortedVector(input_size, smaller_to_larger);
    quick_sortVector3 = GenerateSortedVector(input_size, smaller_to_larger);
  }

  if (comparison_type == "less") {
    const auto beginTime = chrono::high_resolution_clock::now();
    HeapSort(input_vector, less<int>{});
    const auto endTime = chrono::high_resolution_clock::now();
    cout << "Heapsort" << endl << "Runtime: " << ComputeDuration(beginTime, endTime) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << "\n";

    const auto beginTime1 = chrono::high_resolution_clock::now();
    MergeSort(input_vector, less<int>{});
    const auto endTime1 = chrono::high_resolution_clock::now();
    cout << endl;
    cout << "MergeSort" << endl << "Runtime: " << ComputeDuration(beginTime1, endTime1) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << "\n\n";

    const auto beginTime2 = chrono::high_resolution_clock::now();
    QuickSort(input_vector, less<int>{});
    const auto endTime2 = chrono::high_resolution_clock::now();
    cout << "QuickSort" << endl << "Runtime: " << ComputeDuration(beginTime2, endTime2) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << "\n";

    cout << "\nTesting Quicksort Pivot Implementations" << endl;
    cout << endl;

    const auto beginTime3 = chrono::high_resolution_clock::now();
    const auto endTime3 = chrono::high_resolution_clock::now();
    cout << "Median of Three" << endl << "Runtime: " << ComputeDuration(beginTime3, endTime3) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << "\n\n";

    const auto beginTime4 = chrono::high_resolution_clock::now();
    QuickSort2(input_vector, less<int>{});
    const auto endTime4 = chrono::high_resolution_clock::now();
    cout << "Middle" << endl << "Runtime: " << ComputeDuration(beginTime4, endTime4) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << "\n\n";

    const auto beginTime5 = chrono::high_resolution_clock::now();
    QuickSort3(input_vector, less<int>{});
    const auto endTime5 = chrono::high_resolution_clock::now();
    cout << "First" << endl << "Runtime: " << ComputeDuration(beginTime5, endTime5) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << "\n";
  }
  else if (comparison_type == "greater") {
    const auto beginTime = chrono::high_resolution_clock::now();
    HeapSort(input_vector, greater<int>{});
    const auto endTime = chrono::high_resolution_clock::now();
    cout << "Heapsort" << endl << "Runtime: " << ComputeDuration(beginTime, endTime) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << "\n";

    const auto beginTime1 = chrono::high_resolution_clock::now();
    MergeSort(input_vector, greater<int>{});
    const auto endTime1 = chrono::high_resolution_clock::now();
    cout << endl;
    cout << "MergeSort" << "Runtime: " << ComputeDuration(beginTime1, endTime1) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << "\n";

    const auto beginTime2 = chrono::high_resolution_clock::now();
    QuickSort(input_vector, greater<int>{});
    const auto endTime2 = chrono::high_resolution_clock::now();
    cout << endl;
    cout << "QuickSort" << endl << "Runtime: " << ComputeDuration(beginTime2, endTime2) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << "\n";

    cout << "\nTesting Quicksort Pivot Implementations" << endl;

    cout << endl;

    const auto beginTime3 = chrono::high_resolution_clock::now();
    const auto endTime3 = chrono::high_resolution_clock::now();
    cout << "Median of Three" << endl << "Runtime: " << ComputeDuration(beginTime3, endTime3) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << "\n\n";

    const auto beginTime4 = chrono::high_resolution_clock::now();
    QuickSort2(input_vector, greater<int>{});
    const auto endTime4 = chrono::high_resolution_clock::now();
    cout << "Middle" << endl << "Runtime: " << ComputeDuration(beginTime4, endTime4) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << "\n\n";

    const auto beginTime5 = chrono::high_resolution_clock::now();
    QuickSort3(input_vector, greater<int>{});
    const auto endTime5 = chrono::high_resolution_clock::now();
    cout << "First" << endl << "Runtime: " << ComputeDuration(beginTime5, endTime5) << " ns\n";
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << "\n";
  }
}

int main(int argc, char **argv) {
  // DO NOT CHANGE or ADD ANY CODE in this function.
  if (argc != 4)
  {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }

  testSortingWrapper(argc, argv);

  return 0;
}

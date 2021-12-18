// Homework 4
// Testing Sorting Algorithms
// YOUR NAME

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

// Computes duration given a start time and a stop time in nano seconds.
// Keep it in.
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, 
			  chrono::high_resolution_clock::time_point end_time) {
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Test function that shows how you can time a piece of code.
// Just times a simple loop. Remove for final submission.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin_time = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end_time = chrono::high_resolution_clock::now();    
  cout << ComputeDuration(begin_time, end_time) << "ns" << endl;

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  // Use rand() to generate random integer
  // Add code
}

// Generates and returns sorted vector of size @size_of_vector.
// If @smaller_to_larger is true, returns vector sorted from small to large.
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
  // Add code
}

// Verifies that a vector is sorted given a comparator.
// I.e. it applies less_than() for consecutive pair of elements and returns true
// iff less_than() is true for all pairs.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {
  // Add code
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
  TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    // Generate random vector @input_vector.
    
  } else {
    // Generate sorted vector @input_vector.

  }

  // Call HeapSort / MergeSort / QuickSort  using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // MergeSort(input_vector, less<int>{})
  // otherwise call
  // MergeSort(input_vector, greater<int>{})
  // ...
  // ^^SAME for HeapSort & QuickSort

  // Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // QuickSort(input_vector, less<int>{})
  // otherwise call
  // QuickSort(input_vector, greater<int>{})
  // ...
  // ^^SAME for QuickSort2 & QuickSort3

}

int main(int argc, char **argv) {
  // DO NOT CHANGE or ADD ANY CODE in this function.
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  
  testSortingWrapper(argc, argv);

  return 0;
}

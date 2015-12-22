//*********************************************************************
// Cameron Pattisall
// CS 3610 Project 5
// November 17, 2015
// main.cpp main file
//*********************************************************************

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstddef>
#include "sort.h"

using namespace std;

void usage() {
  cout << "Usage: project5 [option]" << endl;
  cout << endl;
  cout << "  Options: " << endl;
  cout << "    -s  performs shell sort on input array then displays results"     << endl;
  cout << "    -i  performs insertion sort on input array then displays results" << endl;
  cout << "    -l  performs quick sort on input array, using the last element"   << endl;
  cout << "          as the pivot, then displays result"                         << endl;
  cout << "    -m  performs quick sort on input array, using the median of"      << endl;
  cout << "          the first, middle and last elements as the pivot, then"     << endl; 
  cout << "          displays results"                                           << endl;
}

int main(int argc, char** argv) {

  //*****************************************************************
  // Declarations for part1 and part2
  //*****************************************************************
  //usage();
  int n; // size of area
  int tmp; // tmp value used for input

  //*****************************************************************
  // PART1: Fill array with redirected input
  // (Gets commented out during part2)
  //*****************************************************************
  cin >> n;
  vector<int> arr; // declare empty array of size n
  // Fill the array with input 
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    arr.push_back(tmp);
  }

  //-**********************************************************
  // Detects command line options for different sorts
  // Part 1
  //-**********************************************************
  if(argc == 2) {
    if(std::string(argv[1]) == "-s") {
      // use shell_sort
      shell_sort(arr);
    }
    else if(std::string(argv[1]) == "-i") {
      // use insertion_sort
      insertion_sort(arr);
    }
    else if(std::string(argv[1]) == "-l") {
      // quick_sort using last as pivot
      quick_sort(arr,"l");
    }
    else if(std::string(argv[1]) == "-m") {
      // quick_sort using middle as pivot
      quick_sort(arr,"m");
    }
  }
  else { // default: quick_sort with first as pivot
    quick_sort(arr,"f");
  }

  // END OF PART 1

//-**********************************************************
  // !!! KEEP COMMENTED OUT FOR TESTING !!!
  // PART2: Code used to generate data on large sized n
  //        for comparison analysis of each sorting algorithm
  // (PART1 Gets commented out to run this code and vice versa)
  // Print() function in sort.cpp has loop commented out to 
  // only output the number of comparisons
//-**********************************************************
/*
for(n = 1000; n <= 10000; n += 3000) {
  vector<int> arr; // declare empty array of size n
  for(int i = 0; i < n; i++) {
    tmp = rand() % 1000000 + 1; // generate random number from 1-1000000
    arr.push_back(tmp);
  }

  //-**********************************************************
  // Detects command line options for different sorts
  // Part 2
  //-**********************************************************
  if(argc == 2) {
    if(std::string(argv[1]) == "-s") {
      // use shell_sort
      shell_sort(arr);
    }
    else if(std::string(argv[1]) == "-i") {
      // use insertion_sort
      insertion_sort(arr);
    }
    else if(std::string(argv[1]) == "-l") {
      // quick_sort using last as pivot
      quick_sort(arr,"l");
    }
    else if(std::string(argv[1]) == "-m") {
      // quick_sort using middle as pivot
      quick_sort(arr,"m");
    }
  }
  else { // default: quick_sort with first as pivot
    quick_sort(arr,"f");
  }
}
// !!! END OF PART 2 !!!
*/
  return EXIT_SUCCESS;
}   // END OF MAIN

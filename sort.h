//*********************************************************************
// Cameron Pattisall
// CS 3610 Project 5
// November 17, 2015
// sort.h header file
//*********************************************************************

#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//*********************************************************************
// shell_sort and associated functions
//*********************************************************************
void shell_sort(vector<int> arr);
void interval_sort(vector<int>& arr, int& c, int begin, int inc);

//*********************************************************************
// insertion_sort and associated functions
//*********************************************************************
void insertion_sort(vector<int> arr);

//*********************************************************************
// quick_sort and associated functions
//*********************************************************************
void quick_sort(vector<int> arr, string choice);
// recursive helper functions called depending on users choice
void quick_last(vector<int>& arr, int& c, int first, int last);
void quick_middle(vector<int>& arr, int& c, int first, int last);
void quick_first(vector<int>& arr, int& c, int first, int last);
// partition helper function used to partition list in quicksort
int partition(vector<int>& arr, int& c, int first, int last, int split);

// function to print sorted array and comparison count
void print(vector<int> arr, int c);

#endif

//*********************************************************************
// Cameron Pattisall
// CS 3610 Project 5
// November 17, 2015
// sort.cpp implementation file
//*********************************************************************

#include "sort.h"

void shell_sort(vector<int> arr) {
	int c = 0; // counter for comparisons
	int inc;

	// get upper value for increment
	for(inc = 1; (unsigned)inc < (arr.size() - 1) / 9; inc = 3 * inc + 1);

	// go through sublists until it reaches bottom inc
	do {
		for(int begin = 0; begin < inc; begin++) {
			interval_sort(arr, c, begin, inc);
		}
		inc = inc / 3;
	} while(inc > 0);

	print(arr,c);
}

void interval_sort(vector<int>& arr, int& c, int begin, int inc) {
	int first; // first out of order
	int location;
	int tmp;

	for(first = begin; (unsigned)first < arr.size(); first += inc) {
		c++; // increment comparisons
		if(arr[first] < arr[first-inc]) {
			tmp = arr[first];
			location = first;
			do {
				c++; // increment comparisons
				arr[location] = arr[location-inc];
				location -= inc;
			} while(location > 0 && arr[location-inc] > tmp);
			arr[location] = tmp;
		}
	}
}

void insertion_sort(vector<int> arr) {
	int c = 0; // counter for comparisons
	int first; // first out of order
	int location; 
	int tmp;

	for(first = 1; (unsigned)first < arr.size(); first++) {
		c++; // increment comparisons
		if(arr[first] < arr[first-1]) {
			tmp = arr[first];
			location = first;
			do {
				c++; // increment comparisons
				arr[location] = arr[location-1];
				location--;
			} while(location > 0 && arr[location-1] > tmp);
			arr[location] = tmp;
		}
	}
	print(arr,c); // print sorted array and comparisons
}

void quick_sort(vector<int> arr, string choice) {
	int c = 0; // counter for comparisons
	if(choice == "l") { // use last pivot recursive function
		quick_last(arr,c,0,arr.size()-1);
	}
	else if(choice == "m") { // use middle pivot recursive function
		quick_middle(arr,c,0,arr.size()-1);
	}
	else {
		quick_first(arr,c,0,arr.size()-1);
	}
	print(arr,c); // print sorted array and number of comparisons
}

void quick_last(vector<int>& arr, int& c, int first, int last) {
	int pivot_index;
	if(first < last) {
		int split = last; // last element
		pivot_index = partition(arr,c,first,last,split);
		quick_middle(arr,c,first,pivot_index-1); // recurse down
		quick_middle(arr,c,pivot_index+1,last); // recurse up
	}
}

void quick_middle(vector<int>& arr, int& c, int first, int last) {
	int pivot_index;
	if(first < last) {
		int split = (first + last) / 2; // middle element
		pivot_index = partition(arr,c,first,last,split);
		quick_middle(arr,c,first,pivot_index-1); // recurse down
		quick_middle(arr,c,pivot_index+1,last); // recurse up
	}
}

void quick_first(vector<int>& arr, int& c, int first, int last) {
	int pivot_index;
	if(first < last) {
		int split = first; // first element
		pivot_index = partition(arr,c,first,last,split);
		quick_first(arr,c,first,pivot_index-1); // recurse down
		quick_first(arr,c,pivot_index+1,last); // recurse up
	}
}

int partition(vector<int>& arr, int& c, int first, int last, int split) {
	int pivot = arr[split]; // determines value of pivot element
	int current; // index of current location
	int small_index = first; // initialize small_index to keep track of swaps

	swap(arr[first],arr[split]); // swap first element with pivot element

	for(current = first + 1; current <= last; current++) {
		c++; // increment number of comparisons
		if(arr[current] < pivot) {
			small_index++; // increment small_index
			swap(arr[small_index],arr[current]); // swap small_index element and current element
		}
	}

	// swap first element with element denoted by small_index
	swap(arr[first],arr[small_index]);
	return small_index;
}

// print the sorted array and comparison count
void print(vector<int> arr, int c) {
	for(int i = 0; (unsigned)i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << c << endl;
}
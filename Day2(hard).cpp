// This problem was asked by Uber.

// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original
// array except the one at i.

// For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], 
// the expected output would be[2, 3, 6].

// Follow - up: what if you can't use division?

#include <iostream>

int main() {

	int arr[] = { 1, 2, 3, 4, 5 };

	int res[(sizeof(arr)/sizeof(*arr))];

	int temp = 1;

	for (int i = 0; i < (sizeof(arr) / sizeof(*arr)); i++) {
		temp = 1;
		for (int element : arr) {
			if (element != arr[i]) {
				temp *= element;
			}
		}
		res[i] = temp;

		std::cout << temp << " ";

	}
	return 0;
}

// The only division I needed was to get the size of the array but 
// I could simply get the size without any divisions by using a for loop with the : operator I don't know if that counts anyways so yes that's it

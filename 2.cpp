// This problem was asked by Uber.

// Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

// For example, if our input was[1, 2, 3, 4, 5], the expected output would be[120, 60, 40, 30, 24].If our input was[3, 2, 1], the expected output would be[2, 3, 6].

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

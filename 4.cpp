// This problem was asked by Stripe.

// Given an array of integers, find the first missing positive integer in linear timeand constant space.
// In other words, find the lowest positive integer that does not exist in the array.The array can contain duplicatesand negative numbers as well.

// For example, the input[3, 4, -1, 1] should give 2. The input[1, 2, 0] should give 3.

// You can modify the input array in - place.

#include <iostream>
#include <vector>

int findlowestpositiveint(std::vector<int> vec) {

	int re = 1;

	for (int integer : vec) {
		if (integer == re && integer > 0) {
			re++;
		}
	}

	return re;
}

int main() {
	std::vector<int> vec = { 3, 4, -1, 1 };
	

	std::cout << findlowestpositiveint(vec);

	return 0;
}

// this took me way longer that it should have... I hope it's okay that I used vector instead 
// of an array but it would've been that much of a difference anyways I just wanted it because 
// vector has variable amount of items.

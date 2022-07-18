// This problem was recently asked by Google.

// Given a list of numbersand a number k, return whether any two numbers from the list add up to k.

// For example, given[10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

// Bonus: Can you do this in one pass ?

#include <iostream>;

int numbers [] = {10, 15, 3, 7};

int k = 17;

bool res = false;

int main() {
	for (int i : numbers) {
		for (int i2 : numbers) {
			if (i + i2 == k) {
				res = true;
			}
		}
	}
	std::cout << res;
}

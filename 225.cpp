#include <iostream>
#include <vector>

// This problem was asked by Bloomberg.

// There are N prisoners standing in a circle, waiting to be executed.The executions are carried out starting with the kth person, and removing every 
// successive kth person going clockwise until there is no one left.

// Given N and k, write an algorithm to determine where a prisoner should stand in order to be the last survivor.

// For example, if N = 5 and k = 2, the order of executions would be[2, 4, 1, 5, 3], so you should return 3.

// Bonus: Find an O(log N) solution if k = 2

int last_exec(int N, int k) {
	int last_exec = NULL;
	int next_exec_index = NULL;
	int buff;

	std::vector<int> prisoners;			// I don't know why but I decided to use vector

	for (int i = 1; i < N+1; i++) {
		prisoners.push_back(i);			// just a push of an iteration like this {1, 2, 3, 4, 5}
	}

	while (!prisoners.empty()) {
		next_exec_index = (next_exec_index + k - 1) % prisoners.size();	// (0 + 2(k) - 1) = 1 so 1 % 5 = 1
										// it's more obvious on the second or third iteration : (1 + 2(k) - 1) % 4 = 2
		last_exec = prisoners[next_exec_index];							// our return value
		prisoners.erase(prisoners.begin() + next_exec_index);			// erase a specific element from list
	}

	return last_exec;

}

int main() {

	int N = 5;		// prisoners
	int k = 2;		// our pattern (every k(th) person is executed)

	std::cout << last_exec(N, k);
	return 0;
}

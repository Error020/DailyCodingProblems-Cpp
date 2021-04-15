#include <iostream>
#include <string>
#include <vector>

// This problem was asked by Google.

// Implement a PrefixMapSum class with the following methods :

// insert(key : str, value : int) : Set a given key's value in the map. If the key already exists, overwrite the value.
// sum(prefix : str) : Return the sum of all values of keys that begin with a given prefix.

// For example, you should be able to run the following code :

// mapsum.insert("columnar", 3)
// assert mapsum.sum("col") == 3

// mapsum.insert("column", 2)
// assert mapsum.sum("col") == 5

class PrefixMapSum {
	
public:
	 class Key {	// the class for the Keys
	 public:
		std::string key;	// the string in the Key
		int value;			// the value of the Key

		Key(std::string key, int value) : key(key), value(value) {}		// constructor
	};

	std::vector<Key> vector;	// idk vector is working properly so why not? and it's comfortable because of it's methods like push_back or at in this case


	void insert(std::string key, int value) {
		vector.push_back(Key(key, value));		// push_back appends an element to the vector
	}

	int sum(std::string prefix) {
		int re = 0;			// it'll be the returned integer
		for (int i = 0; i < vector.size(); i++) {		// size returns the size of the vector
			if (vector.at(i).key.rfind(prefix, 0) == 0) {	// at returns the i'nd Element in the vector and 
														// rfind(key, 0) returns if it finds the key in the string starting at the 0'th letter 
				re += vector.at(i).value;
			}
		}
		return re;
	}
};

int main() {

	PrefixMapSum mapsum;

	mapsum.insert("columnar", 3);
	std::cout << mapsum.sum("col") << ::std::endl;
	mapsum.insert("column", 2);
	std::cout << mapsum.sum("col") << ::std::endl;

	return 0;
}

#include <iostream>
#include <string>

// This problem was asked by IBM.

// Given a string with repeated characters, rearrange the string so that no two adjacent characters are the same. If this is not possible, return None.

// For example, given "aaabbc", you could return "ababac".Given "aaab", return None

class reReturn {		
public:
	std::string str;
	int tries = 0;
	reReturn(std::string str, int tries) : str(str), tries(tries)	{}
};

reReturn reArrange(std::string str) {

	int i, j;	// iterators
	char cbuf;	// a character buffer for the reArrangement
	bool solved = false;	// boolean to check if the problem is solved
	bool possible = true;	// boolean is it possible 
	int tries = 0;		// how many tries did it take the program to solve it 
	int checksum = 0;	// how many rearrangements took place per iteration
	int newstart = 0;	// where the for loops to iterate the string should start after a successful rearrangement

	while (solved == false) {		// MY SOLUTION IS A BIT LIKE BRUTEFORCING TO SOLVE
		checksum = 0;
		newstart = 0;

		std::cout << "rearranging" << ::std::endl;
		for (i = newstart; i < str.length(); i++) {
			if (str[i] == str[i + 1]) {
				for (j = newstart; j < str.length(); j++) {
					if (str[i] != str[j]) {
						cbuf = str[i + 1];
						str[i + 1] = str[j];
						str[j] = cbuf;		// two characters were swapped
						newstart = i;
						checksum++;
						break;
					}
				}
			}
		}

		std::cout << "checking" << ::std::endl;

		if (checksum == 0) {		// if checksum is 0 the was no rearrangement this loop
			solved = true;
		}
		else {
			tries++;				// if there was a rearrangement this loop 
			if (tries == (str.length()*2)) {
				possible = false;
				solved = true;
			}
		}
		std::cout << str << ::std::endl;

	}
	if (possible == true) {
		return reReturn(str, tries);
	}
	else {
		return reReturn("none", tries);
	}
}

int main() {
	std::string str; // "aaabbc"

	std::cout << "Give me a String :  ";
	std::cin >> str;	// get the string through console input

	reReturn re = reArrange(str);	// create Object with reArrange's return value as Elements

	std::cout << ::std::endl << re.str << ::std::endl << "\t es wurde so oft versucht : " << re.tries << ::std::endl;	// console output

	return 0;
}
// You come across a dictionary of sorted words in a language you've never seen before.
// Write a program that returns the correct order of letters in this language.
// For example, given['xww', 'wxyz', 'wxyw', 'ywx', 'ywz'], you should return
// ['x', 'z', 'w', 'y'].

#include <iostream>
#include <vector>

std::string words[] = {"xww", "wxyz", "wxyw", "ywx", "ywz"};

std::vector<char> characters;

int main() {
	for (std::string word : words) {
		for (char c : word) {
			if (characters.empty() != 1) {
				bool found = false;
				for (char character : characters) {
					if (character == c) {
						found = true;
					}
				}
				if (found == false) {
					characters.push_back(c);
				}
			}
			else {
				characters.push_back(c);
			}
		}
	}
	for (char c : characters) {
		std::cout << c;
	}
}

// I think I got it wrong but that's not how daily coding problems would write it either. 
// I'll see when I get back to #226 with my new email address.

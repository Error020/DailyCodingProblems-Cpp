// This problem was asked by Jane Street.

// cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the firstand last element of that pair. 
// For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

// Given this implementation of cons :

// def cons(a, b) :
//     def pair(f) :
//     return f(a, b)
//     return pair

//     Implement car and cdr.


#include <iostream>

class cons {
public:
	int a;
	int b;

	cons(int a, int b) : a(a), b(b) {}

};

int car(cons obj) {
	int re;
	re = obj.a;
	return re;
}

int cdr(cons obj) {
	int re;
	re = obj.b;
	return re;
}

int main() {

	std::cout << car(cons(3, 4));
	std::cout << cdr(cons(3, 4));

	return 0;
}

// medium??? I guess it would be if I wasn't used to a language like c++

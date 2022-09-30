/* 
   This problem was asked by Jane Street.
   cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the firstand last
   element of that pair.For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
   Given this implementation of cons :
    def cons(a, b) :
        def pair(f) :
            return f(a, b)
        return pair
   Implement car and cdr.
*/

#include <iostream>

struct Pair {
    int a, b;
};

Pair cons(int i, int j) {
    Pair p;
    p.a = i;
    p.b = j;
    return p;
}

int car(Pair p) {
    return p.a;
}

int cdr(Pair p) {
    return p.b;
}

int main() {
    std::cout << car(cons(3, 4)) << std::endl;
    std::cout << cdr(cons(3, 4)) << std::endl;

    return 0;
}

// this is my second approach... I think I might give this another shot, I understand that I need lambda

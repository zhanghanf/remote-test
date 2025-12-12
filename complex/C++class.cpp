#include<iostream>
#include"complex.h"



using namespace std;

printX() {};
template<typename T,typename...types>
void printX(T& firstArg, types&...args) {
	cout << firstArg << endl;
	printX(args...);
}
int main() {
	complex c1(1, 2), c2(2, 3);
	print(c1, c2, 7.7, bitset<16>377, 42);
}
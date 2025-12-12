#include<iostream>
#include"String.h"
using namespace std;
ostream& operator<<(ostream& os, const String& str) {
	os << str.get_c_str();
	return os;
}
int main() {
	String s1("mystring");
	string s2;
	String* p = new String("hello");
	cout << *p;
	delete p;
	return 0;

}
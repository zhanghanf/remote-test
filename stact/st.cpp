#include<iostream>
#include"Sample.h"
using namespace std;

void main() {
	StaticSample::display();
	StaticSample s1, s2;
	StaticSample::display();
	StaticSample* p1 = new StaticSample;
	p1->display();
	delete p1;
	StaticSample::display();
}
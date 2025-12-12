#include "Sample.h"
#include<iostream>
int StaticSample::obj_count = 0;
int StaticSample::obj_living = 0;
StaticSample::StaticSample() {
	++obj_count;
	++obj_living;
}
StaticSample::~StaticSample() {
	--obj_living;
}
void  StaticSample::display() {//在类外写定义时不需要在定义static
	std::cout << obj_count << obj_living;
}
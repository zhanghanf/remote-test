#pragma once
#ifndef _ARRAY_
#define _ARRAY_
#include<iostream>
using namespace std;
#include<stdexcept>
class Array {
private:
	int* elem;
	int size;
	int MaxNum;
	void expend() {
		int* p = new int[2 * MaxNum];
		for (int i = 0; i < size; i++) {
			p[i] = elem[i];
		}
		delete[] elem;
		elem = p;
		p = nullptr;
		MaxNum = 2 * MaxNum;
	}
public:
	Array(int num = 10) :size(0), MaxNum(num) {
		elem = new int[MaxNum];
	}
	void push_back(int val);//Ä©Î²²åÈë
	void pop();//Ä©Î²É¾³ý
	void insert(int pos, int val);//°´Î»ÖÃ²åÈë
	//°´ÔªËØÉ¾³ý
	void erase(int val);
	//ÔªËØ²éÑ¯
	int find(int val);
	//±éÀú
	void display();
	~Array();
};
#endif // !_ARRAY_


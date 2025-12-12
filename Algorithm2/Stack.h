#pragma once
#include<iostream>
#ifndef _STACK_
#define _STACK_
class Stack
{
	//À≥–Ú’ª push pop top empty
private:
	int top;
	int* data;
	int mMAXSIZE;
	void expend(int size) {
		int* p = new int[size];
		memcpy(p, data, top * sizeof(int));
		delete[] data;
		data = p;
	}
public:
	Stack(int max=10) :top(0),mMAXSIZE(max) {
		data = new int[mMAXSIZE];
	}
	void Push(int val);
	int Top() const;
	void Pop();
	~Stack() {
		delete data;
		data = nullptr;
	}
	int size() { return top; }
	bool empty()const { return top == 0; }
};
#endif


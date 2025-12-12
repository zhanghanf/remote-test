#pragma once
#ifndef _DQEUE_
#define _DQEUE_
#include<iostream>
class dqeue
{
private:
	int* data;
	int first;
	int last;
	int MAXSIZE;
	void expend(int size) {
		int* elem = new int(size);
		memcpy(elem, data, MAXSIZE*sizeof(int));
		delete data;
		data = elem;
	}
public:
	dqeue(int len = 10) :MAXSIZE(len), data(new int(MAXSIZE)), first(0), last(0) {};
	~dqeue() { delete data; data = nullptr; }
	int top() {
		if (this->empty())throw "dqeue is empty";
		return data[(last - 1 + MAXSIZE) % MAXSIZE];
	}
	void push(int date) {
		if ((last + 1) % MAXSIZE == first) {
			expend(2 * MAXSIZE);
		}
		data[last] = date;
		last = (last + 1) % MAXSIZE;
	}
	void pop() {
		if (first == last)throw "dqeue is empty";
		first= (first + 1) % MAXSIZE;
	}
	bool empty() {
		return first == last;
	}
};
#endif


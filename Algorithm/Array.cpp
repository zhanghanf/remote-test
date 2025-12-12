#include "Array.h"

void Array::push_back(int val)
{
	if (this->size == this->MaxNum) expend();
	elem[size] = val;
	size = size + 1;;
}

void Array::pop()
{
	if (size > 0)size--;
}

void Array::insert(int pos, int val)
{
	if (pos<0 || pos>size)return;
	if (size == MaxNum) expend();
	for(int i = size; i > pos; i--) {
		elem[i + 1] = elem[i];
	}
	elem[pos] = val;
	size++;
}

void Array::erase(int val)
{
	int pos = find(val);
	if (pos < 0)return;
	for (int i = pos; i < size - 1; i++) {
		elem[i] = elem[i + 1];
	}
	size--;
}

int Array::find(int val)
{
	for (int i = 0; i < size; i++) {
		if (elem[i] == val)return i;
	}
	return -1;
}

void Array::display()
{
	cout << size << endl;
	for (int i = 0; i < size; i++) {
		cout << elem[i] << " ";
	}
}

Array::~Array()
{
	delete[]elem;
	elem = nullptr;
}

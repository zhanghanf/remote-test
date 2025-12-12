#include "Stack.h"

void Stack::Push(int val)
{
	if (top == mMAXSIZE) {
		expend(2 * mMAXSIZE);
	}
	data[top] = val;
	top++;
}

int Stack::Top() const
{
	return data[top-1];
}

void Stack::Pop()
{
	if (top != 0)top--;
	else throw "stack is empty!";
}

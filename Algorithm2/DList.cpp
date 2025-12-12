#include "DList.h"
#include<iostream>
void DList::InSert(int val)
{
	DNode* p = new DNode(val);
	head->next->pre = p;
	p->next = head->next;
	p->pre = head;
	head->next = p;
}

void DList::InSertLast(int val)
{
	DNode* p = new DNode(val);
	last->pre->next = p;
	p->pre = last->pre;
	p->next = last;
	last->pre = p;
}

void DList::Del()
{
	if (last->pre == head)return;
	auto p = last->pre->pre;
	p->next = last;
	p = last->pre;
	last->pre = last->pre->pre;
	delete p;
}

void DList::Dispay() const
{
	auto p = head;
	while (p->next != last) {
		p = p->next;
		std::cout << p->data << " ";
	}
}

DList::~DList()
{
	auto p = head;
	auto q = p->next;
	while (p != nullptr) {
		q = p->next;
		delete p;
		p = q;
	}
}

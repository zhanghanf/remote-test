#pragma once
#ifndef _DLIST_
#define _DLIST_
struct DNode {
	DNode* pre;
	DNode* next;
	int data;
	DNode(int val=0) :data(val),pre(nullptr),next(nullptr){
	
	}
};
class DList
{
private:
	DNode* head;
	DNode* last;
public:
	DList():head(new DNode),last(new DNode) {
		head->next = last;
		last->pre = head;
	}
	void InSert(int val);
	void InSertLast(int val);
	void Del();
	void Dispay()const;
	~DList();
};
#endif


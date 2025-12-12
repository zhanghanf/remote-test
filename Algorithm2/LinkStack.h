#pragma once
#ifndef _LINK_
#define _LINK_
//设计有头节点的链式栈
struct Node {
	Node* next;
	int data;
	Node(int val=0): data(val),next(nullptr){

	}
};
class LinkStack
{
private:
	Node* head;
public:
	LinkStack() {
		head = new Node;
	}
	void push(int val) {
		Node* p = new Node(val);
		p->next = head->next;
		head = p;
	}
	void pop() {
		if (head->next == nullptr) {
			throw "stack is empty";
		}
		Node* p = head->next;
		head->next = p->next;
		delete p;
	}
	int top()const {
		if (head->next == nullptr) {
			throw "stack is empty";
		}
		return head->next->data;
	}
	bool empty() {
		return head->next == nullptr;
	}
	~LinkStack() {
		Node* p = head;
		while (p != nullptr) {
			head = head->next;
			delete p;
			p = head;
		}
	}
};
#endif

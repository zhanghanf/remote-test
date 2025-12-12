#pragma once
#ifndef _LDQEUE_
#define _LDQEUE_
struct Node {
	Node* pre;
	Node* rear;
	int data;
	Node() :data(0), pre(nullptr), rear(nullptr) {};
};
class Ldqeue
{
private:
	Node* head;
	Node* last;
public:
	Ldqeue() :head(new Node), last(new Node) {
		head->rear = last;
		last->pre = head;
	}
	~Ldqeue() {
		Node* p = head->rear;
		while (p->rear != nullptr) {
			head->rear = p->rear;
			delete p;
			p = head->rear;
		}
		delete head;
	}
};
#endif


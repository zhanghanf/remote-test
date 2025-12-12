#pragma once
#ifndef _LIST_H_
#define _LIST_H_
//节点类型
#include<iostream>
struct Node {
	Node* next;
	int data;
	Node(int val = 0) :data(val), next(nullptr) {};
};
class List
{
private:
	Node* head;
public:

	List() {
		head = new Node;
	}
	//void insert(Node* node);
	//头插法
	void inserthead(int val) {
		Node* p = new Node(val);
		if (head->next == nullptr) {
			head->next = p;
			return;
		}
		p->next = head->next;
		head->next = p;
	}
	//尾插法
	void insertail(int val) {
		Node* p = new Node(val);
		Node* q = head;
		while (q->next != nullptr) {
			q = q->next;
		}
		q->next = p;
		
	}
	Node* Getnext() {
		return this->head;
	}
	//删除元素
	void remove(int val) {
		Node* p = head->next;
		Node* q = head;
		while (p != nullptr) {
			if (p->data == val) {
				q->next = p->next;
				p->next = nullptr;
				delete p;
				return;
			}
			q = p;
			p = p->next;
		}
	}
	//遍历
	void display() {
		std::cout << head->data<<std::endl;
		Node* p = head->next;
		while (p != nullptr) {
			std::cout << p->data << " ";
			p = p->next;
		}
	}
	void ListReverse();
	~List() {
		Node* p = head;
		while (head->next != nullptr) {
			
			head = head->next;
			delete p;
			p = head;
		}
		delete head;
		head = nullptr;
	}
	friend void Merge(List& head1, List& head2);
};

#endif


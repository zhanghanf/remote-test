#pragma once
#ifndef _QUEUE_H
#define _QUEUE_
#include<cstdlib>
class Customer
{
private:
	long arrive; //arrival time for customer
	int processingtime;//processing time for customer;
public:
	Customer() :arrive(0), processingtime(0) {}
	void set(long when) ;
	long when() const { return arrive; }
	int ptime()const { return processingtime; }
};
typedef Customer item;
class Queue
{
private:
	enum { Q_SIZE = 10 };//定义队列最大元素个数
	//数据存储设计：基于链表
	struct Node { item data; Node* next; };
	Node* front;
	Node* rear;
	int items;
	const int qsize;
public:
	//构造函数和析构函数
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty() const;//判断是否为空
	bool isfull() const;//判断是否满了；
	int queuecount()const;//判断元素个数
	bool enqueue(const item&date);//插入
	bool dequeue(item&date);//删除
};


#endif // !_QUEUE_H


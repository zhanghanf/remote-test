#include "Queue.h"

Queue::Queue(int qs):qsize(qs)
{
	front = rear = nullptr;
	items = 0;
	//qsize = Q_SIZE;//常量只能初始化
}

Queue::~Queue()
{
	if (isempty())return;
	Node* temp ;
	while (front != nullptr) {
		temp = front;
		front = front->next;
		delete temp;
	}
	
}

bool Queue::isempty() const
{
	return items==0;
}

bool Queue::isfull() const
{
	return items==qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const item& date)
{
	if(isfull())
		return false;
	Node* add = new Node;//create anode;
	add->data = date;
	add->next = nullptr;
	items++;
	if (front == nullptr)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Queue::dequeue(item& date)
{
	if(front==nullptr)
		return false;
	date = front->data;
	items--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = nullptr;
	return true;
}

void Customer::set(long when) 
{
	arrive = when;
	processingtime = std::rand() % 3 + 1;
}
bool newCustomer(double x) {
	return (std::rand() * x / RAND_MAX < 1);//平局每x分钟来一个顾客
}
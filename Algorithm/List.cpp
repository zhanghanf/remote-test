#include "List.h"

void List::ListReverse()
{
	if (head->next == nullptr)return;
	Node* p = head->next;
	Node* q = nullptr;
	while (p ->next!= nullptr) {
		head->next = p->next;
		p->next = q;
		q = p;
		p = head->next;
	}
	p->next = q;
}

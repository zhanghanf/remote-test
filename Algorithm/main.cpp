
#include<vector>
#include"Array.h"
#include"List.h"
using namespace std;

#include<stdlib.h>
#include<time.h>

//逆序字符串
void Reverse(char arr[], int size){
	char* p = arr;
	char* q = arr + size - 1;
	while (p < q){
		char ch = *p;
		*p = *q;
		*q = *p;
		p++;
		q--;
	}
}
void Sort(vector<int> &arr) {
	/*
	int p = 0;
	for (int i = 0; i < arr.size();i++) {
		if (arr[i] % 2 == 0) {
			swap(arr[p], arr[i]);
			p++;
		}
	}
	*/
	int p = 0, q = arr.size() - 1;
	while (p < q) {
		/*
		* if (arr[p] % 2 == 0 && arr[q] % 2 == 1) {
			p++, q--;
			continue;
		}
		if (arr[p] % 2 == 1 && arr[q] % 2 == 0) {
			swap(arr[p], arr[q]);
			p++, q--;
			continue;
		}
		if (arr[p] % 2 == 1&& arr[q] % 2 == 1) {
			q--;
			continue;
		}
		if (arr[p] % 2 == 0 && arr[q] % 2 == 0) {
			p++;
			continue;
		}
		*/
		while (((arr[p] & 1 )== 0) && p < q)p++;
		while (((arr[q] & 1 )== 1) && p < q)q--;
		swap(arr[p], arr[q]);
		p++, q--;
	}
}
void delVelue(vector<int>& arr) {
	int p = 0,q = 1;
	if (arr.size() < 2)return;
	while (q < arr.size()) {
		if (arr[q] == arr[p]) {
			q++;
			continue;
		}
		p++;
		swap(arr[p], arr[q]);
		q++;
	}
}

//从小到大
void Merge(List&head1, List&head2) {
	Node* p = head1.head->next;
	Node* q = head2.head->next;
	Node* last = head1.head;
	head2.head->next = nullptr;

	while(p!=nullptr&&q!=nullptr){
		if (p->data > q->data) {
			last->next = q;
			q = q->next;
			last = last->next;
		}
		else {
			last->next = p;
			p = p->next;
			last = last->next;
		}
	}
	if (p != nullptr)last->next = p;
	else last->next = q;
}
//单链表是否有环
int main() {
	/*
	* Array a;
	for (int i = 0; i < 20; i++) {
		a.push_back(i);
	}
	a.pop();
	a.erase(4);
	cout << a.find(5) << endl;
	a.display();
	*/
	/*
	vector<int> arr { 1,1,5,5,7,10,10 };
	delVelue(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i];
	}
	*/
	
	List l,l1;
	int arr[] = { 13,15,22,56,78 };
	int brr[] = { 17,23,53,67,99 };
	for (auto v : arr) {
		l.insertail(v);
	}
	l.display();
	for (auto v : brr) {
		l1.insertail(v);
	}
	l1.display();
	Merge(l, l1);
	l.display();
	cout << "ss";
	l1.display();
	/*
	cout << __LINE__ << endl;
	cout << __FILE__ << endl;
	cout << __DATE__ << endl;
	cout << __TIME__ << endl;
	cout << __cplusplus << endl;
	cout << __STDC_HOSTED__ << endl;
	*/
	
	
	
}
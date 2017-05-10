#pragma once

#include "Node.h"

template <class T>
class queue {
public:
	node<T> *firstElement;
	node<T> *head;
	node<T> *last;

	queue() : head(NULL), last(NULL), firstElement(NULL) {}

	~queue() {
		while (!empty()) {
			deleteElement();
		}
	}

	bool empty() {
		if (head == NULL) return 1;
		else return 0;
	}

	node<T> *addNewElement(T data) {
		node<T> *tmp = new node<T>;
		tmp->data = data;
		tmp->next = NULL;
		return tmp;
	}

	void push(T data) {
		if (!empty()) {
			node<T> *tmp = addNewElement(data);
			last->next = tmp;
			last = tmp;
		}
		else {
			node<T> *tmp = addNewElement(data);
			head = tmp;
			last = tmp;
			firstElement = tmp;
		}
	}

	node<T>* pop() {
		if (!empty()) {
			node<T> *tmp = head;
			head = head->next;
			return tmp;
		}
		else return NULL;
	}

	T currentElement() {
		if (!empty())
			return head->data;
		else return NULL;
	}

	int sizeOfQueue() {
		node<T> *tmp = head;
		int a = 0;
		if (head == NULL) return 0;
		else if (head == last) return 1;

		while (tmp != NULL) {
			a++;
			tmp = tmp->next;
		}

		return a;
	}

	void deleteElement() {
		if (empty()) return;
		else if (head == last) {
			delete head;
			head = NULL;
			last = NULL;
		}
		else {
			node<T> *tmp = head;
			head = head->next;
			delete tmp;
		}
	}


};


//void showAll(queue_node *head, queue_node *last) {
//	int i = 0; // counting size of given queue_node
//	while (!empty(head)) {
//		if (head == last)
//			cout << head->data << endl;
//		else
//			cout << head->data << "->";
//		head = head->next;
//		i++;
//	}
//}
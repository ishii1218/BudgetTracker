/*#pragma once
#include<iostream>
#include"DisplayFunction.h"
#include"DoublyLinkedList.h"
#include"Node.h"

using namespace std;


class Singly_Linked_List {
public:
	Month* head;
	Month* tail;

	int size;

	Singly_Linked_List() {
		head = NULL;
		tail = NULL;
		size = 0;

	}

	void firstMonth() {
		string mon;
		Month* temp = new Month(select_3);
		temp->CreateNodes(dysofm(yr, select_3));
		head = temp;
		size++;
	}

	void continueMonth() {
		Month* temp = new Month(select_3);
		temp->CreateNodes(dysofm(yr, select_3));

		Month* current = head;
		for (int i = 0; i < size-1; i++) {
			current = current->next;
		}
		current->next = temp;
	}

	void print() {
		Month* current = head;
		for (int i = 0; i < size - 1; i++) {
			current = current->next;
		}
		cout << current->elem << endl;

	}

};*/
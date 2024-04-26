#pragma once

using namespace std;


template<typename T>

class DoublyLinkedList
{

	struct dNode
	{
		T val;
		dNode* next;
		dNode* prev;
	};
	dNode* head, * tail;
	int length;

public:
	bool isExist(T element);
	bool isItemAtEqual(T element, int index);
	void swap(int firstItemIdx, int secondItemIdx);
	bool isEmpty();
	int linkedListSize();
	void clear();
	void print();
	DoublyLinkedList();
	void insertAtHead(T element);
	void insertAtTail(T element);
	void insertAt(T element, int index);
	void removeAtHead();
	void removeAtTail();
	void removeAt(int index);
	T retrieveAt(int index);
	void replaceAt(T element, int index);
};

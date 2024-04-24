#pragma once

using namespace std;
struct Node
{
	int val;
	Node* next;
};


class singelLinkedList
{
	Node* head, * tail;
	int length;

	public:
        singelLinkedList();
		void insertAtHead(int element) ;
		void insertAtTail(int element);
		void insertAt(int element,int index);
		void removeAtHead();
		void removeAtTail();
		void removeAt(int index);
		int retrieveAt(int index);
		void replaceAt(int element, int index);
};


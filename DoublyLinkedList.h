#pragma once

using namespace std;
struct Node
{
	int val;
	Node* next;
	Node* prev;
};


class DoublyLinkedList
{
	Node* head, * tail;
	int length;

	public:
    //Not Tested Yet
        bool isExist(int element);
        bool isItemAtEqual(int element, int index);
        void swap(int firstItemIdx, int secondItemIdx);
        bool isEmpty();
        int linkedListSize();
        void clear();
        void print();
    //Not Implemented Yet
        DoublyLinkedList();
		void insertAtHead(int element) ;
		void insertAtTail(int element);
		void insertAt(int element,int index);
		void removeAtHead();
		void removeAtTail();
		void removeAt(int index);
		int retrieveAt(int index);
		void replaceAt(int element, int index);
};

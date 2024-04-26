#pragma once

using namespace std;

template<typename T>
class singelLinkedList
{

	struct sNode
	{
		int val;
		sNode* next;
	};


	sNode* head, * tail;
	int length;

	public:
		singelLinkedList();
		void insertAtHead(T element) ;
		void insertAtTail(T element);
		void insertAt(T element,int index);
		void removeAtHead();
		void removeAtTail();
		void removeAt(int index);
		T retrieveAt(int index);
		void replaceAt(T element, int index);
		bool isExist(T element);
		bool isItemAtEqual(T element, int index);
		void swap(int firstItemIdx, int secondItemIdx);
		bool isEmpty();
		int linkedListSize();
		void clear();
		void print();
};


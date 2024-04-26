#pragma once


template<typename T>

class Stack
{
	struct stackNode
	{
		T val;
		stackNode* next;
	};
	stackNode* Top, * bottom;
	int length;
	 
	public:
		Stack();
		void push(T element);
		T pop();
		T top();
		bool isEmpty();
		int stackSize();
		void clear();
		void print();
};
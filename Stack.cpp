#include "Stack.h"
#include <iostream>
using namespace std;



template<typename T>
Stack<T>::Stack() {
	length = 0;
	Top = bottom = NULL;
}



template<typename T>
void Stack<T>::push(T element) {
	stackNode* newNode = new stackNode;
	newNode->val = element;
	if (length == 0) {
		Top = bottom = newNode;
		bottom->next = NULL;
	}
	
	else {
		newNode->next = Top;
		Top = newNode;
	}
	length++;
}



template<typename T>
T Stack<T>::pop() {
	stackNode* current = Top;
	Top = Top->next;
	T element = current->val;
	delete current;
	length--;
	return element;
}



template<typename T>
T Stack<T>::top() {
	return Top->val;
}



template<typename T>
bool Stack<T>::isEmpty() {
	return (length == 0);
}



template<typename T>
int Stack<T>::stackSize() {
	return length;
}



template<typename T>
void Stack<T>::clear() {
	while (length != 0) {
		pop();
	}
}



template<typename T>
void Stack<T>::print() {
	stackNode* current = Top;
	while (current != NULL) {
		cout << current->val << " ";
		current = current->next;
	}
}
#include "singelLinkedList.h"
#include<iostream>

singelLinkedList::singelLinkedList() {
	head = tail = NULL;
	length = 0;
}

void singelLinkedList::insertAtHead(int element) {
	Node* newNode = new Node;
	newNode->val = element;
	if (length == 0) {
		head = tail = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = head;
		head = newNode;
	}
	length++;
}

void singelLinkedList::insertAtTail(int element) {
	Node* newNode = new Node;
	newNode->val = element;
	if (length == 0) {
		head = tail = newNode;
		newNode->next = NULL;
	}
	else {
		tail->next = newNode;
		tail = newNode;
		newNode->next = NULL;
	}
	length++;
}

void singelLinkedList::insertAt(int element, int index) {
	if (index == 0) {
		insertAtHead(element);
	}
	else if (index == length) {
		insertAtTail(element);
	}
	else {
		Node* newNode = new Node;
		newNode->val = element;
		Node* current = head;
		for (int i = 1; i < index; i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		length++;
	}
}

void singelLinkedList::removeAtHead() {
	if (length == 0) {
		cout << "the list is already empty.";
	}
	else if (length == 1) {
		delete head;
		head = tail = NULL;
		length--;
	}
	else {
		Node* current = head;
		head = head->next;
		delete current;
		length--;
	}
}

void singelLinkedList::removeAtTail() {
	if (length == 0) {
		cout << "the list is already empty.";
	}
	else if (length == 1) {
		delete head;
		head = tail = NULL;
		length--;
	}
	else {
		Node* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		tail = current;
		current = current->next;
		tail->next = NULL;
		delete current;
		length--;
	}
}

void singelLinkedList::removeAt(int index) {
	if (length == 0) {
		cout << "the list is already empty.";
	}

	if (index == 0) {
		removeAtHead();
	}
	else if (index == length) {
		removeAtTail();
	}
	else {
		Node* current = head->next;
		Node* previos = head;
		for (int i = 1; i < index; i++) {
			previos = current;
			current = current->next;
		}
		previos->next = current->next;
		if (tail == current) {
			tail = previos;
		}
		delete current;
		length--;
	}
}

int singelLinkedList::retrieveAt(int index) {
	if (index == 0) {
		return (head->val);
	}
	else if (index == length - 1) {
		return (tail->val);
	}
	else {
		Node* current = head;
		for (int i=0; i < index; i++) {
			current = current->next;
		}
		return (current->val);
	}
}

void singelLinkedList::replaceAt(int element, int index) {
	if (index == 0) {
		head->val = element;
	}
	else if (index == length - 1) {
		tail->val = element;
	}
	else {
		Node* current = head;
		for (int i = 0; i < index; i++) {
			current = current->next;
		}
		current->val = element;
	}
}

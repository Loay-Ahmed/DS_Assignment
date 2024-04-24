#include "DoublyLinkedList.h"
#include<iostream>

bool DoublyLinkedList::isExist(int element) {
    Node* current = head;
    if (length > 0) {
        while (current->next != NULL) {
            if (current->val == element) {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}

bool DoublyLinkedList::isItemAtEqual(int element, int index) {
    Node* current = head;
    int count = 1;
    if (length > 1) {
        while (current->next != NULL) {
            if (index == count && current->val == element) {
                return true;
            }
            current = current->next;
            count++;
        }
    }
    return false;
}

void DoublyLinkedList::swap(int firstItemIdx, int secondItemIdx) {
    if (length > 1) {
        Node* current1 = head;
        Node* current2 = head;
        for (int i = 0; i < firstItemIdx; i++) {
            current1 = current1->next;
        }
        for (int i = 0; i < secondItemIdx; i++) {
            current2 = current2->next;
        }
        int* tmp = new int(current1->val);
        current1->val = current2->val;
        current2->val = *tmp;
        delete tmp;
        tmp = nullptr;
    }
    else {
        cout << "Can't swap, list is less than 2";
    }
}

bool DoublyLinkedList::isEmpty() {
    return (length == 0 && head == NULL && tail == NULL);
}

int DoublyLinkedList::linkedListSize() {
    return length;
}

void DoublyLinkedList::clear() {
    Node* current = head;
    while (current != NULL) {
        Node* tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::print() {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

DoublyLinkedList::DoublyLinkedList() {
    head = tail = NULL;
    length = 0;
}


void DoublyLinkedList :: insertAtHead(int element) {
    Node* newNode = new Node;
    newNode->val = element;
    if (length == 0) {
        newNode->next = newNode->prev = NULL;
        head = tail = newNode;
    }
    else {
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
    length++;
}


void DoublyLinkedList::insertAtTail(int element) {
    Node* newNode = new Node;
    newNode->val = element;
    if (length == 0) {
        newNode->next = newNode->prev = NULL;
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = NULL;
        tail = newNode;
    }
    length++;
}


void DoublyLinkedList::insertAt(int element, int index) {
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
        newNode->prev = current;
        current->next = newNode;
        current->next->prev = newNode;
        length++;
    }
}


void DoublyLinkedList::removeAtHead() {
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


void DoublyLinkedList::removeAtTail() {
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


void DoublyLinkedList::removeAt(int index) {
    if (index == 0) {
        removeAtHead();
    }
    else if (index == length - 1) {
        removeAtTail();
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        length--;
    }
}


int DoublyLinkedList::retrieveAt(int index) {
    if (index == 0) {
        return (head->val);
    }
    else if (index == length - 1) {
        return (tail->val);
    }
    else {
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return (current->val);
    }
}

void DoublyLinkedList::replaceAt(int element, int index) {
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

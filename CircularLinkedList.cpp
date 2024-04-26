#include "CircularLinkedList.h"
#include<iostream>
#include <string>

template<typename T>

CircularLinkedList<T>::CircularLinkedList() {
    tail = NULL;
    length = 0;
}

template<typename T>
void CircularLinkedList<T>::insertAtHead(const T& element) {
    cirqNode* newNode = new cirqNode;
    newNode->val = element;
    if (length == 0) {
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    length++;
}


template<typename T>
void CircularLinkedList<T>::insertAtTail(const T& element) {
    cirqNode* newNode = new cirqNode;
    newNode->val = element;
    if (length == 0) {
        tail = newNode;
        newNode->next = newNode;
    }
    else {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}



template<typename T>
void CircularLinkedList<T>::insertAt(const T& element, int index) {
    if (index == 0) {
        insertAtHead(element);
    }

    else if (index == length) {
        insertAtTail(element);
    }
    
    else {
        cirqNode* newNode = new cirqNode;
        newNode->val = element;
        cirqNode* current = tail->next;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }
}


template<typename T>
void CircularLinkedList<T>::removeAtHead() {
    if (length == 0) {
        cout << "the list is already empty.";
    }
    else if (length == 1) {
        delete tail;
        tail = NULL;
        length--;
    }
    else {
        cirqNode* current = tail->next;
        tail->next = current->next;
        delete current;
        length--;
    }
}


template<typename T>
void CircularLinkedList<T>::removeAtTail() {
    if (length == 0) {
        cout << "the list is already empty.";
    }
    else if (length == 1) {
        delete tail;
        tail = NULL;
        length--;
    }
    else {
        cirqNode* current = tail->next;
        while (current->next != tail) {
            current = current->next;
        }
        tail = current;
        current = current->next;
        tail->next = current->next;
        delete current;
        length--;
    }
}



template<typename T>
void CircularLinkedList<T>::removeAt(int index) {
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
        cirqNode* previos = tail->next;
        cirqNode* current = previos->next;
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



template<typename T>
T CircularLinkedList<T>::retrieveAt(int index) {
    if (index == 0) {
        return (tail->next->val);
    }
    else if (index == length - 1) {
        return (tail->val);
    }
    else {
        cirqNode* current = tail->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return (current->val);
    }
}



template<typename T>
void CircularLinkedList<T>::replaceAt(const T& element, int index) {
    if (index == 0) {
        tail->next->val = element;
    }
    else if (index == length - 1) {
        tail->val = element;
    }
    else {
        cirqNode* current = tail->next;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->val = element;
    }
}



template<typename T>
bool CircularLinkedList<T>::isExist(const T& element) {
    cirqNode* current = tail->next;
    if (length > 0) {
        while (current->next != tail->next) {
            if (current->val == element) {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}


template<typename T>
bool CircularLinkedList<T>::isItemAtEqual(const T& element, int index) {
    cirqNode* current = tail->next;
    if (length > 0) {
        while (current != NULL) {
            if (current->val == element) {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}



template<typename T>
void CircularLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (length > 1) {
        cirqNode* current1 = tail->next;
        cirqNode* prev1 = NULL;
        cirqNode* current2 = tail->next;
        cirqNode* prev2 = NULL;
        for (int i = 0; i < firstItemIdx; i++) {
            prev1 = current1;
            current1 = current1->next;
        }
        for (int i = 0; i < secondItemIdx; i++) {
            prev2 = current2;
            current2 = current2->next;
        }
        prev1->next = current2;
        prev2->next = current1;
        prev2 = current2->next;
        current2->next = current1->next;
        current1->next = prev2;
    }
    else {
        cout << "Can't swap, list is less than 2";
    }
}



template<typename T>
bool CircularLinkedList<T>::isEmpty() {
    return (length == 0 && tail == NULL);
}



template<typename T>
int CircularLinkedList<T>::linkedListSize() {
    return length;
}



template<typename T>
void CircularLinkedList<T>::clear() {
    while (tail != NULL) {
        removeAtHead();
    }
}


template<typename T>
void CircularLinkedList<T>::print() {
    cirqNode* current = tail->next;
    cout << current->val << " ";
    current = current->next;
    while (current != tail->next) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

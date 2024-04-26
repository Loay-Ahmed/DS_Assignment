#include "DoublyLinkedList.h"
#include<iostream>


template<typename T>
bool DoublyLinkedList<T>::isExist(T element) {
    dNode* current = head;
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



template<typename T>
bool DoublyLinkedList<T>::isItemAtEqual(T element, int index) {
    dNode* current = head;
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
void DoublyLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (length > 1) {
        dNode* current1 = head;
        dNode* prev1 = NULL;
        dNode* nxt1 = current1->next;
        dNode* current2 = head;
        dNode* prev2 = NULL;
        dNode* nxt2 = current2->next;
        for (int i = 0; i < firstItemIdx; i++) {
            prev1 = current1;
            current1 = current1->next;
            nxt1= current1->next;
        }
        for (int i = 0; i < secondItemIdx; i++) {
            prev2 = current2;
            current2 = current2->next;
            nxt2 = current2->next;
        }

        prev1->next = current2;
        prev2->next = current1;

        current1->prev = prev2;
        current2->prev = prev1;

        current2->next = nxt1;
        current1->next = nxt2;

        nxt1->prev = current2;
        nxt2->prev = current1;

    }
    else {
        cout << "Can't swap, list is less than 2";
    }
}



template<typename T>
bool DoublyLinkedList<T>::isEmpty() {
    return (length == 0 && head == NULL && tail == NULL);
}



template<typename T>
int DoublyLinkedList<T>::linkedListSize() {
    return length;
}



template<typename T>
void DoublyLinkedList<T>::clear() {
    while (tail != NULL) {
        removeAtHead();
    }
}



template<typename T>
void DoublyLinkedList<T>::print() {
    dNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}



template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = tail = NULL;
    length = 0;
}


template<typename T>
void DoublyLinkedList<T> :: insertAtHead(T element) {
    dNode* newNode = new dNode;
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



template<typename T>
void DoublyLinkedList<T>::insertAtTail(T element) {
    dNode* newNode = new dNode;
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



template<typename T>
void DoublyLinkedList<T>::insertAt(T element, int index) {
    if (index == 0) {
        insertAtHead(element);
    }
    else if (index == length) {
        insertAtTail(element);
    }
    else {
        dNode* newNode = new dNode;
        newNode->val = element;
        dNode* current = head;
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



template<typename T>
void DoublyLinkedList<T>::removeAtHead() {
    if (length == 0) {
        cout << "the list is already empty.";
    }
    else if (length == 1) {
        delete head;
        head = tail = NULL;
        length--;
    }
    else {
        dNode* current = head;
        head = head->next;
        delete current;
        length--;
    }
}



template<typename T>
void DoublyLinkedList<T>::removeAtTail() {
    if (length == 0) {
        cout << "the list is already empty.";
    }
    else if (length == 1) {
        delete head;
        head = tail = NULL;
        length--;
    }
    else {
        dNode* current = head;
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



template<typename T>
void DoublyLinkedList<T>::removeAt(int index) {
    if (index < 0 || index >= length) {
        cout << "Out Of Range" << endl;
        return;
    }
    else if (index == 0) {
        removeAtHead();
    }
    else if (index == length - 1) {
        removeAtTail();
    }
    else {
        dNode* current = head->next;
        dNode* previos = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
            previos = previos->next;
        }
        previos->next = current->next;
        previos = current->next;
        previos->prev = current->prev;
        delete current;
        length--;
    }
}



template<typename T>
T DoublyLinkedList<T>::retrieveAt(int index) {
    if (index == 0) {
        return (head->val);
    }
    else if (index == length - 1) {
        return (tail->val);
    }
    else {
        dNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return (current->val);
    }
}



template<typename T>
void DoublyLinkedList<T>::replaceAt(T element, int index) {
    if (index == 0) {
        head->val = element;
    }
    else if (index == length - 1) {
        tail->val = element;
    }
    else {
        dNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->val = element;
    }
}

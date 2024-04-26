#include "singelLinkedList.h"
#include<iostream>


template<typename T>
singelLinkedList<T>::singelLinkedList() {
    head = tail = NULL;
    length = 0;
}



template<typename T>
void singelLinkedList<T>::insertAtHead(T element) {
    sNode* newNode = new sNode;
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



template<typename T>
void singelLinkedList<T>::insertAtTail(T element) {
    sNode* newNode = new sNode;
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



template<typename T>
void singelLinkedList<T>::insertAt(T element, int index) {
    if (index == 0) {
        insertAtHead(element);
    }
    else if (index == length) {
        insertAtTail(element);
    }
    else {
        sNode* newNode = new sNode;
        newNode->val = element;
        sNode* current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }
}



template<typename T>
void singelLinkedList<T>::removeAtHead() {
    if (length == 0) {
        cout << "the list is already empty.";
    }
    else if (length == 1) {
        delete head;
        head = tail = NULL;
        length--;
    }
    else {
        sNode* current = head;
        head = head->next;
        delete current;
        length--;
    }
}



template<typename T>
void singelLinkedList<T>::removeAtTail() {
    if (length == 0) {
        cout << "the list is already empty.";
    }
    else if (length == 1) {
        delete head;
        head = tail = NULL;
        length--;
    }
    else {
        sNode* current = head;
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
void singelLinkedList<T>::removeAt(int index) {
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
        sNode* current = head->next;
        sNode* previos = head;
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
T singelLinkedList<T>::retrieveAt(int index) {
    if (index == 0) {
        return (head->val);
    }
    else if (index == length - 1) {
        return (tail->val);
    }
    else {
        sNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return (current->val);
    }
}



template<typename T>
void singelLinkedList<T>::replaceAt(T element, int index) {
    if (index == 0) {
        head->val = element;
    }
    else if (index == length - 1) {
        tail->val = element;
    }
    else {
        sNode* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->val = element;
    }
}



template<typename T>
bool singelLinkedList<T>::isExist(T element) {
    sNode* current = head;
    if (length > 0) {
        while (current!= NULL) {
            if (current->val == element) {
                return true;
            }
            current = current->next;
        }
    }
    return false;
}



template<typename T>
bool singelLinkedList<T>::isItemAtEqual(T element, int index) {
    sNode* current = head;
    int count = 0;
    if (length > 0) {
        while (current != NULL) {
            if (index == count && current->val == element) {
                return true;
            }
            current = current->next;
            count++;
        }
    }
    return false;
}



template<typename T>
void singelLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (length > 1) {
        sNode* current1 = head;
        sNode* prev1 = NULL;
        sNode* current2 = head;
        sNode* prev2 = NULL;
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
bool singelLinkedList<T>::isEmpty() {
    return (length == 0 && head == NULL && tail == NULL);
}



template<typename T>
int singelLinkedList<T>::linkedListSize() {
    return length;
}



template<typename T>
void singelLinkedList<T>::clear() {
    while (tail != NULL) {
        removeAtHead();
    }
}



template<typename T>
void singelLinkedList<T>::print() {
    sNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

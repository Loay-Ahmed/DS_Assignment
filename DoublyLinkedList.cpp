#include "DoublyLinkedList.h"
#include<iostream>

bool DoublyLinkedList::isExist(int element) {
    Node *current = head;
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
    Node *current = head;
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
        Node *current1 = head;
        Node *current2 = head;
        for (int i = 0; i < firstItemIdx; i++) {
            current1 = current1->next;
        }
        for (int i = 0; i < secondItemIdx; i++) {
            current2 = current2->next;
        }
        int *tmp = new int(current1->val);
        current1->val = current2->val;
        current2->val = *tmp;
        delete tmp;
        tmp = nullptr;
    } else {
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
    Node *current = head;
    while (current != NULL) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::print() {
    Node *current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

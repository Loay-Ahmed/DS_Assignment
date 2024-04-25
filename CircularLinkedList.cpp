#include "CircularLinkedList.h"
#include<iostream>

CircularLinkedList::CircularLinkedList() {
    head = tail = NULL;
    length = 0;
}

void CircularLinkedList::insertAtHead(int element) {
    Node *newNode = new Node;
    newNode->val = element;
    if (length == 0) {
        head = tail = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

void CircularLinkedList::insertAtTail(int element) {
    Node *newNode = new Node;
    newNode->val = element;
    if (length == 0) {
        head = tail = newNode;
        newNode->next = NULL;
    } else {
        tail->next = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
    length++;
}

void CircularLinkedList::insertAt(int element, int index) {
    if (index == 0) {
        insertAtHead(element);
    } else if (index == length) {
        insertAtTail(element);
    } else {
        Node *newNode = new Node;
        newNode->val = element;
        Node *current = head;
        for (int i = 1; i < index; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        length++;
    }
}

void CircularLinkedList::removeAtHead() {
    if (length == 0) {
        cout << "the list is already empty.";
    } else if (length == 1) {
        delete head;
        head = tail = NULL;
        length--;
    } else {
        Node *current = head;
        head = head->next;
        delete current;
        length--;
    }
}

void CircularLinkedList::removeAtTail() {
    if (length == 0) {
        cout << "the list is already empty.";
    } else if (length == 1) {
        delete head;
        head = tail = NULL;
        length--;
    } else {
        Node *current = head;
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

void CircularLinkedList::removeAt(int index) {
    if (length == 0) {
        cout << "the list is already empty.";
    }

    if (index == 0) {
        removeAtHead();
    } else if (index == length) {
        removeAtTail();
    } else {
        Node *current = head->next;
        Node *previos = head;
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

int CircularLinkedList::retrieveAt(int index) {
    if (index == 0) {
        return (head->val);
    } else if (index == length - 1) {
        return (tail->val);
    } else {
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return (current->val);
    }
}

void CircularLinkedList::replaceAt(int element, int index) {
    if (index == 0) {
        head->val = element;
    } else if (index == length - 1) {
        tail->val = element;
    } else {
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->val = element;
    }
}

bool CircularLinkedList::isExist(int element) {
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

bool CircularLinkedList::isItemAtEqual(int element, int index) {
    Node *current = head;
    int count = -1;
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

void CircularLinkedList::swap(int firstItemIdx, int secondItemIdx) {
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

bool CircularLinkedList::isEmpty() {
    return (length == 0 && head == NULL && tail == NULL);
}

int CircularLinkedList::linkedListSize() {
    return length;
}

void CircularLinkedList::clear() {
    Node *current = head->next;
    head->next = NULL;
    while (current != NULL) {
        Node *tmp = current;
        current = current->next;
        delete tmp;
    }
    head = NULL;
    tail = NULL;
}

void CircularLinkedList::print() {
    Node *current = head->next;
    cout << head->val << " ";
    while (current != head) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

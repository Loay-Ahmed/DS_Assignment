#include "Queue.h"

template<typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

template<typename T>
Queue<T>::~Queue() {
    clear();
}

template<typename T>
void Queue<T>::enqueue(const T &element) {
    Node *newNode = new Node(element);
    if (isEmpty()) {
        frontNode = newNode;
    } else {
        rearNode->next = newNode;
    }
    rearNode = newNode;
    size++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw logic_error("Queue is empty");
    }
    Node *temp = frontNode;
    T element = temp->data;
    frontNode = frontNode->next;
    delete temp;
    size--;
    return element;
}

template<typename T>
T Queue<T>::first() const {
    if (isEmpty()) {
        throw logic_error("Queue is empty");
    }
    return frontNode->data;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
int Queue<T>::queueSize() const {
    return size;
}

template<typename T>
void Queue<T>::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

template<typename T>
void Queue<T>::print() const {
    Node *current = frontNode;
    cout << "Queue: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}
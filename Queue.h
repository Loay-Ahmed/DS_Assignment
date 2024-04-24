#ifndef DS_ASSIGNMENT_QUEUE_H
#define DS_ASSIGNMENT_QUEUE_H


#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node *next;

        Node(const T &newData) : data(newData), next(nullptr) {}
    };

    Node *frontNode;
    Node *rearNode;
    int size;
public:
    // Constructor
    Queue();

    // Destructor
    ~Queue();

    //  add an element to the end of the queue
    void enqueue(const T &element);

    //  remove and return the first element in the queue
    T dequeue();

    //  return the first element without removing it
    T first() const;

    //  check if the queue is empty
    bool isEmpty() const;

    //  return the size of the queue
    int queueSize() const;

    //  clear the queue
    void clear();

    //  print the elements of the queue
    void print() const;
};

#endif //DS_ASSIGNMENT_QUEUE_H

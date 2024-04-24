#include "iostream"
#include "Queue.h"

int main() {
    Queue<int> q;
// Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
// Print queue
    q.print();
// Dequeue elements
    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Dequeued element: " << q.dequeue() << endl;
// Print queue
    q.print();
// Check first element
    cout << "First element: " << q.first() << endl;
// Check if queue is empty
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
// Clear queue
    q.clear();
// Check if queue is empty after clearing
    cout << "Is queue empty after clearing? " << (q.isEmpty() ? "Yes" : "No") << endl;
}
#include <string>
using namespace std;

template<typename T>
class CircularLinkedList {

    struct cirqNode {
        T val;
        cirqNode *next;
    };

    cirqNode *tail;
    int length;

public:
    //Not Tested Yet
    CircularLinkedList();

    void insertAtHead(const T &element);

    void insertAtTail(const T &element);

    void insertAt(const T &element, int index);

    void removeAtHead();

    void removeAtTail();

    void removeAt(int index);

    T retrieveAt(int index);

    void replaceAt(const T &element, int index);

    bool isExist(const T &element);

    bool isItemAtEqual(const T &element, int index);

    void swap(int firstItemIdx, int secondItemIdx);

    bool isEmpty();

    int linkedListSize();

    void clear();

    void print();
};

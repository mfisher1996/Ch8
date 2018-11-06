#include <iostream>
#include "unorderedLinkedList.h"
using namespace std;

template <class Type>
class linkedQueueType: public unorderedLinkedList<Type>
{
public:
    void initializeQueue();
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void addQueue(const Type& newItem);
    Type front() const;
    Type back() const;
    void deleteQueue();
};
template <class Type>
void linkedQueueType<Type>::initializeQueue()
{
    unorderedLinkedList<Type>::initializeList();
}
template <class Type>
bool linkedQueueType<Type>::isEmptyQueue() const
{
    return unorderedLinkedList<Type>::isEmptyList();
}
template <class Type>
bool linkedQueueType<Type>::isFullQueue() const
{
    return false;
}
template <class Type>
void linkedQueueType<Type>::addQueue(const Type& newElement)
{
    unorderedLinkedList<Type>::insertLast(newElement);
}
template <class Type>
Type linkedQueueType<Type>::front() const
{
    return unorderedLinkedList<Type>::front();
}

template <class Type>
Type linkedQueueType<Type>::back() const
{
    return unorderedLinkedList<Type>::back();
}

template <class Type>
void linkedQueueType<Type>::deleteQueue()
{
    if(!unorderedLinkedList<Type>::isEmptyList())
    {
        unorderedLinkedList<Type>::deleteNode(unorderedLinkedList<Type>::front());
    }
    else
        cout << "cannot remove from empty stack" << endl;

    return;
}

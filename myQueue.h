//
//  myQueue.h
//  Wk10_ch8
//
//  Created by Mason Fisher on 10/31/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//

#ifndef myQueue_h
#define myQueue_h

template<class Type>
class queueType{
private:
    Type * list;
    int queueFront;
    int queueRear;
    int maxSize;
    
public:
    /**
     queueType(int)
     constructor for queueType. sets maxSize of queue equal to int passed.
     */
    queueType(int size = 100){maxSize=size;queueFront = 0; queueRear = 0; list = new Type[maxSize];};
    /**
     ~queueType()
     deconstructor for queueType. Deletes the list created in the constructor.
     */
    ~queueType(){delete list;};
    /**
     isFullQueue()
     returns true if the queue is full and returns false otherwise
     */
    bool isFullQueue(){return (queueRear+1 == queueFront);};
    /**
     isEmptyQueue()
     returns true if queue is empty and returns false otherwise
     */
    bool isEmptyQueue(){return (queueRear == queueFront);};
    /**
     front()
     returns the item at position queueFront + 1
     */
    Type front(){return list[queueFront+1];};
    /**
     initializeQueue()
     sets queueFront and queueRear to 0
     */
    void initializeQueue(){queueFront = 0; queueRear = 0;};
    void moveNthFront(int n);
    void insertQueue(Type insertItem);
    void deleteQueue();
    
    
};


/**
 insertQueue(Type)
 insert item for type specified at object construction. Adds a new Type to the end of the
 list.
 */
template<class Type>
void queueType<Type>::insertQueue(Type insertItem){
    if(!isFullQueue()){
        queueRear = (queueRear+1) % maxSize;
        list[queueRear] = insertItem;
    }else
        cout << "/t/tQueue is full.\n";
}
/**
 deleteQueue()
 Deletes the first item inserted into the queue if the queue is not empty.
 */
template<class Type>
void queueType<Type>::deleteQueue(){
    if(!isEmptyQueue())
        queueFront = (queueFront+1) % maxSize;
    else
        cout << "/t/tQueue is empty.\n";
}
/**
 moveNthFront(int)
 Moves value at index locaiton int passed to index location queueFront
 */
template<class Type>
void queueType<Type>::moveNthFront(int n){
    n = (queueFront + n) % maxSize;
    Type value = list[n];
    if(!isEmptyQueue()){
        if(queueFront < n){
            for(int i = n; i > (queueFront%maxSize); i--){
                list[i] = list[i-1];
            }
        }else{
            for(int i = n; i > 0; i--)
                list[i] = list[i-1];
            list[0] = list[maxSize-1];
            for(int i = maxSize-1; i > queueFront+1; i--)
                list[i] = list[i-1];
        }
    }
    list[queueFront+1] = value;
}

#endif /* myQueue_h */

//
//  main.cpp
//  Wk10_ch8
//
//  Created by Mason Fisher on 10/30/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//
/*
 3. This chapter described the array implementation of queues that use a special
 array slot, called the reserved slot, to distinguish between an empty and a full
 queue. Write the definition of the class and the definitions of the function
 members of this queue design. Also, write a test program to test various
 operations on a queue.
 */

#include <iostream>
#include "Validation.h"
#include "myQueue.h"

using namespace std;

int main(int argc, const char * argv[]) {
    queueType<int> list(10);
    Validation check;
    check.out("list initialized with a size of 10.");
    list.insertQueue(5);
    check.out("5 was added to the queue.");
    list.insertQueue(6);
    check.out("6 was added to the queue.");
    list.insertQueue(8);
    check.out("8 was added to the queue.");
    cout << endl;
    check.out("The queue containts: ", 'x');
    while (!list.isEmptyQueue()){
        cout << list.front() << " ";
        list.deleteQueue();
    }
    cout << endl;
    
    
    return 0;
}

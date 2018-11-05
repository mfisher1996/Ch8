//
//  Ex4.cpp
//  Wk10_ch8
//
//  Created by Mason Fisher on 11/1/18.
//  Copyright © 2018 Mason Fisher. All rights reserved.
//
/**
 4. Write the definition of the function moveNthFront that takes as a parameter
 a positive integer, n. The function moves the nth element of the queue to
 the front. The order of the remaining elements remains unchanged. For
 example, suppose
 queue = {5, 11, 34, 67, 43, 55} and n = 3.
 After a call to the function moveNthFront,
 queue = {34, 5, 11, 67, 43, 55}.
 Add this function to the class queueType. Also write a program to test
 your method.
 */

#include "Validation.h"
#include "myQueue.h"

using namespace std;

int main(){
    queueType<int> myList;
    Validation check;
    
    check.out("How many items would you like to insert into this queue?");
    int num = check.numb(num);
    for(int i = num; i > 0;i--){
        check.out("Item " + to_string(num+1-i)+":");
        myList.insertQueue(check.numb(num));
    }
    check.out("What item would you like moved to first?");
    myList.moveNthFront(check.numb(num));
    
    check.out("The list holds: ", 'x');
    while(!myList.isEmptyQueue()){
        cout << myList.front() << " ";
        myList.deleteQueue();
    }
    
    return 0;
}

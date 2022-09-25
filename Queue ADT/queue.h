//
//  queue.h
//  Queue ADT
//
//  Created by blane on 9/25/22.
//

#ifndef queue_h
#define queue_h
#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class queue {
private:
    node* front; //irst node in queue
    node* rear;  //last node in queue
public:
    queue() {
        front = nullptr;
        rear = nullptr;
    }
    
    bool isEmpty() {
        if(front==nullptr && rear==nullptr) {
            return true;
        }
        else {
            return false;
        }
    }
    
    
    //adds node to end of list
    void enqueue(int val) {
        //new node created
        node* newNode = new node;
        newNode->data = val;
        newNode->next = nullptr;
        
        if(isEmpty()) {
            //if list is empty, node is pointed to by front and rear nodes
            front = newNode;
            rear = newNode;
        }
        else {
            //
            rear->next = newNode;
            rear = newNode;
        }
    }
    
    //remove element from front of queue
    void dequeue() {
        node* temp = new node;
        temp = front; //equal to first val
        front = front->next;
        delete temp;
    }
    
    char peek() {
        return front->data;
    }
    
    void print() {
        node* cu = front;
            
        while(cu!=nullptr) {
            cout << cu->data << " ";
            cu = cu->next;
        }
    }
    
    
};

#endif /* queue_h */

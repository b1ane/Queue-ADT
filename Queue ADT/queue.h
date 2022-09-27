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
    
    int peek() {
        return front->data;
    }
    
    void print() {
        node* cu = front;
            
        while(cu!=nullptr) {
            cout << cu->data << " ";
            cu = cu->next;
        }
    }
    
    
    int eval() {
        //starting from front of line
        node* cu = front;

        //john always starts out with 1 5 dollar bill
        int five = 1;
        int ten = 0;
        int twent = 0;
        int fift = 0;
        
        int money = 0;
        int change = 0;
        
        int retVal = 1;
        
        
        //if queue is not empty
        while (cu!=nullptr) {
            //take money from person
            money = money + cu->data;
            //remove person from line
            dequeue();
            //change to be given back to person
            change = cu->data - 5;
            //saves value of 5 (when 10)
            
            
            //keep count of bills given by person
            if (cu->data == 5) {
                five = five + 1;
            }
            if (cu->data == 10) {
                ten = ten + 1;
            }
            if (cu->data == 20) {
                twent = twent + 1;
            }
            if (cu->data == 50) {
                fift = fift + 1;
            }
            
            //calculate change to be given
            //if change to be given is more than 20 AND john has a 20
            while(change>= 50 && fift > 0) {
                change = change - 50;
                fift = fift - 1;
            }
            while (change >= 20 && twent > 0) {
                change = change - 20;
                twent = twent - 1;
            }
            while (change >= 10 && ten > 0) {
                change = change - 10;
                ten = ten - 1;
            }
            while (change >= 5 && five > 0) {
                change = change - 5;
                five = five - 1;
            }
            

            
            //checks how much money john has, stops line when john doesn't have correct change
            if (change == 5 && five == 0) {
                retVal = 0;
                break;
            }
            if(change == 10 && ten == 0){
                retVal = 0;
                break;
            }
            if(change == 20 && twent == 0){
                retVal = 0;
                break;
            }
            if(change == 50 && fift == 0){
                retVal = 0;
                break;
            }
            cu = cu->next;
            cout << endl;
        }
        
        return retVal;
    }
    
};

#endif /* queue_h */

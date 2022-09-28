//
//  main.cpp
//  Queue ADT
//John is selling sandwiches in front of a school each for $5. There is a queue of students who wants to purchase sandwich with available dollar bills of 5, 10, 20 or 50. At the beginning John has only a $5 bill with him. You will be given a string representation of integer values (separated by a space) containing the money each student has in their hand. You need to write a program to find if John will be able to provide change to everyone in the queue. Your output will be represented as 1 or 0 respectively if John can provide change to all or not. You MUST use a queue implementation (NO STL aka Standard Template Library) for each of these operations to receive credit. Feel free to include any variables you will need in your functions.
//  Created by blane on 9/25/22.
//

#include <iostream>
#include <string>
#include <sstream>
#include "queue.h"
using namespace std;

int main() {
    string input;
    getline(cin, input);
    
    int num;
    stringstream ss(input);
    
    queue q;
    while(ss>>num) {
        q.enqueue(num);
    }
    
    cout << q.eval() << endl;

    return 0;
}

//
//  main.cpp
//  Queue ADT
//
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
    
    
    q.print();
    cout << endl;

    return 0;
}

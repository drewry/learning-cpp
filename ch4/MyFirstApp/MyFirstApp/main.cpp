//
//  main.cpp
//  MyFirstApp
//
//  Created by Drewry Morris on 6/25/15.
//  Copyright (c) 2015 Drewry Morris. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int x = 0;
    
    x = 1;
    cout << "Excercise 1.1: " << endl;
    while(x <= 10) {
        cout << x << endl;
        x++;
    }
    
    x = 10;
    cout << "Excercise 1.2: " << endl;
    while(x >= 1) {
        cout << x << endl;
        x--;
    }
    
    x = 2;
    cout << "Excercise 1.3: " << endl;
    while(x <= 20) {
        cout << x << endl;
        x += 2;
    }
    
    x = 1;
    cout << "Excercise 1.4: " << endl;
    while(x <= 16) {
        cout << x << ", " << (x * x) << endl;
        x++;
    }
    
    return 0;
}

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

struct Vector {
    float x, y, z;
};

struct Player {
    string name;
    int hp;
    Vector position;
};

int main(int argc, const char * argv[]) {
    // create an object of type Player,
    Player me; // instance named 'me'
    me.name = "William";
    me.hp = 100.0f;
    me.position.x = me.position.y = me.position.z=0;
    
    cout << "Name?" << endl;
    string name;
    cin >> name;
    cout << "Age?" << endl;
    int age;
    cin >> age;
    cout << "Hello " << name << " I see you have attained " << age << " years. Congratulations." << endl;
    
    return 0;
}

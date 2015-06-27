//
//  main.cpp
//  MyFirstApp
//
//  Created by Drewry Morris on 6/25/15.
//  Copyright (c) 2015 Drewry Morris. All rights reserved.
//

#include <iostream>
using namespace std;

// enums define a new type of variable!
enum Food
{
    // a variable of type Food can have any of these values
    Fish,
    Bread,
    Apple,
    Orange
};

int main()
{
    cout << "Choose from below: \n 1) Fish\n 2) Bread\n 3) Apple\n 4) Orange\n";
    int choose;
    cin >> choose;
    choose--;
    Food food = Food(choose); // Change the food here
    
    switch( food )
    {
        case Fish:
            cout << "Here fishy fishy fishy" << endl;
            break;
        case Bread:
            cout << "Chomp! Delicious bread!" << endl;
            break;
        case Apple:
            cout << "Mm fruits are good for you" << endl;
            break;
        case Orange:
            cout << "Orange you glad I didn't say banana" << endl;
            break;
        default: // This is where you go in case none of the cases above caught
            cout << "Invalid food" << endl;
            break;
    }
    return 0;
}
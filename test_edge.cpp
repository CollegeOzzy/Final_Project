/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

//do some basic unit testing on edges

#include <iostream>

#include "edge.h"

using std::cout;
using std::endl;

int main() {
    Edge edge1(nullptr, nullptr, 1);
    
    cout << "edge1.get_source(): " << edge1.get_source() << endl;
    cout << "edge1.get_destination(): " << edge1.get_destination() << endl;
    cout << "edge1.get_weight(): " << edge1.get_weight() << endl;

    return 0;
}

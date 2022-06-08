/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

//do some basic unit testing on Graph_nodes

#include <cassert>
#include <iostream>

#include "graph_node.h"

using std::cout;
using std::endl;

//Test node behaviors with one node
void test_new_node_empty_neighbors() {
    cout << "*******************************************************************" << endl;
    cout << "Testing new node with no neighbor edges." << endl;
    string expected_name = "node1";
    int expected_neighors_size = 0;
    string expected_to_string_value = expected_name + ":\n\tneighbor edges: ";



    Graph_node node1(expected_name);

    cout << "node1.get_name(): " << node1.get_name() << endl;
    //cout << "node1.get_name() == expected_name: " << (node1.get_name() == expected_name) << endl;
    assert(node1.get_name() == expected_name);

    cout << "node1.get_neighbors(): " << node1.get_neighbors() << endl;
    //cout << "(node1.get_neighbors()->size() == expected_neighors_size): " << (node1.get_neighbors()->size() == expected_neighors_size) << endl;
    assert(node1.get_neighbors()->size() == expected_neighors_size);

    cout << node1.to_string(", ");
    //cout << "(node1.to_string(\", \") == expected_to_string_value): " <<(node1.to_string(", ") == expected_to_string_value) << endl;
    assert(node1.to_string(", ") == expected_to_string_value);



    cout << endl << endl;
    cout << "*******************************************************************" << endl;
}

//Test node behaviors with two nodes where node two is a neighbor of node 1.
void test_new_node_with_one_neighbor() {
    cout << "*******************************************************************" << endl;
    cout << "Testing new node with one neighbor edge." << endl;



    Graph_node node1("node1");
    Graph_node node2("node2");

    node1.add_neighbor(&node2, 42);

    cout << "node1.get_name(): " << node1.get_name() << endl;
    cout << "node1.get_neighbors(): " << node1.get_neighbors() << endl;
    cout << node1.to_string(", ");
    cout << endl << endl;

    cout << "node2.get_name(): " << node2.get_name() << endl;
    cout << "node2.get_neighbors(): " << node2.get_neighbors() << endl;
    cout << node2.to_string(", ");



    cout << endl << endl;
    cout << "*******************************************************************" << endl;
}

//Test node behaviors with three nodes where node two and node three are neighbors of node 1.
void test_new_node_with_two_neighbors() {
    cout << "*******************************************************************" << endl;
    cout << "Testing new node with two neighbor edges." << endl;



    Graph_node node1("node1");
    Graph_node node2("node2");
    Graph_node node3("node3");

    node1.add_neighbor(&node2, 42);
    node1.add_neighbor(&node3, 84);

    cout << "node1.get_name(): " << node1.get_name() << endl;
    cout << "node1.get_neighbors(): " << node1.get_neighbors() << endl;
    cout << node1.to_string(", ");
    cout << endl << endl;

    cout << "node2.get_name(): " << node2.get_name() << endl;
    cout << "node2.get_neighbors(): " << node2.get_neighbors() << endl;
    cout << node2.to_string(", ");
    cout << endl << endl;

    cout << "node3.get_name(): " << node3.get_name() << endl;
    cout << "node3.get_neighbors(): " << node3.get_neighbors() << endl;
    cout << node3.to_string(", ");



    cout << endl << endl;
    cout << "*******************************************************************" << endl;
}

int main() {
    test_new_node_empty_neighbors();
    test_new_node_with_one_neighbor();
    test_new_node_with_two_neighbors();

    return 0;
}

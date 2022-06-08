/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

#include <iostream>

#include "graph_node.h"

//Create a new empty Graph_node.
//Graph_node::Graph_node() {}

//Create a new Graph_node with a name and an empty set of neighbors.
Graph_node::Graph_node(string new_name) {
    name = new_name;
    neighbors = new vector<Edge *>();
}

Graph_node::~Graph_node() {
    /*
    for(int i = 0; i < neighbors->size(); ++i) {
        delete neighbors->at(i);
    }
    delete neighbors;
    */
    vector<Edge *>::iterator it;
    for(it = neighbors->begin(); it != neighbors->end(); ++it) {
        delete *it;
    }

}

//Create a new Graph_node with a name and a set of neighbors.
//Graph_node(string new_name, vector<Edge *> new_neighbors);

//Return name of this Graph_node.
string Graph_node::get_name() {
    return name;
}

//Return this node's neighbors.
vector<Edge *> *Graph_node::get_neighbors() {
    return neighbors;
}

//Return number of edges that this node has.
int Graph_node::get_edge_count() {
    return neighbors->size();
}

//Take a node and a weight, construct an Edge, and add that Edge to the neighbors list.
void Graph_node::add_neighbor(Graph_node *new_node, int weight) {
    Edge *new_edge = new Edge(this, new_node, weight);

    neighbors->push_back(new_edge);
}

//strongly inspired by: https://www.geeksforgeeks.org/different-ways-to-print-elements-of-vector/#:~:text=a%20separator%20string-,void%20with_separator(const%20vector%3CS%3E%26%20vec%2C,%7D,-//%20Driver%20Code
//Represent this graph node as a string, showing name and neighbor info.
string Graph_node::to_string(string sep) {
    string result = name + ":\n\tneighbor edges: ";
    // Iterating over all elements of vector
    for (auto elem : *neighbors) {
        result += elem->to_string() + sep;
    }

    return result;
}

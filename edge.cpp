/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

#include "edge.h"

//Edge::Edge();
Edge::Edge(Graph_node *new_source, Graph_node *new_destination, int new_weight) {
    source = new_source;
    destination = new_destination;
    weight = new_weight;
}

Graph_node *Edge::get_source() {
    return source;
}

Graph_node *Edge::get_destination() {
    return destination;
}

int Edge::get_weight() {
    return weight;
}

string Edge::to_string() {
    return "(" + source->get_name() + ", " + destination->get_name() + ", " + std::to_string(weight) + ")";
}

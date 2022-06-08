/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

#include <cassert>
#include <iostream>
#include <vector>

#include "Graph.h"

using std::cout;
using std::endl;
using std::vector;

void test_default_graph_name() {
    string expected_graph_name = "default graph name";
    Graph *my_graph = new Graph;

    assert(my_graph->get_name() == expected_graph_name);
}

void test_add_node_with_default_name() {
    string expected_node_name = "default node name";
    
    Graph *my_graph = new Graph("graph");

    my_graph->add_node();

    vector<Graph_node *> *nodes = my_graph->get_nodes();
    Graph_node *first_node = nodes->at(0);
    string actual_node_name = first_node->get_name();
    //string actual_node_name = my_graph->get_nodes()->at(0)->get_name();

    assert(actual_node_name == expected_node_name);
}

int main() {
    test_default_graph_name();
    test_add_node_with_default_name();
}
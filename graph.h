/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/
#pragma once

#include <string>
#include <vector>

#include "Graph_node.h"

using std::string;
using std::vector;

class Graph {
    private:
        string name;
        vector<Graph_node *> *nodes;

    public:
        Graph(string new_name="default graph name");
        ~Graph();
        string get_name();
        void add_node(string new_name="default node name");
        void add_edge(string source_node_name, string destination_node_name, int weight=1);
        vector<Graph_node *> *get_nodes();
        int get_node_count();
        int get_edge_count(); //more complicated, but just a little
        string to_string(); // utilize knowledge that graph_nodes know how to represent their selves as a string already
        string shortest_path(Graph* graph, string source_node, string destination_node);
};
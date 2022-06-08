/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

#pragma once

#include <string>
#include <vector>

#include "edge.h"

using std::string;
using std::vector;

class Edge;

class Graph_node {
    private: 
        string name;
        vector<Edge *> *neighbors;

    public:
        //Graph_node();
        Graph_node(string new_name);
        //Graph_node(string new_name, vector<Edge *> *new_neighbors);
        ~Graph_node();

        string get_name();
        vector<Edge *> *get_neighbors();
        int get_edge_count();

        void add_neighbor(Graph_node *new_node, int weight);

        string to_string(string sep=" ");
};
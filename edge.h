/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/

#pragma once

#include "graph_node.h"

class Graph_node;

class Edge {
    private:
        Graph_node *source;
        Graph_node *destination;
        int weight;

    public:
        //Edge();
        Edge(Graph_node *new_source, Graph_node *new_destination, int new_weight);

        Graph_node *get_source();
        Graph_node *get_destination();
        int get_weight();

        std::string to_string();
};
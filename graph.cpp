/*
Many of these files were provided by Joseph Jess as part of their CS 260 course at Linn Benton Community College
I edited some of it for final project requirement but I credit Joseph Jess for a vast majority of the work
*/
#include "graph.h"

#include <iostream>
using std::cout;
using std::endl;

Graph::Graph(string new_name) {
    name = new_name;
    nodes = new vector<Graph_node *>;
}

Graph::~Graph() {
    // delete internal Graph_nodes created dynamically!
    vector<Graph_node *>::iterator it;
    for(it = nodes->begin(); it != nodes->end(); ++it) {
        delete *it;
    }
    // finally delete the nodes vector.
    delete nodes;
}

//Return the name of this graph.
string Graph::get_name() {
    return name;
}

//Add a new node into the graph.
void Graph::add_node(string new_name) {
    Graph_node *new_node = new Graph_node(new_name);
    nodes->push_back(new_node);
}

//Add an edge between two nodes in the graph.
//Thought: Should we do this by node names instead and have the graph find the node!?
void Graph::add_edge(string source_node_name, string destination_node_name, int weight) {
    //find nodes with given names
    Graph_node *source_node = nullptr;
    Graph_node *destination_node = nullptr;

    for(auto node : *nodes) {
        if(node->get_name() == source_node_name){
            source_node = node;
        }

        if(node->get_name() == destination_node_name) {
            destination_node = node;
        }
    }

    //add edge between nodes, if found...
    //check for either node not found!
    if(source_node != nullptr && destination_node != nullptr) {
        source_node->add_neighbor(destination_node, weight);
    }
    //otherwise just leave the function!
}

//Return list of nodes in this graph.
vector<Graph_node *> *Graph::get_nodes() {
    return nodes;
}

//Return number of nodes in this graph.
int Graph::get_node_count() {
    return nodes->size();
}

//Return number of total edges in this graph.
int Graph::get_edge_count() {
    // it's complicated...?
    // get the neighbors count of each node in my graph's node list
    int edge_count = 0;
    for(auto node : *nodes) {
        node->get_edge_count();
    }
    return edge_count;
}

//Return a string representing this graph.
string Graph::to_string() {
    string result = name + ":\n";
    for(auto node : *nodes) {
        result += "\t" + node->to_string() + "\n";
    }
    return result;
}

string Graph::shortest_path(Graph* graph, string source_node, string destination_node) {
    //might make a struct for this but going to brute force based on my design
    // start by initilizing a list of unknown distances
    int shortest_dist_size = graph->get_node_count();
    int infinity = 999;
    vector<int>shortest_dist(shortest_dist_size, infinity);

    //List of Nodes on the graph
    vector<Graph_node *>*vector_of_nodes; 
        vector_of_nodes = graph->get_nodes(); 

    // a list of unchecked nodes
    vector<string> unchecked_nodes;
    for(int i=0; i < vector_of_nodes->size(); i++)
        unchecked_nodes.push_back(vector_of_nodes->at(i)->get_name());

    // a list to track which previous nodes are encountered
    // this will be initialized with the values "unknown"
    vector<string> previous_nodes(shortest_dist_size, "unknown");


    // Go through the list of nodes
    for(int j=0; j < vector_of_nodes->size(); j++){ 
        if(vector_of_nodes->at(j)->get_name() == source_node){
        // Once you match with the source node...
        // update shortest dist of vertex that shares the index 
        // (this might cause problems because of ordering issues but just going to roll with it for a while...)
            shortest_dist.at(j)= 0;

            //Check to see what edges the source node has
            vector<Edge *> *source_node_edges;
            source_node_edges = vector_of_nodes->at(j)->get_neighbors();
            cout << source_node_edges << endl;

            // if the calvulated distance of a vertex is less than the known distance the shortest distance needs updated
            // 
            for(int k=0; k < source_node_edges->size(); k++){ //For every edge on the source node                
                int calc_dist = shortest_dist.at(j) + source_node_edges->at(k)->get_weight();
                // I dont believe this works because we are iterating through a vector of size neighbors..
                // will test in debug...
                // my debugger isn't working... so I guess I just use print statements :(
                if(calc_dist < shortest_dist.at(k)){
                    shortest_dist.at(k) = calc_dist;
                    cout << shortest_dist.at(2) << endl;
                    return "Reached test.";
                }
                
                
                // if(source_node_edges->at(k)->get_destination()->get_name() == destination_node){
                // //     temp_weight = source_node_edges->at(j)->get_weight();
                // // }
                // // else if(j=0)
                // //     temp_weight = source_node_edges->at(j)->get_weight();
                // // else if(source_node_edges->at(j)->get_weight() < temp_weight)
                // //     temp_weight = source_node_edges->at(j)->get_weight();
                // //     source_node = source_node_edges->at(j)->get_destination();
                // }
            }
        }
        else{
            string not_found;
            not_found = "Node not found.";
            return not_found;
        }
    }   
return 0;
}
//Returns a string showing the shortest path.
// string Graph::shortest_path(Graph* graph, Graph_node* source_node, Graph_node* destination_node) {
//     int temp_weight;
//     vector<Graph_node *> *vector_of_nodes;
//     vector_of_nodes = graph->get_nodes();
//     for(int i=0; i < vector_of_nodes->size(); i++){
//         if(vector_of_nodes->at(i) == source_node){
//             for(int j=0; j < vector_of_nodes->size(); j++){
//                 if(vector_of_nodes->at(j) == source_node){
//                     temp_weight = vector_of_nodes->at(j)->
//                 }
//             }
//         }
            
//     }

    
// vector_of_edges = * source_node-> get_neighbors();
// for (auto elem : vector_of_edges){
//     if(elem->get_source() == source_node and elem->get_source() == destination_node){
//         temp_weight = elem->get_weight();
//     }
// }
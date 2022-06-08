#include <iostream>
#include <vector>

#include "Graph.h"

using std::cout;
using std::endl;
using std::vector;

void print(vector <Graph_node *>*const a) {
   cout << "The vector elements are : ";

   for(int i=0; i < a->size(); i++)
   cout << a->at(i) << ' ';
}

int main() {
    // first step is creating the graph...
    Graph *alogorithm_graph = new Graph("alogorithm_graph");
    
    // second step is creating the nodes...
    string vertex_1 = "Vertex 1";
    alogorithm_graph->add_node(vertex_1);
    string vertex_2 = "Vertex 2";
    alogorithm_graph->add_node(vertex_2);
    string vertex_3 = "Vertex 3";
    alogorithm_graph->add_node(vertex_3);
    string vertex_4 = "Vertex 4";
    alogorithm_graph->add_node(vertex_4);
    string vertex_5 = "Vertex 5";
    alogorithm_graph->add_node(vertex_5);
    string vertex_6 = "Vertex 6";
    alogorithm_graph->add_node(vertex_6);

    // testing the 6 nodes...
    string print_graph;
    print_graph = alogorithm_graph->to_string();
    cout << print_graph << endl;
    // it does work which we knew from the test_graph function but I just wanted to make sure in semi-my own way...

    // third step is adding the edges...
    alogorithm_graph->add_edge(vertex_1, vertex_2, 7);
    alogorithm_graph->add_edge(vertex_1, vertex_3, 9);
    alogorithm_graph->add_edge(vertex_1, vertex_6, 14);

    alogorithm_graph->add_edge(vertex_2, vertex_3, 10);
    alogorithm_graph->add_edge(vertex_2, vertex_4, 15);

    alogorithm_graph->add_edge(vertex_3, vertex_4, 11);
    alogorithm_graph->add_edge(vertex_3, vertex_6, 2);

    alogorithm_graph->add_edge(vertex_4, vertex_5, 6);

    alogorithm_graph->add_edge(vertex_5, vertex_6, 9);
    
    // going to test the graph again...
    //string print_graph;
    print_graph = alogorithm_graph->to_string();
    cout << print_graph << endl;

    // vector<Graph_node *> *testing;
    // testing = alogorithm_graph->get_nodes();
    // print(testing);

    //cout << alogorithm_graph->shortest_path(alogorithm_graph, vertex_1, vertex_2) << endl;
}
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct dijstras_table{
    vector<string> vertex_name;
    vector<int> shortest_dist;
    vector<string> previous_vertex;
};

void print(vector<string>const* a) {
   cout << "The vector elements are : ";

   for(int i=0; i < a->size(); i++)
   cout << a->at(i) << ' ';
}

int main(){ 
    int list_of_shortest_dist_size = 6;
    string variable = "";
    vector<string>list_of_shortest_dist(list_of_shortest_dist_size, variable);
    print(&list_of_shortest_dist);

    // dijstras_table table;
    // table.shortest_dist = list_of_shortest_dist;
}
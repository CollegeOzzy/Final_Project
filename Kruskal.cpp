#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// This code was provided from a friend to help me walk through kruskal problem
// heavily influenced from https://www.simplilearn.com/tutorials/data-structure-tutorial/kruskal-algorithm
// Ian D'Arcy a network engineer for motorola

//structure that denotes a weighted edge
struct Edge
{
	int source, destination, weight;
};

//structure that denotes a weighted, undirected and connected graph
struct Graph
{
	int Node, E;
	struct Edge* edge;
};

//allocates memory for storing graph with V vertices and E edges
struct Graph* GenerateGraph(int Node, int E)
{
	struct Graph* graph = (struct Graph*)(malloc(sizeof(struct Graph)));
	graph->Node = Node;
	graph->E = E;
	graph->edge = (struct Edge*)malloc(sizeof( struct Edge));
	return graph;
};

//subset for Union-Find
struct tree_maintainance_set
{
	int parent;
	int rank;
};

//finds the set of chosen element i using path compression
int find_DisjointSet(struct tree_maintainance_set subsets[], int i)
{
    //find root and make root as parent of i
	if (subsets[i].parent != i)
		subsets[i].parent = find_DisjointSet(subsets, subsets[i].parent);
		
return subsets[i].parent;
}

//Creates the Union of two sets
void Union_DisjointSet(struct tree_maintainance_set subsets[], int x, int y)
{
	int xroot = find_DisjointSet(subsets, x);
	int yroot = find_DisjointSet(subsets, y);
    //connecting tree with lowest rank to the tree with highest rank
	if (subsets[xroot].rank < subsets[yroot].rank)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].rank > subsets[yroot].rank)
		subsets[yroot].parent = xroot;
	//if ranks are same, arbitrarily increase the rank of one node
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].rank++;
	}
}

//function to compare edges using qsort() in C programming
int myComp(const void* a, const void* b)
{
	struct Edge* a1 = (struct Edge*)a;
	struct Edge* b1 = (struct Edge*)b;
	return a1->weight > b1->weight;
}

//function to construct MST using Kruskal’s approach
void KruskalMST(struct Graph* graph)
{
	int Node = graph->Node;
	struct Edge
	result[Node]; 
	int e = 0; 
	int i = 0; 

    //sorting all edges
	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);
	
    //memory allocation for V subsets
	struct tree_maintainance_set* subsets = (struct tree_maintainance_set*)malloc(Node* sizeof(struct tree_maintainance_set));

    //V subsets containing only one element
	for (int v = 0; v < Node; ++v) 
	{
	subsets[v].parent = v;
	subsets[v].rank = 0;
	}

    //Edge traversal limit: V-1
	while (e < Node - 1 && i < graph->E) 
	{
		struct Edge next_edge = graph->edge[i++];
		int x = find_DisjointSet(subsets, next_edge.source);
		int y = find_DisjointSet(subsets, next_edge.destination);
		if (x != y) 
		{
			result[e++] = next_edge;
			Union_DisjointSet(subsets, x, y);
		}

	}

    //printing MST
	printf("Edges created in MST are as below: \n");
	int minimumCost = 0;
	for (i = 0; i < e; ++i)	
	{
		printf("%d -- %d == %d\n", result[i].source, result[i].destination, result[i].weight);
		minimumCost += result[i].weight;
	}

	printf("The Cost for created MST is : %d",minimumCost);
	return;
}

int main()
{
	int Node = 4; 
	int E = 6; 
	struct Graph* graph = GenerateGraph(Node, E);
	
    //Creating graph with manual value insertion
	// add edge 0-1
	graph->edge[0].source = 0;
	graph->edge[0].destination = 1;
	graph->edge[0].weight = 2;

	// add edge 0-2
	graph->edge[1].source = 0;
	graph->edge[1].destination = 2;
	graph->edge[1].weight = 4;

	// add edge 0-3
	graph->edge[2].source = 0;
	graph->edge[2].destination = 3;
	graph->edge[2].weight = 4;

	// add edge 1-3
	graph->edge[3].source = 1;
	graph->edge[3].destination = 3;
	graph->edge[3].weight = 3;

	// add edge 2-3
	graph->edge[4].source = 2;
	graph->edge[4].destination = 3;
	graph->edge[4].weight = 1;

	// add edge 1-2
	graph->edge[5].source = 1;
	graph->edge[5].destination = 2;
	graph->edge[5].weight = 2;
	KruskalMST(graph);

	return 0;
}
#include <bits/stdc++.h>
using namespace std;

/*
* A directed graph using adjacency list representation;
* every vertex holds a list of all neighbouring vertices
* that can be reached from it.
*/
class Graph {
public:
	// Construct the graph given the number of vertices...
	Graph(int numVertices);
	// Specify an edge between two vertices
	void addEdge(int from, int to);
	// Call the recursive helper function to count all the
	// paths
	int countPaths(int start, int end, int numVertices);

private:
	int numVertices;
	list<int>* adjacencyList;
	void pathCounter(int current, int destination, int& pathCount,
					 vector<bool>& visited);
};

Graph::Graph(int numVertices)
{
	this->numVertices = numVertices; // unused!!
	// An array of linked lists - each element corresponds
	// to a vertex and will hold a list of neighbours...
	adjacencyList = new list<int>[numVertices];
}

void Graph::addEdge(int from, int to)
{
	adjacencyList[from].push_back(to);
}

int Graph::countPaths(int start, int end, int numVertices)
{
	int pathCount = 0;
	vector<bool> visited(numVertices, false);
	pathCounter(start, end, pathCount, visited);
	return pathCount;
}

/*
* A recursive function that counts all paths from start to
* end. Keep track of the count in the parameter.
*/
void Graph::pathCounter(int current, int destination, int& pathCount,
						vector<bool>& visited)
{
	// If we've reached the destination, then increment
	// the path count...
	visited[current] = true;
	if (current == destination) {
		pathCount++;
	}
	// ...otherwise recurse into all neighbours...
	else {
		for (auto neighbor : adjacencyList[current]) {
			if (!visited[neighbor])
				pathCounter(neighbor, destination, pathCount,
							visited);
		}
	}
	visited[current] = false;
}

// Driver code
int main()
{
	// Create a graph with 5 vertices
	Graph graph(5);
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 4);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 3);
	graph.addEdge(2, 1);
	graph.addEdge(3, 2);
	
	// Function call to count paths from vertex 0 to vertex 4
	cout << graph.countPaths(0, 4, 5);

	return 0;
}

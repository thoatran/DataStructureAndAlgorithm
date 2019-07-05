//Author: Thoa Tran Thi
//ID: s1242006
//Kruskal algorithm implemented in C++
//To implement and run the program, we change the directory to the directory we saved the Kruskal.cpp file and run the following command lines:
//g++ -std=c++11 -o Kruskal.o Kruskal.cpp
//.Kruskal.o
//Just in MacOS
//clang++ -std=c++11 -stdlib=libc++ -Wno-c++98-compat Kruskal.cpp
//./a.out


#include<iostream>
#include <vector>

using namespace std;

typedef pair<int, int> Pair;

struct Graph {
	int Vertex, Edge;
	std::vector < pair<int, Pair> > edges;

	Graph (int Vertex, int Edge) {
		this->Vertex = Vertex;
		this->Edge = Edge;
	}

	//add an edge to the graph
	void addEdge(int u, int v, int weight) {
		edges.push_back({weight, {u, v}});
	}

	int kruskalMST();
};

struct Set {
	int *parent;
	int *rank;
	int n;

	Set(int n) {
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n+1];

		for(int i = 0; i <= n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int findParent(int u) {
		if(u != parent[u])
			parent[u] = findParent(parent[u]);
		return parent[u];
	}

	void unionSet(int x, int y) {
		x = findParent(x); 
		y = findParent(y);

		if(rank[x] > rank[y])
			parent[y] = x;
		else
			parent[x] = y;

		if(rank[x] == rank[y])
			rank[y] ++;

	}
};

int Graph::kruskalMST() {
	int totalWeight = 0;
	sort(edges.begin(), edges.end());

	Set set(Vertex);

	std::vector< pair<int, Pair> >::iterator i;
	for(i = edges.begin(); i != edges.end(); i++) {
		int u = i->second.first;
		int v = i->second.second;
		int setU = set.findParent(u);
		int setV = set.findParent(v);

		if(setU != setV) {
			totalWeight += i->first;
			cout << u << " - " << v << endl;
			set.unionSet(setU, setV);
		}
	}
	return totalWeight;
}

int main() {
	//Input graph
	//V is the number of vertices, E is the number od edges in the graph
	//Function addEdge(int u, int v, int weight) to add the edge from u to v with the cost is value of weight to the graph.
	//The output will be the edges which will be added to the MST following the Kruskal algorithm and the total cost of the MST.
	int V = 7, E = 11; 
    Graph g(V, E); 
    g.addEdge(0, 1, 7); 
    g.addEdge(0, 3, 5); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 3, 9); 
    g.addEdge(1, 4, 7); 
    g.addEdge(2, 4, 5); 
    g.addEdge(3, 5, 6); 
    g.addEdge(3, 4, 15); 
    g.addEdge(4, 5, 8); 
    g.addEdge(4, 6, 9); 
    g.addEdge(5, 6, 11); 
  
    cout << "Edges of MST are \n"; 
    int totalWeight = g.kruskalMST(); 
  
    cout << "\nWeight of MST is " << totalWeight << endl; 
  
    return 0;
}
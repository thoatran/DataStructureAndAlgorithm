//Author: Thoa Tran Thi
//ID: s1242006
//DFS implemented in C++
//Compile and run file:
// g++ -o DFS.o DFS.c
// ./DFS.o
//There is the difference in the index in the C++ programming language(start from 0)and the index in the graph(start from 1) 

#include<iostream>
#include <list>
using namespace std;

class Graph {
    int G;
    list <int> * adj;
    void DFSUtil(int v, bool visited[]); 
    static int time;
    
public:
    Graph(int G);
    void addEdge(int G, int w);
    void DFS(int v);    //v is the starting vertex to traverse the graph
    
};

Graph::Graph(int G){
    this->G = G;
    adj = new list<int>[G];
}

void Graph::addEdge(int G, int w) {
    this->adj[G].push_back(w);
}

void Graph::DFSUtil(int v , bool visited[]) {
	time += 1;
    visited[v] = true;
    cout << "Time: " << time << " to start to discover vertex: " << v + 1 << endl;
    
    list<int>:: iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
    time += 1;
 	cout << "Time: " << time << " to finish dixcovering vertex: " << v + 1 << endl;
}

void Graph::DFS(int v){
	time = 0;
    bool *visited = new bool[G];

    for(int i = 0; i < G; i++){
    	visited[i] = false;
    }
    
    DFSUtil(v, visited);
    
}
int Graph::time = 0;

int main(){
	Graph G(6);
	G.addEdge(0,1);
	G.addEdge(0,3);
	G.addEdge(1,4);
	G.addEdge(3,1);
	G.addEdge(4,3);
	G.addEdge(2,4);
	G.addEdge(2,5);
	G.addEdge(5,5);
	G.DFS(0);            //start traversing from vertex 0(equal to the vertex 1 in the graph)
	return 0;
}
//Author: Thoa Tran Thi
//ID: s1242006
// Dijkstra's algorithm implementation in C++
// To compile and run the file, change the directory to the folder where you saved it and run the following command lines:
// g++ -std=c++11 -o Dijkstra.o Dijkstra.cpp
// ./Dijkstra.o

// Input: Firstly input the number of vertices in the graph and then itput repectively each cells of the weght matrix of the graph.
// Output: each vertex with its own parent vertex and the shortest distance from source vertex to itself 
//         for the source vertex , its parent will be -1 to mark that it is the source one.
//  In the code, set 0 vertex to be the source vertex to start travelling, so change it if you want ( be sure that it is smaller then the number of vertex)

#include <iostream>
#include <queue>
#include <limits>

using namespace std;

const float INFINITE = numeric_limits<float>::max();

struct vertex_t{
	int id;
	float d;
	int parent;
	vertex_t(int id): id(id), d(INFINITE), parent(-1) {}
	void display(){
		cout << "Vertex: " << id << " Parent: " << parent << " Distance: " << d << endl;
	}
};

class Graph{
private:
	vector<vertex_t> vertex_list;
	vector<vector<float>> weight_matrix;
	vector<vector<int>> adj_list;
public:
	Graph(vector<vector<int>> adj_list, vector<vector<float>> weight_matrix): 
	adj_list(adj_list),
	weight_matrix(weight_matrix) 
	{
		for(int i = 0; i < weight_matrix.size(); ++i){
			vertex_list.push_back({i});
		}
	}

	void displaySPT(int src){
		for(auto vertex: vertex_list){
			vertex.display();
		}
	}
	
	void relax(int u, int v){
		if(vertex_list[v].d > vertex_list[u].d + weight_matrix[u][v]){
			vertex_list[v].d = vertex_list[u].d + weight_matrix[u][v];
			vertex_list[v].parent = u;
		}
	}

	void dijsktra(int src) {
		vertex_list[src].d = 0;

		auto comp = [] (vertex_t u, vertex_t v) { return u.d > v.d; };

		priority_queue<vertex_t, vector<vertex_t>, decltype(comp)> 
		q(vertex_list.begin(), vertex_list.end(), comp);

		while(!q.empty()){
			vertex_t top_element = q.top();
			q.pop();
			int u = top_element.id;
			for(auto v : adj_list[u]){
				relax(u, v);
			}
		}
		displaySPT(src);
	}
};


int main(){
	int V;
	cout << "Input the number of vertices: ";
	cin >> V;
	vector<vector<float>> weight_matrix;
	vector<vector<int>> adj_list (V);
	cout << "Input the weght matrix: " << endl;
	for(int i = 0; i < V; ++i){
		vector<float> row;
		for(int j = 0; j < V; ++j){
			float weight;
			cin >> weight;
			row.push_back(weight);

			if(weight != 0.0){
				adj_list[i].push_back(j);
			}
		}
		weight_matrix.push_back(row); 
	}
	Graph g(adj_list, weight_matrix);
	g.dijsktra(0);     //source vertex to travel
}
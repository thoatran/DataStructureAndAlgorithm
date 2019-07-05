//Author: Tran Thi Thoa
//ID: s1242006

//The implementation of Warshall's algorithm in C++
// Input: firstly input the number of rows(equal to the number of columns) in the adjacent matrix
//        then input each cell in that matrix following the rule of the warshall's algorithm
//Output: the transitive closure matrix of the graph
// To compile and run file, run the following command lines
// g++ -std=c++11 -o warshall.o warshall.cpp
// ./warshall.o


#include <iostream>
#include <limits>
#include <vector>

using namespace std;

void displayGraph(vector< vector<int> > G){
	int size = G.size();
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++){
			cout << G[i][j] << "  ";
		}
		cout << endl;
	}
}

vector < vector<int> > warshall(vector< vector<int> > G) {
	int size = G.size();
	vector < vector<int> > D = G;
	for(int i = 0; i < size; i++) {
		vector< vector<int> > D_next = D;
		for(int j = 0; j < size; j++) {
			for(int k = 0; k < size; k++) {
				D_next[j][k] = D[j][k] | (D[j][i] & D[i][k]);
			}
		}
		D = D_next;
	}
	return D;
}

int main() {
	vector< vector<int> > G;
	int size;
	cout << "Number of vertices: ";
	cin >> size;

	for(int i = 0; i < size; i++) {
		vector<int> row;
		for(int j = 0; j < size; j++) {
			int tmp;
			//the first T 
			//if(i == j) or (i,j) belongs to E[G] then T(i,j) = 1
			//else t(i,j) = 0;
			cin >> tmp;
			row.push_back(tmp);
		}
		G.push_back(row);
	}

	vector< vector<int> > T = warshall(G);
	cout << "The transitive closure of the graph is: " << endl;
	displayGraph(T);
}
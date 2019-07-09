//Author: Thoa Tran Thi
//ID: s1242006
// The implementation of Floyd's algorithm in C++
//Input: first input the number of rows (equal to the number of columns) of the weight matrix.
//       Then input the value of each cell in the weight matrix respectively.
//Note: For the vertex(cell) has weight equal to infinite, input “inf” to represent it

//The output will be the APSP matrix D ( the weight matrix of all pairs with the shortest path)
// To implement and run program, run the following command lines:
//g++ -std=c++11 -o floyd.o floyd.cpp
//./floy.o


#include <iostream>
#include <limits>
#include <vector>
#include <sstream>

using namespace std;

const float INF = numeric_limits<float>::max();

vector< vector <float> > floyd(vector< vector<float> > W) {
	vector< vector <float> > D = W;
	int size = W.size();

	for(int i = 0; i < size; i++) {
		vector < vector <float> > D_next = D;

		for(int j = 0; j < size; j++) {
			for(int k = 0; k < size; k++) {
				D_next[j][k] = min(D[j][k], D[j][i] + D[i][k]);
			}
		}
		D = D_next;
	}
	return D;
}

void displayGraph(vector<vector<float>> G){
	int size = G.size();
	for(int i = 0; i < size; ++i){
		for(int j = 0; j < size; ++j)
			cout << G[i][j] << " ";
		cout << endl;
	}
}

int main() {
	vector < vector <float> > W;
	int size;
	cout << "Number of vertices: ";
	cin >> size;
	for(int i = 0; i < size ; i++) {
		vector<float> row;
		for(int j = 0; j < size; j++) {
			string tmp;
			cin >> tmp;
			float value;
			if(tmp == "inf") 
				value = INF;
			else {
				stringstream ss;
				ss << tmp;
				ss >> value;
			}
			row.push_back(value);
		}
		W.push_back(row);
	}

	vector < vector <float> > D = floyd(W);
	cout << "All pairs shortest table: " << endl;
	displayGraph(D);
}

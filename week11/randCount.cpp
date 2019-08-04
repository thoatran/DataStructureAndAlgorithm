//To compile and run the program, run the following command lines:
//            g++ -std=c++11 -o randCount randCount.cpp
//	          ./randCount


#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define M 2147483647
#define A 48271

vector <int> rand1(int n) {
	int x = 53402397;            //seed
	vector <int> randSet;
	for(int i = 0; i < n; i++) {
		x = 65539 * x + 125654;
		if( x < 0) {
			x += M;
			x += 1;
		}

		randSet.push_back(x);
	}
	return randSet;
}

vector <int> rand2(int n) {
	int x = 1;               //seed
	int Q = M / A;
	int R = M % A;
	vector<int> randSet;
	for(int i = 0; i < n; i++) {
		x = A * ( x % Q) - R * ( x / Q);
		if ( x < 0 ){
			x += M;
		}
		randSet.push_back(x);
	} 
	return randSet;
}

vector <int> rand3 (int n) {
	int x = 1;
	int next = 0;
	vector <int> initial;
	initial = rand2(55);
	vector <int> randSet ;
	for(int i = 0; i < n; i++) {
		int j = (next + 31) % 55;
		x = initial[j] - initial[next];
		if ( x < 0 ) {
			x += M;
			x += 1;
		}
		initial[next] = x;
		next = (next + 1) % 55;
		randSet.push_back(x);
	}
	return randSet;
}

//functions to random the numbers from 0 to 1

vector <float> rand1from0to1(int n) {
	int x = 53402397;            //seed
	vector <float> randSet;
	for(int i = 0; i < n; i++) {
		x = 65539 * x + 125654;
		if( x < 0) {
			x += M;
			x += 1;
		}

		randSet.push_back((float)x / M);
	}
	return randSet;
}

vector <float> rand2from0to1(int n) {
	int x = 1;               //seed
	int Q = M / A;
	int R = M % A;
	vector<float> randSet;
	for(int i = 0; i < n; i++) {
		x = A * ( x % Q) - R * ( x / Q);
		if ( x < 0 ){
			x += M;
		}
		randSet.push_back((float)x / M);
	} 
	return randSet;
}

vector <float> rand3from0to1 (int n) {
	float x = 1;
	int next = 0;
	vector <float> initial;
	initial = rand2from0to1(55);
	vector <float> randSet ;
	for(int i = 0; i < n; i++) {
		int j = (next + 31) % 55;
		x = initial[j] - initial[next];
		if ( x < 0 ) {
			x += 1;
			x += 1 / M;
		}
		initial[next] = x;
		next = (next + 1) % 55;
		randSet.push_back(x);
	}
	return randSet;
}

void printListInt (vector<int> V) {
	for(int i = 0; i < V.size(); i++) {
		cout << V[i] << "    ";
	}
	cout << endl;
}

void printListFloat (vector<float> V) {
	for(int i = 0; i < V.size(); i++) {
		cout << V[i] << "    ";
	}
	cout << endl;
}

void countOccurences(vector<float> V, int n) {
	/*
	map <float, float> freqMap;

	sort(V.begin(), V.end());
	freqMap.insert(pair<float, float>(V[0], count(V.begin(), V.end(), V[0])));
	for(int i = 0; i < V.size(); i++) {
		if(V[i] != V[i-1])
			freqMap.insert(pair<float, float>(V[i], count(V.begin(), V.end(), V[i])));
	}

	for(auto i = freqMap.begin(); i != freqMap.end(); i++) {
		cout << i->first << "  :  " << (float)(i->second) / n << endl;
	}
	*/
	cout << "The appearance frequency: " << endl;
	float freq[10];
	for(int i = 0; i < 10; i++) {
		freq[i] = 0;
	}
	for(int i = 0; i < V.size(); i++) {
		if(V[i] >= 0 && V[i] < 0.1)
			freq[0] += (float)1 / n;
		else if(V[i] >= 0.1 && V[i] < 0.2)
			freq[1] += (float)1 / n;
		else if(V[i] >= 0.2 && V[i] < 0.3)
			freq[2] += (float)1 / n;
		else if(V[i] >= 0.3 && V[i] < 0.4)
			freq[3] += (float)1 / n;
		else if(V[i] >= 0.4 && V[i] < 0.5)
			freq[4] += (float)1 / n;
		else if(V[i] >= 0.5 && V[i] < 0.6)
			freq[5] += (float)1 / n;
		else if(V[i] >= 0.6 && V[i] < 0.7)
			freq[6] += (float)1 / n;
		else if(V[i] >= 0.7 && V[i] < 0.8)
			freq[7] += (float)1 / n;
		else if(V[i] >= 0.8 && V[i] < 0.9)
			freq[8] += (float)1 / n;
		else 
			freq[9] += (float)1 / n;
	}
	for(int i = 0; i < 10; i++){
		if(i == 0) 
			cout << "0.0 - 0.1: " << freq[i] << endl;
		else if(i == 1) 
			cout << "0.1 - 0.2: " << freq[i] << endl;
		else if(i == 2) 
			cout << "0.2 - 0.3: " << freq[i] << endl;
		else if(i == 3) 
			cout << "0.3 - 0.4: " << freq[i] << endl;
		else if(i == 4) 
			cout << "0.4 - 0.5: " << freq[i] << endl;
		else if(i == 5) 
			cout << "0.5 - 0.6: " << freq[i] << endl;
		else if(i == 6) 
			cout << "0.6 - 0.7: " << freq[i] << endl;
		else if(i == 7) 
			cout << "0.7 - 0.8: " << freq[i] << endl;
		else if(i == 8) 
			cout << "0.8 - 0.9: " << freq[i] << endl;
		else 
			cout << "0.9 - 1.0: " << freq[i] << endl;
	}
}

int main() {
	//use that part for problem a
	vector<int> randSet1, randSet2, randSet3;
	int n = 5;
	cout << "Rand1 algorithm: " << endl;
	randSet1 = rand1(n);
	printListInt(randSet1);
	cout << "Rand2 algorithm: " << endl;
	randSet2 = rand2(n);
	printListInt(randSet2);
	cout << "Rand3 algorithm: " << endl;
	randSet3 = rand3(n);
	printListInt(randSet3);
	
	//use that part for problem b
	/*
	vector<float> randSet1, randSet2, randSet3;
	int n = 1000000;
	cout << "Rand1: " << endl;
	randSet1 = rand1from0to1(n);
	//printListFloat(randSet1);
	countOccurences(randSet1, n);
	cout << "Rand2: " << endl;
	randSet2 = rand2from0to1(n);
	//printListFloat(randSet2);
	countOccurences(randSet2, n);
	cout << "Rand 3: " << endl;
	randSet3 = rand3from0to1(n);
	//printListFloat(randSet);
	countOccurences(randSet3, n);
	*/
	return 0;
}
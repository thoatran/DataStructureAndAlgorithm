//Author: Thoa Tran Thi
//ID: s1242006
//The Huffman encode tree implemented in C++
//Compile and run by the following command lines:
//            g++ -std=c++11 -o huffman.o huffman.cpp
//            ./huffman.o 
//Input: the text to encode
//Output: The Huffman coding list for the input text.

#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node {
	char key;
	Node *left;
	Node *right;
	int freq;

	Node() : freq(0), left(NULL), right(NULL) {};
	Node(char key, char freq) : key(key), freq(freq), left(NULL), right(NULL) {};
};

map <char, int> constructLetterFrequencyMap(string input) {
	map <char, int> freqMap;

	for(auto letter : input) {
		freqMap[letter] += 1;
	}

	return freqMap;
}

vector<Node *> constructNodeList (map<char, int> freqMap) {
	vector < Node * > nodeList;
	for(auto i = freqMap.begin(); i != freqMap.end(); i ++) {
		Node *freqNode = new Node(i->first, i->second);
		nodeList.push_back(freqNode);
	}

	return nodeList;
}

Node *huffman(vector<Node*> nodeList) {
	auto comparison = [](Node *a, Node *b) {
		return a->freq > b->freq;
	};
	priority_queue<Node *, vector<Node*>, decltype(comparison)> Q(nodeList.begin(), nodeList.end(), comparison);
	int size = nodeList.size();

	for(int i = 0; i < size-1; i++) {
		Node *root = new Node();
		Node *leftChild = Q.top();
		Q.pop();
		Node *rightChild = Q.top();
		Q.pop();

		root->left = leftChild;
		root->right = rightChild;
		root->freq = leftChild->freq + rightChild->freq;
		Q.push(root);
	}
	Node *tree = Q.top();
	Q.pop();
	return tree;
}

void preorderVisit(Node *root, map <char, string> *huffmanEncoder, string bitcode) {
	if(root == NULL) {
		return;
	}

	if(root->left == NULL && root->right == NULL){
		(*huffmanEncoder)[root->key] = bitcode;
	}

	preorderVisit(root->left, huffmanEncoder, bitcode + "0");
	preorderVisit(root->right, huffmanEncoder, bitcode + "1");
}

map <char, string> constructEncodingMap(Node *root) {
	map <char, string> huffmanEncoder;
	preorderVisit(root, &huffmanEncoder, "");
	return huffmanEncoder;
}

string encoding(map <char, string> huffmanEncoder, string input) {
	string encodedtext = "";
	for(auto letter : input) {
		encodedtext += huffmanEncoder[letter];
	}
	return encodedtext;
}

int main() {
	string input;
	cout << "Input text: ";
	getline(cin, input);

	map<char, int> freqMap = constructLetterFrequencyMap(input);

	vector<Node *> nodeList = constructNodeList(freqMap);

	cout << "Frequency of letters in the input text: "<< endl;
	for(auto node : nodeList) {
		cout << node->key <<"  :  "<< node->freq << endl;
	}

	Node *tree = huffman(nodeList);
	map<char, string>huffmanEncoder = constructEncodingMap(tree);
	cout << "Huffman encode list for the input: " << endl;
	for(auto i = huffmanEncoder.begin(); i != huffmanEncoder.end(); i++) {
		cout << i->first <<"  :  "<< i->second << endl;
	}

	return 0;
}
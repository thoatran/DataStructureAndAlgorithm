//To compile and run the file, run the following cammand lines:
//         g++ -std=c++11 -o eightQueensProb eightQueensProb.cpp 
//         ./eightQueensProb 

#include <iostream>

using namespace std;

#define N 8          //Change this value to change number of queens

void printSolution(int board[N][N]) 
{ 
	static int k = 1; 
	cout << "Solution "<< k <<"-th:"<< endl;
	k ++;
	for (int i = 0; i < N; i++) 
	{ 
		for (int j = 0; j < N; j++) 
			if(board[i][j] == 1)
				cout << "  Q  ";
			else
				cout << "  _  ";
		cout << endl;
	} 
	cout <<"_______________________________________________" << endl;
} 

bool isSafe(int board[N][N], int row, int col) { 
	/* Check this row on left side */
	for (int i = 0; i < col; i++) 
		if (board[row][i]) 
			return false; 

	/* Check upper diagonal on left side */
	for (int i=row, j=col; i>=0 && j>=0; i--, j--) 
		if (board[i][j]) 
			return false; 

	/* Check lower diagonal on left side */
	for (int i=row, j=col; j>=0 && i<N; i++, j--) 
		if (board[i][j]) 
			return false; 

	return true; 
} 

bool solveNQUtil(int board[N][N], int col) { 
	if (col == N) 
	{ 
		printSolution(board); 
		return true; 
	} 
	bool res = false; 
	for (int i = 0; i < N; i++) 
	{ 
		/* Check if queen can be placed on 
		board[i][col] */
		if ( isSafe(board, i, col) ) 
		{ 
			board[i][col] = 1; 
			res = solveNQUtil(board, col + 1) || res; 

			board[i][col] = 0; // BACKTRACK 
		} 
	} 
	return res; 
} 

void solveNQ() 
{ 
	int board[N][N]; 
	memset(board, 0, sizeof(board)); 

	if (solveNQUtil(board, 0) == false) 
	{ 
		cout << "Solution does not exist" << endl; 
		return ; 
	} 

	return ; 
} 

int main() 
{ 
	solveNQ(); 
	return 0; 
} 
//To compile and run the program, run the follơing command lines:
//            g++ -std=c++11 -o matrixChainMultiplication matrixChainMultiplication.cpp 
//            ./matrixChainMultiplication 

#include <iostream>
#include <limits>

using namespace std; 

void printParenthesis(int i, int j, int n, int *s, char &name) { 
	if (i == j) { 
		cout << name++; 
		return; 
	} 

	cout << "("; 
	printParenthesis(i, *((s+j*n)+i), n, s, name); 
	printParenthesis(*((s+j*n)+i) + 1, j, n, s, name); 
	cout << ")"; 
} 

void matrixChainOrder(int p[], int n) { 
	int m[n][n]; 
	// cost is zero when multiplying one matrix. 
	for (int i=1; i<n; i++) 
		m[i][i] = 0; 

	// L is chain length. 
	for (int L=2; L<n; L++) { 
		for (int i=1; i<n-L+1; i++) { 
			int j = i+L-1; 
			m[i][j] = INT_MAX; 
			for (int k=i; k<=j-1; k++) { 
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]; 
				if (q < m[i][j]) { 
					m[i][j] = q; 
					m[j][i] = k; 
				} 
			} 
		} 
	} 

	for(int i = 0; i < n; i++) {
		for (int j = 0; j < n ; j++) {
			printf("%10d", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	// The first matrix is printed as 'A', next as 'B', so on
	char name = 'A'; 
	cout << "Optimal Parenthesization is: "; 
	printParenthesis(1, n-1, n, (int *)m, name); 
	cout << "\nOptimal Cost is : " << m[1][n-1] << endl; 
} 

int main() { 
	int arr[] = {100, 10, 100, 1, 1000, 100};      //change this value to chnage the size ò the initial matrices
	int n = sizeof(arr)/sizeof(arr[0]); 
	matrixChainOrder(arr, n); 
	return 0; 
} 

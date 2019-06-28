//Author:Thoa Tran Thi
//ID: s1242006
//Implement Heap Bottom Up algorithm in C programing language
//To run this program, open terminal and change the directory to the folder where you saved this file
//Run the following command line
//        gcc -o heap.o heap.c
//        ./heap.o


#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b);
void maxHeapify(int a[], int n, int i);
void HeapBottomUp(int a[], int n);

int main(){
	int n;
	printf("Input the number of elements in the array: ");
	scanf("%d",&n);
	int a[n];
	for(int i = 0; i < n; i++) {
		printf("Input the %d-th element: ", i + 1);
		scanf("%d", &a[i]);
	}
	HeapBottomUp(a,n);
	printf("The output heap: \n");
	for(int i = 0; i < n; i++)
		printf("%d  ", a[i]);
	return 0;
}

void swap (int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void maxHeapify(int a[], int n, int i) {
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int tmp = i;

	if(left < n && a[left] > a[tmp])
		tmp = left;
	if(right < n && a[right] > a[tmp])
		tmp = right;
	if(tmp != i) {
		swap(&a[i], &a[tmp]);
		maxHeapify(a,n,tmp);
	}
}

void HeapBottomUp(int a[], int n) {
	for(int i = n/2-1; i >= 0; i-- )
		maxHeapify(a,n,i);
}

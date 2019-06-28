#include <stdio.h>

void merge(int a[], int left, int mid, int right);
void mergeSort(int a[], int left, int right);

int main()
{
	int n;   //size of the array
	printf("Input n: ");
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; i++) {
		printf("Input the %d-th element: ",i+1);
		scanf("%d", &arr[i]);
	}
	//int n = sizeof(arr)/sizeof(arr[0]); 
	mergeSort(arr, 0, n-1);
	printf("The sorted array: ");
	for(int i = 0; i < n; i++){
		printf("%d  ", arr[i]);
	}
	return 0;

}

void merge(int arr[], int left, int mid, int right) 
{ 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    /* Merge the temp arrays back */
    i = 0;     
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 
        int mid = left+(right-left)/2; 
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid+1, right); 
        merge(arr, left, mid, right); 
    } 
} 
#include <iostream> 
#include <chrono>
#include <random>

using namespace std; 
using namespace std::chrono; 


int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[low]; // pivot 
    int i = high ; 
  
    for (int j = high - 1; j >= low + 1; j--) { 
 
        if (arr[j] > pivot) { 
  
            i--;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i - 1], arr[low]); 
    return (i - 1); 
} 
  
int partition_r(int arr[], int low, int high) 
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random], arr[low]); 
  
    return partition(arr, low, high); 
} 

//quick sort with the first element as pivot
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high - 1) { 

        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi); 
        quickSort(arr, pi + 1, high); 
    } 
} 

//quick sort with random pivot
void quickSort_r(int arr[], int low, int high) 
{ 
    if (low < high - 1) { 
  
        int pi = partition_r(arr, low, high); 
        quickSort_r(arr, low, pi); 
        quickSort_r(arr, pi + 1, high); 
    } 
} 
  
/* Function to print an array */
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << "   "; 
    cout << endl;
} 
  
int main() 
{ 
    cout << "__________________N = 100______________" << endl;
    double duration1 = 0;
    double duration2 = 0;
    for(int i = 0; i < 100; i++){
        int n = 100;
        int arr1[n], arr2[n];
        for(int i = 0; i < n; i ++) {
            arr1[i] = rand() % 1000;
            arr2[i] = arr1[i];
        }
        auto start1 = high_resolution_clock::now();
        quickSort(arr1, 0, n);
        auto stop1 = high_resolution_clock::now(); 
        duration1 += duration_cast<microseconds>(stop1 - start1).count();
        auto start2 = high_resolution_clock::now();
        quickSort_r(arr2, 0, n);
        auto stop2 = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop2 - start2).count();
    }
    cout << "The time for quick sort with the first element as pivot: " << (double)duration1 / 100 << "microseconds" << endl;
    cout << "The time for quick sort with the random element as pivot: " << (double)duration2 / 100 << "microseconds" << endl;
    
///////////////////////////////////////////////////////////
    cout << "__________________N = 1000______________" << endl;
    duration1 = 0;
    duration2 = 0;
    for(int i = 0; i < 100; i++){
        int n = 1000;
        int arr3[n], arr4[n];
        for(int i = 0; i < n; i ++) {
            arr3[i] = rand() % 1000;
            arr4[i] = arr3[i];
        }
        auto start1 = high_resolution_clock::now();
        quickSort(arr3, 0, n);
        auto stop1 = high_resolution_clock::now(); 
        duration1 += duration_cast<microseconds>(stop1 - start1).count();
        auto start2 = high_resolution_clock::now();
        quickSort_r(arr4, 0, n);
        auto stop2 = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop2 - start2).count();
    }
    cout << "The time for quick sort with the first element as pivot: " << (double)duration1 / 100 << "microseconds" << endl;
    cout << "The time for quick sort with the random element as pivot: " << (double)duration2 / 100 << "microseconds" << endl;
    ////////////////////////////////////////

    cout << "__________________N = 10000______________" << endl;
    duration1 = 0;
    duration2 = 0;
    for(int i = 0; i < 100; i++){
        int n = 10000;
        int arr5[n], arr6[n];
        for(int i = 0; i < n; i ++) {
            arr5[i] = rand() % 1000;
            arr6[i] = arr5[i];
        }
        auto start1 = high_resolution_clock::now();
        quickSort(arr5, 0, n);
        auto stop1 = high_resolution_clock::now(); 
        duration1 += duration_cast<microseconds>(stop1 - start1).count();
        auto start2 = high_resolution_clock::now();
        quickSort_r(arr6, 0, n);
        auto stop2 = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop2 - start2).count();
    }
    cout << "The time for quick sort with the first element as pivot: " << (double)duration1 / 100 << "microseconds" << endl;
    cout << "The time for quick sort with the random element as pivot: " << (double)duration2 / 100 << "microseconds" << endl;
    cout << "__________________N = 100000______________" << endl;
    duration1 = 0;
    duration2 = 0;
    for(int i = 0; i < 100; i++){
        int n = 100000;
        int arr7[n], arr8[n];
        for(int i = 0; i < n; i ++) {
            arr7[i] = rand() % 1000;
            arr8[i] = arr7[i];
        }
        auto start1 = high_resolution_clock::now();
        quickSort(arr7, 0, n);
        auto stop1 = high_resolution_clock::now(); 
        duration1 += duration_cast<microseconds>(stop1 - start1).count();
        auto start2 = high_resolution_clock::now();
        quickSort_r(arr8, 0, n);
        auto stop2 = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop2 - start2).count();
    }
    cout << "The time for quick sort with the first element as pivot: " << (double)duration1 / 100 << "microseconds" << endl;
    cout << "The time for quick sort with the random element as pivot: " << (double)duration2 / 100 << "microseconds" << endl;
    cout << "__________________N = 1000000______________" << endl;
    duration1 = 0;
    duration2 = 0;
    for(int i = 0; i < 100; i++){
        int n = 1000000;
        int arr9[n], arr10[n];
        for(int i = 0; i < n; i ++) {
            arr9[i] = rand() % 1000;
            arr10[i] = arr9[i];
        }
        auto start1 = high_resolution_clock::now();
        quickSort(arr9, 0, n);
        auto stop1 = high_resolution_clock::now(); 
        duration1 += duration_cast<microseconds>(stop1 - start1).count();
        auto start2 = high_resolution_clock::now();
        quickSort_r(arr10, 0, n);
        auto stop2 = high_resolution_clock::now(); 
        duration2 += duration_cast<microseconds>(stop2 - start2).count();
    }
    cout << "The time for quick sort with the first element as pivot: " << (double)duration1 / 100 << "microseconds" << endl;
    cout << "The time for quick sort with the random element as pivot: " << (double)duration2 / 100 << "microseconds" << endl;
    

    return 0; 
} 
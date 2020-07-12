#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 

    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


void printArray(int A[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

void mergeSort(int arr[], int l, int r, int side) { 
    if (l < r) { 
        int c = (r + l) / 2; 
  
        mergeSort(arr, l, c, 1); 
        mergeSort(arr, c + 1, r, 2); 
        merge(arr, l, c, r); 
    } 
}
  
int main() 
{ 
    // int arr_size = 1000; 
    // int arr_size = 10000; 
    // int arr_size = 100000; 
    int arr_size = 1000000; 
    int arr[arr_size]; 

    for(int i=0;i<arr_size;i++){
        arr[i] = rand() % arr_size + 1;
    }
  
    int start_s = clock();
    mergeSort(arr, 0, arr_size - 1, 0); 
    int stop_s = clock();
    int time = (stop_s - start_s) / double(CLOCKS_PER_SEC) * 1000;

    printf ("\n Running time: %d ms \n", time);


    return 0; 
} 



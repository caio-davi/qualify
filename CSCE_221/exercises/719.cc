#include <bits/stdc++.h> 
using namespace std;  
  
void printArray(int arr[], int size){  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  

void swap(int* a, int* b){  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
  
int partition (int arr[], int low, int high, int side){  
    cout << "low: " << low << " high: " << high << "\n";
    int med = low + ((high-low)/2);

    int pivot = arr[med];
    cout << "pivot: " << pivot << "\n";
    // int pivot = arr[high];
    int less = (low-1) ;
    int more = (high +1);
    int same = med;
    for (int i = med+1; i <= high - 1; i++){  
        if (arr[i] < pivot){  
            less++; 
            swap(&arr[i], &arr[less]);  
        }
    }
    for (int i = low; i <= high - 1; i++){  
        if(i < med && arr[i] == pivot){
            same++;
            swap(&arr[i], &arr[same]);  
        }
        if(i < med && arr[i] > pivot){
            more--;
            swap(&arr[i], &arr[more]);
        }
    }
    cout << "med: " << med << "\n";

        return same;  

}  

void quickSort(int arr[], int low, int high, int side){  
        printArray(arr, 15);
    if (low < high){
        int pivot = partition(arr, low, high, side);
        quickSort(arr, low, pivot - 1, 0);  
        quickSort(arr, pivot + 1, high, 1);
    }  
}  
  

  
int main()  
{  
    int arr[] = {10, 7, 8, 8, 1, 2, 3, 12, 14, 15, 16, 2, 4, 7, 90};  
    int n = sizeof(arr) / sizeof(arr[0]);  
    quickSort(arr, 0, n - 1, 0);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    return 0;  
}  
#include <stdio.h> 
#include <stdlib.h> 
void maxHeapify(int arr[], int n, int i) 
{ 
int largest = i; 
int left = 2 * i + 1; 
int right = 2 * i +2; 
if (left < n && arr[left] > arr[largest]) 
largest = left; 
if (right < n && arr[right] > arr[largest]) 
largest = right; 
if (largest != i) 
{ 
int temp = arr[i]; 
arr[i] = arr[largest]; 
arr[largest] = temp; 
maxHeapify(arr, n, largest); 
}
} 
void buildMaxHeap(int arr[], int n) 
{ 
for (int i = n / 2 - 1; i >= 0; i--) 
maxHeapify(arr, n, i); 
} 
void minHeapify(int arr[], int n, int i) 
{ 
int smallest = i; 
int left = 2 * i + 1; 
int right = 2 * i +2; 
if (left < n && arr[left] < arr[smallest]) 
smallest = left; 
if (right < n && arr[right] < arr[smallest]) 
smallest = right; 
if (smallest != i) 
{ 
int temp = arr[i]; 
arr[i] = arr[smallest]; 
arr[smallest] = temp; 
minHeapify(arr, n, smallest); 
} 
} 
void buildMinHeap(int arr[], int n) 
{ 
for (int i = n / 2 - 1; i >= 0; i--) 
minHeapify(arr, n, i); 
} 
void printArray(int arr[], int n) 
{ 
for (int i = 0; i < n; ++i) 
printf("%d ", arr[i]); 
printf("\n"); 
} 
void main()
{ 
int n; 
printf("Enter the number of elements in the array: "); 
scanf("%d", &n); 
int arr[n]; 
printf("Enter the elements of the array: "); 
for (int i = 0; i < n; ++i) 
scanf("%d",&arr[i]); 
buildMaxHeap(arr, n); 
printf("Max-Heap: "); 
printArray(arr, n); 
buildMinHeap(arr, n); 
printf("Min-Heap: "); 
printArray(arr, n); 
} 
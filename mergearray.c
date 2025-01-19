#include <stdio.h>
void merge(int *,int *,int,int,int *);
void display(int *, int);
void Sort(int *, int);

void main() 
{
int n1, n2;
printf("Enter the size of first array: ");
scanf("%d", &n1);
int A[n1];
printf("Enter elements of the first array:\n");
for (int i = 0; i < n1; i++) 
{
scanf("%d", &A[i]);
}
printf("\nArray:\n");
display(A,n1);
Sort(A,n1);
printf("\nArray (after sorting):\n");
display(A,n1);


printf("Enter the size of second array: ");
scanf("%d", &n2);
int B[n2];
printf("Enter elements of the second array:\n");
for (int i = 0; i < n2; i++) 
{
scanf("%d", &B[i]);
}
printf("\nArray:\n");
display(B,n2);
Sort(B,n2);
printf("\nArray (after sorting):\n");
display(B,n2);

int n3=n1+n2;
int C[n3];
merge(A, B, n1, n2, C);

printf("\nMerged Array:\n");
display(C,n3);
}


void merge(int *A, int *B, int n1, int n2, int *C) 
{
int i = 0, j = 0, k = 0;
while (i < n1 && j < n2) 
{
if (A[i] < B[j]) 
{
C[k] = A[i];
i++;
} 
else if (A[i] > B[j]) 
{
C[k] = B[j];
j++;
} 
else
{
C[k] = A[i];  
i++;
k++;
C[k] = B[j];  
j++;
}
k++;
}

    
while (i < n1) 
{
C[k] = A[i];
i++;
k++;
}

while (j < n2) 
{
C[k] = B[j];
j++;
k++;
}
}


void display(int *arr, int size) 
{
for (int i = 0; i < size; i++) 
{
printf("%d ", arr[i]);
}
printf("\n");
}


void Sort(int *arr, int size) 
{
int temp;
for (int i = 0; i < size - 1; i++) 
{
for (int j = 0; j < size - i - 1; j++) 
{
if (arr[j] > arr[j + 1]) 
{
temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}
}

#include <stdio.h> 
#include <stdlib.h> 
#define MAX_ELEMENTS 1000 
typedef struct Set 
{ 
int parent; 
int rank; 
} Set; 
Set sets[MAX_ELEMENTS]; 
int numElements; 
void initSets() 
{ 
int i; 
for (i = 0; i<numElements; i++) 
{ 
sets[i].parent = i; 
sets[i].rank = 0; 
}
} 
int find(int element) 
{ 
if (sets[element].parent != element) 
{ 
sets[element].parent = find(sets[element].parent); // Path compression 
} 
return sets[element].parent; 
} 
void unionSets(int element1, int element2) 
{ 
int set1 = find(element1); 
int set2 = find(element2); 
if (set1!= set2) 
{ 
if (sets[set1].rank> sets[set2].rank) 
{ 
sets[set2].parent = set1; 
} 
else if (sets[set1].rank< sets[set2].rank) 
{ 
sets[set1].parent = set2; 
} 
else 
{ 
sets[set2].parent = set1; 
sets[set1].rank++; 
}
}
} 
void displaySets() 
{ 
int i; 
printf("Element:\t"); 
for (i = 0; i<numElements; i++) 
{ 
printf("%d\t", i);
} 
printf("\nParent:\t"); 
for (i = 0; i<numElements; i++) 
{ 
printf("%d\t", sets[i].parent); 
} 
printf("\nRank:\t"); 
for (i = 0; i<numElements; i++) { 
printf("%d\t", sets[i].rank); 
} 
printf("\n\n"); 
} 
int main() 
{ 
int i; 
numElements = 6; 
initSets(); 
displaySets(); 
unionSets(0, 1); 
unionSets(1, 2); 
unionSets(3, 4); 
unionSets(4, 5); 
unionSets(2, 4); 
displaySets(); 
for (i = 0; i<numElements; i++) 
{ 
printf("The representative element of element %d is %d\n", i, find(i)); 
} 
return 0; 
} 

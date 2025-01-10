#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* left;
struct node* right;
};
struct node* create(int item)
{
struct node* temp = (struct node*)malloc(sizeof(struct node)); 
temp->data = item;  
temp->left = NULL;
temp->right = NULL;
return temp;
}

struct node* insertnode(struct node* root, int item);
struct node* deletenode(struct node* root, int value); 
struct node* inorderpredecessor(struct node* root);
void inorder(struct node* root);
void preorder(struct node* root);
void postorder(struct node* root);
void main()
{
int ch,item,value;
struct node* root = NULL;
do
{
printf("Binary Search Tree Operations\n1.Insert a Node\n2.Delete a Node\n3.In-order Traversal\n4.Pre-order Traversal\n5.Post-order Traversal\n6.Exit\n");
printf("choose an operation:\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
printf("Enter item for new node: ");
scanf("%d", &item);
root = insertnode(root, item);
printf("value inserted\n");
break;
}
case 2:
{
if(root==NULL) 
{ 
printf("Tree is empty\n");  
}
else 
{  
printf("Enter value to delete: ");
scanf("%d", &value);
root = deletenode(root, value);
printf("value deleted\n");
}
break;
}
case 3:
{
if(root==NULL) 
{ 
printf("Tree is empty\n");  
}
else 
{  
printf("In Order Traversal\n");  
inorder(root); 
printf("\n");
}
break;
}
case 4:
{
if(root==NULL) 
{ 
printf("Tree is empty\n");  
}
else 
{
printf("Pre Order Traversal\n");    
preorder(root); 
printf("\n");
}
break;
}
case 5:
{
if(root==NULL) 
{ 
printf("Tree is empty\n");  
}
else 
{ 
printf("Post Order Traversal\n");   
postorder(root); 
printf("\n");
}
break;
}
case 6:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=6);
}

struct node* insertnode(struct node* root, int item) 
{
if (root == NULL) 
{
return create(item);
}
if (item < root->data) 
{
root->left = insertnode(root->left, item);
} 
else 
{
root->right = insertnode(root->right, item);
}
return root;
}


struct node* inorderpredecessor(struct node* root) 
{
root = root->left;
while (root->right != NULL) 
{
root = root->right;
}
return root;
}


struct node* deletenode(struct node* root, int value) 
{
if (root == NULL) 
{
printf("Node not found\n");
return root;
}

struct node* temp;
if (value < root->data) 
{
root->left = deletenode(root->left, value);
}
else if (value > root->data) 
{
root->right = deletenode(root->right, value);
}
else 
{
if (root->left == NULL && root->right == NULL) 
{
free(root);
return NULL;
}
else if (root->left == NULL) 
{
temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL) 
{
temp = root->left;
free(root);
return temp;
}
else 
{
temp = inorderpredecessor(root);
root->data = temp->data;
root->left = deletenode(root->left, temp->data);
}
}
return root;
}


void inorder(struct node* root)
{
if(root == NULL) return;
inorder(root->left);
printf("%d\t", root->data);
inorder(root->right);
}

void preorder(struct node* root)
{
if(root == NULL) return;
printf("%d\t", root->data);
preorder(root->left);
preorder(root->right);
}

void postorder(struct node* root)
{
if(root == NULL) return;
postorder(root->left);
postorder(root->right);
printf("%d\t", root->data);
}










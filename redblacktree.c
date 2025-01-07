#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node* parent;
struct node* left;
struct node* right;
int color; // red=1 black=0
};
struct node* create(int item)
{
struct node* temp = (struct node*)malloc(sizeof(struct node)); 
temp->data = item;  
temp->parent = NULL;
temp->left = NULL;
temp->right = NULL;
temp->color = 1;
return temp;
}

struct node* insertnode(struct node* root, int item);
struct node* leftrotate(struct node* x); 
struct node* rightrotate(struct node* x); 
void inorder(struct node* root);
void main()
{
int ch,item,value;
struct node* root = NULL;
do
{
printf("Red Black Tree Operations\n1.Insert a new node\n2.Left rotate\n3.Right rotate\n4.Inorder traversal\n5.Exit\n");
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
leftrotate(root);
break;
}
case 3:
{
rightrotate(root);
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
printf("In Order Traversal\n");  
inorder(root); 
printf("\n");
}
break;
}
case 5:printf("exit\n");
break;
default:printf("enter correct value\n\n");
break;
}
}while(ch!=6);
}

void insertnode(struct node* root, int data) 
{
struct node* node = create(data);
struct node* y = NULL;
struct node* x = root;
    
while (x != TNULL) 
{
y = x;
if (node->data < x->data) 
{
x = x->left;
} 
else 
{
x = x->right;
}
}
node->parent = y;
if (y == NULL) 
{
root = node;
} 
else if (node->data < y->data) 
{
y->left = node;
} 
else 
{
y->right = node;
}
node->left = NULL;
node->right = NULL;
node->color = 1; // New nodes are red
    
root=fixInsert(root, node);
return root;
}

struct node* fixInsert(struct node* root, struct node* k) 
{
    struct node* u;
    while (k->parent->color == 1) {
        if (k->parent == k->parent->parent->right) {
            u = k->parent->parent->left;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->left) {
                    k = k->parent;
                    rightRotate(root, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                leftRotate(root, k->parent->parent);
            }
        } else {
            u = k->parent->parent->right;
            if (u->color == 1) {
                u->color = 0;
                k->parent->color = 0;
                k->parent->parent->color = 1;
                k = k->parent->parent;
            } else {
                if (k == k->parent->right) {
                    k = k->parent;
                    leftRotate(root, k);
                }
                k->parent->color = 0;
                k->parent->parent->color = 1;
                rightRotate(root, k->parent->parent);
            }
        }
        if (k == *root) break;
    }
    (root)->color = 0;
return root;
}




struct node* leftrotate(struct node* x) 
{
struct node* y = x->right;
x->right = y->left;
    
if (y->left != NULL) 
{
y->left->parent = x;
}
    
y->parent = x->parent;
    
if (x->parent == NULL) 
{
*root = y;
} 
else if (x == x->parent->left) 
{
x->parent->left = y;
} 
else 
{
x->parent->right = y;
}
    
y->left = x;
x->parent = y;

return x;
}

struct node* rightrotate(struct node* x) 
{
struct node* y = x->left; 
x->left = y->right; 
    
if (y->right != NULL) 
{
y->right->parent = x;
}
    
y->parent = x->parent; 
    
if (x->parent == NULL) 
{
root = y;
} 
else if (x == x->parent->right) 
{
x->parent->right = y;
}
else
{
x->parent->left = y;
}
    
y->right = x; 
x->parent = y; 
    
return x; 
}


void inorder(struct node* root)
{
if(root == NULL) return;
inorder(root->left);
printf("%d\t", root->data);
inorder(root->right);
}











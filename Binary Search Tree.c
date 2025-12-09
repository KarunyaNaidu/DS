#include<stdio.h>
#include<stdlib.h>

typedef struct node {
int data;
struct node *left;
struct node *right;
}node;
node *root=NULL;
node *create(int value)
{
   node *newnode=(node*)malloc(sizeof(node));
   newnode->data=value;
   newnode->right=newnode->left=NULL;
   return newnode;
}
void insert(node root,int value)
{
    if(root==NULL)
    {
        root=create(value);
    }
    if(value<root->data)
    {
        if(root->left!=NULL)
        {
            insert(root->left,value);
        }
        else
            root->left=value;
    }
    if(value>root->data)
    {
        if(root->right!=NULL)
        {
            insert(root->right,value);
        }
        else
            root->right=value;
    }
}
void preorder(node root)
{
    if(root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(node root)
{
if(roort!=NULL)
{
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}
}
int main() {
    struct Node* root = NULL;
    int value;

    printf("Enter values to insert into BST (enter -1 to stop):\n");

    while (1) {
        printf("Insert value: ");
        scanf("%d", &value);

        if (value == -1) {
            break;  // exit infinite loop
        }

        root = insert(root, value);
    }

    printf("\n Preorder Traversal: ");
    preorder(root);

    printf("\n Inorder Traversal: ");
    inorder(root);

    return 0;
}

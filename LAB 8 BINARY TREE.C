#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node *root, int val)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->left = newnode->right = NULL;
        return newnode;
    }

    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);

    return root;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct node *root = NULL;
    int n, val, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter node values:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }

    while (1)
    {
        printf("\n1.Preorder\n2.Inorder\n3.Postorder\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: preorder(root); break;
            case 2: inorder(root); break;
            case 3: postorder(root); break;
            case 4: exit(0);
            default: printf("Invalid choice\n");
        }
        printf("\n");
    }
}

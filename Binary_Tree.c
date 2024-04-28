//-------------------------------//
//////// Creating Binary Tree /////
//-------------------------------//

#include <stdio.h>
#include<stdlib.h>

// Define a structure for tree nodes.
struct Node
{    
    int value;    // The value of the node.
    struct Node * left, * right;    // Pointer to the left and right child.
};

// Printing data in Preorder traversal.
void explore (struct Node * root)
{
    if (root != NULL) {
        printf (" %d ", root->value);
        explore (root->left);
        explore (root->right);
    }
}

// Main Function
int main() {
    int i=0, last = 0, current = 0;
    struct Node *root, *pleft, *pright, *list[2000];
    int n = 0;
   
    // Prompt user to enter the root value and create the root node.
    printf ("root value ? ");
    scanf ("%d", &n);
    root = (struct Node *) malloc (sizeof (struct Node));

    root->value = n;
    root->left = NULL;
    root->right = NULL;
    list[0] = root;
    current = 0;
    last = 0;

    // Loop to create the binary tree based on user input.
    while (1)
    {
        if (current > last){
            break;    // Exit the loop if all nodes have been processed.
        }
       // Get value wether nodes data -99
        if (list[current]->value == -99){
            current++; continue;    // Skip the current node if its value is -99 (indicating no node).
        }

        // Create left and right child nodes.
        pleft = (struct Node *) malloc (sizeof (struct Node));
        pright = (struct Node *) malloc (sizeof (struct Node));

        // Prompt user for the left child value.
        printf ("left of %d? ", list[current]->value);    // Storing Left Node value in Binary Tree.
        scanf ("%d", &n);

        pleft->value = n;
        pleft->left = NULL;
        pleft->right = NULL;

        // Prompt user for the right child value.
        printf ("right of %d? ", list[current]->value);    // Storing Right Node value in Binary Tree.
        scanf ("%d", &n);

        pright->value = n;
        pright->left = NULL;
        pright->right = NULL;

        // Assign children to the current node or set to NULL if value is -99.
        if (pleft->value == -99){
            list[current]->left = NULL;
        }
        else{
            list[current]->left = pleft;
        }
        if (pright->value == -99){
            list[current]->right = NULL;
        }
        else {
            list[current]->right = pright;
        }
        
        // Add the children to the list for further processing.
        list[last+1] = pleft;
        list[last+2] = pright;
        last = last + 2;
        current++;
    }

    // Printing Data.
    explore (root);
   
    return 0;
}

/*
This code represnts a Binary Tree .
*/

//-------------------------------//
//////// Creating Binary Tree /////
//-------------------------------//

#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int value;
    struct Node * left, * right;
};

// Printing data in Preorder.
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
   
    //creating the root.
    printf ("root value ? ");
    scanf ("%d", &n);
    root = (struct Node *) malloc (sizeof (struct Node));

    root->value = n;
    root->left = NULL;
    root->right = NULL;
    list[0] = root;
    current = 0;
    last = 0;
   
    while (1)
    {
        if (current > last){
            break;
        }
       // Get value wether nodes data -99
        if (list[current]->value == -99){
            current++; continue;
        }
       
        pleft = (struct Node *) malloc (sizeof (struct Node));
        pright = (struct Node *) malloc (sizeof (struct Node));
       
        printf ("left of %d? ", list[current]->value);    // Storing Left Node value in Binary Tree.
        scanf ("%d", &n);

        pleft->value = n;
        pleft->left = NULL;
        pleft->right = NULL;
       
        printf ("right of %d? ", list[current]->value);    // Storing Right Node value in Binary Tree.
        scanf ("%d", &n);

        pright->value = n;
        pright->left = NULL;
        pright->right = NULL;
       
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
       
        list[last+1] = pleft;
        list[last+2] = pright;
        last = last + 2;
        current++;
    }

    // Printing Data.
    explore (root);
   
    return 0;
}

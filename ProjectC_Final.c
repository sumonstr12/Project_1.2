//-----------------------------------//
/*
    
This Code is for Finding Triangle in Graph.

*/
//------------------------------------//


#include <stdio.h>
#include <stdlib.h>

// Define a structure for graph nodes
struct Node    
{
    int nodeid;
    int adjcount;    //// Count of adjacent nodes
    int adjs[10];    //Adding adjacent node id.
};

const int w = 3;

int l = 0;    // Counter for the number of triangles found.
int final[50][3];    // Array to store the triangles found

// Function to sort the final array of triangles
void sort(int final[][3],int l){
    int totalP = l;    // Total number of triangles found

    // Iterate through the list of triangles to remove duplicates and print them
    for(int i = 0;i<totalP-1;i++){
        for(int j = i+1;j<totalP - 2;j++){
            if(i!=j){
                // If a duplicate triangle is found, skip it
                if(final[i][0] == final[j][0] && final[i][1] == final[j][1] && final[i][2] == final[j][2]){
                    break;
                }else{
                    // Print the unique triangle
                    printf("%d - %d - %d \n",final[i][0],final[i][1],final[i][2]);
                }
            }
        }
    }
    
}

// Adding Node in the graph.
int addNode(struct Node *p, int nid, int count)
{
    int i = 0, ncount = count;
    // Check if the node already exists
    for (i = 0; i < count; i++)
    {
        if (p[i].nodeid == nid)
        {
            break;
        }
    }
    // If the node does not exist, add it
    if (i == count)
    {
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

// Adding Adjaceny Nodes.
void addAdjacent(struct Node *p, int nid1, int nid2, int count)
{
    int i = 0, index;
    for (i = 0; i < count; i++)
    {
        if (p[i].nodeid == nid1)
        {
            int c = p[i].adjcount;
            p[i].adjs[c] = nid2;
            p[i].adjcount = c + 1;
            break;
        }
    }
}


// Checking is there have any Triangle or not .
int Triangle(struct Node *p, int count, int node)
{
    // Iterate through each node
    for (int i = 0; i < count; i++)
    {
        if (p[i].nodeid == node)
        {
            // Check each pair of adjacent nodes for a triangle
            for ( int j = 0; j < p[i].adjcount; j++)
            {
                int adj1 = p[i].adjs[j];
                for (int k = j + 1; k < p[i].adjcount; k++)
                {
                    int adj2 = p[i].adjs[k];

                    // Check if adj1 and adj2 are connected
                    for (int m = 0; m < count; m++)
                    {
                        if (p[m].nodeid == adj1)
                        {
                            for (int n = 0; n < p[m].adjcount; n++)
                            {
                                if (p[m].adjs[n] == adj2)
                                {
                                    // Determine the order of nodes in the triangle
                                    int min = (node < adj1) ? ((node < adj2) ? node : adj2) : ((adj1 < adj2) ?adj1 : adj2);
                                    int max = (node > adj1) ? ((node > adj2) ? node : adj2) : ((adj1 > adj2) ?adj1 : adj2);
                                    int middle = (node != min && node != max) ? node : (adj1 != min && adj1 != max) ? adj1 : adj2;

                                    // Store the triangle in the final array
                                    final[l][0] = min;
                                    final[l][1] = middle;
                                    final[l][2] = max;
                                    l++;
                                    //return 1;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

//Main Function.
int main()
{
    struct Node nodes[50];    // Array to store nodes
    int nodecount = 0;    // Counter for the number of nodes
    int n1 = 0, n2 = 0;    // Variables to store node ids
    //int final[50][3];

    while (1)        // Take Nodes values
    {
        printf("Enter n1, n2 (-9 to exit): ");
        scanf("%d %d", &n1, &n2);
        if (n1 == -9 || n2 == -9)
        {
            break;
        }
        nodecount = addNode(&nodes[0], n1, nodecount);
        nodecount = addNode(&nodes[0], n2, nodecount);
        addAdjacent(&nodes[0], n1, n2, nodecount);
        addAdjacent(&nodes[0], n2, n1, nodecount);
    }

    // Check for triangles
    for (int i = 0; i < nodecount; i++)
    {
        int node = nodes[i].nodeid;
        Triangle(nodes, nodecount, node);
    }

    sort(final,l);    // Sorting final array.

    

    return 0;
}

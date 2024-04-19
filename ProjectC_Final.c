#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int nodeid;
    int adjcount;
    int adjs[10];
};

const int w = 3;

int l = 0;
int final[50][3];



void sort(int final[][3],int l){
    
    int totalP = l;
    for(int i = 0;i<totalP-1;i++){
        for(int j = i+1;j<totalP - 2;j++){
            if(i!=j){
                if(final[i][0] == final[j][0] && final[i][1] == final[j][1] && final[i][2] == final[j][2]){
                    break;
                }else{
                    printf("%d - %d - %d \n",final[i][0],final[i][1],final[i][2]);
                }
            }
        }
    }
    

    
    
}

int addNode(struct Node *p, int nid, int count)
{
    int i = 0, ncount = count;
    for (i = 0; i < count; i++)
    {
        if (p[i].nodeid == nid)
        {
            break;
        }
    }
    if (i == count)
    {
        p[i].nodeid = nid;
        p[i].adjcount = 0;
        ncount++;
    }
    return ncount;
}

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



int Triangle(struct Node *p, int count, int node)
{
    
    
    for (int i = 0; i < count; i++)
    {
        if (p[i].nodeid == node)
        {
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

                                    int min = (node < adj1) ? ((node < adj2) ? node : adj2) : ((adj1 < adj2) ?adj1 : adj2);
                                    int max = (node > adj1) ? ((node > adj2) ? node : adj2) : ((adj1 > adj2) ?adj1 : adj2);
                                    int middle = (node != min && node != max) ? node : (adj1 != min && adj1 != max) ? adj1 : adj2;

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

int main()
{
    struct Node nodes[50];
    int nodecount = 0;
    int n1 = 0, n2 = 0;
    //int final[50][3];


    while (1)
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

    sort(final,l);

    

    return 0;
}

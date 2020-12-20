#include <bits/stdc++.h>
using namespace std;


#define V 9

int notParent[V];

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    char k,m;
    int w=0;
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++)
    {
        k=parent[i]+65;
        m=i+65;
        w=w+graph[i][parent[i]];
        cout<<k<<" - "<<m<<" \t"<<graph[i][parent[i]]<<" \n";
    }
    cout<<endl;
    cout<<"Weight Taken:"<<w<<endl;
}

void primMST(int graph[V][V])
{
    int parent[V];
    int key[V];

    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)  {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
        }
    }

    printMST(parent, graph);
}


int main()
{

    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 12, 0 },
                        { 0, 8, 0, 6, 0, 4, 0, 0, 3 },
                        { 0, 0, 6, 0, 9, 13, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 13, 10, 0, 3, 0, 0 },
                        { 0, 0, 0, 0, 0, 3, 0, 1, 5 },
                        { 8, 12, 0, 0, 0, 0, 1, 0, 6 },
                        { 0, 0, 3, 0, 0, 0, 5, 6, 0 } };
    primMST(graph);

    return 0;
}

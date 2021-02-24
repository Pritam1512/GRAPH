#include<bits/stdc++.h>
using namespace std;

//graph using adjaccency list 
//topological sorting using bfs algo
//only in DAG(directed acyclic graph)

void addEdge(int n,int m,vector<int> adj[],int inEdge[])
{
    adj[n].push_back(m);//add edge only from u->v
    inEdge[m]++;
}
void display(vector<int> adj[],int n)
{
    
    for(int i=0;i<n;i++)
    {
        cout << i << "-> :";
        for(auto x : adj[i])
        {
            cout << x << " ";
        }
        cout << "" << endl;
    }
}
void topologicalS(vector<int> adj[],int inEdge[],int n)
{
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(inEdge[i] == 0)
        q.push(i);
    }

    while(q.empty() == false)
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(auto x : adj[v])
        {
            inEdge[x]--;
            if(inEdge[x] == 0)
            {
                q.push(x);
            }
        }
    }
}
int main()
{
    vector<int> adj[6];
    int inEdge[6] = {0};

    addEdge(5,0,adj,inEdge);
    addEdge(5,2,adj,inEdge);
    addEdge(4,0,adj,inEdge);
    addEdge(4,1,adj,inEdge);
    addEdge(2,3,adj,inEdge);
    addEdge(3,1,adj,inEdge);
    cout << "Adjacency list repn of graph is :\n";
      display(adj,6);
      cout << "" << endl;
    cout << "InEdge array will be :\n";
    for(int i=0;i<6;i++)
    {
        cout << inEdge[i] << " ";
    }
    cout << "" <<endl;
    cout << "Tpoplogical sorting will be :\n";
    topologicalS(adj,inEdge,6);
    cout << "\n";
    return 0;
}
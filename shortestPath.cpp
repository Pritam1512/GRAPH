#include<bits/stdc++.h>
using namespace std;

//graph using adjaccency list 

void addEdge(int n,int m,vector<int> adj[])
{
    adj[n].push_back(m);
    adj[m].push_back(n);
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

void shortestPath(vector<int> adj[],int n,int s)
{
    bool visited[n] = {false};
    int dist[n];
    dist[s] =  0;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while(q.empty() == false)
    {
        int c = q.front();
        q.pop();
        for(auto x : adj[c])
        {
            if(visited[x] == false)
            {
                dist[x] = dist[c] + 1;
                visited[x] = true;
                q.push(x);
            }
        }

    }


    for(int i=0;i<n;i++)
    {
        cout << dist[i] << " ";
    }
}

int main()
{
    vector<int> adj[6];

    addEdge(0,1,adj);
    addEdge(0,2,adj);
    addEdge(2,3,adj);
    addEdge(2,4,adj);
    addEdge(3,4,adj);
    addEdge(4,5,adj);
    cout << "Element in the graph is :\n";
    display(adj,6);
    cout << "Shortest path from node 0 :\n";
    shortestPath(adj,6,0);
    return 0;
}
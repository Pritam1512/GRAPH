#include<bits/stdc++.h>
using namespace std;

//graph using adjaccency list 
// cycle detection using dfs recursive method

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

bool cycleDetRec(vector<int> adj[],int s,bool visited[],int parent)
{
    visited[s] = true;

    for(auto x : adj[s])
    {
        if(visited[x] == false)
        {
            if(cycleDetRec(adj,x,visited,s)== true)
                return true;
        }   
        else if(x != parent)
        {
            return true;
        }
    }
    return false;
}


bool cycleDetection(vector<int> adj[],int n)
{
    bool visited[n] = {false};

    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            if(cycleDetRec(adj,i,visited,-1) == true)
            {
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
    vector<int> adj[7];

    addEdge(0,1,adj);
    addEdge(0,2,adj);
    addEdge(2,3,adj);
    addEdge(2,4,adj);
    addEdge(3,6,adj);
    addEdge(4,5,adj);
    cout << "Elements in graph  :\n";
        display(adj,7);
    if(cycleDetection(adj,7) == true)
        cout << "Cycle is present \n";
    else
        cout << "Cylce is not present \n";
    return 0;
}
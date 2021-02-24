#include<bits/stdc++.h>
using namespace std;

//graph using adjaccency list 
//dfs traversal using stack ADT
//dfs traversal using recursion

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

void dfs(vector<int> adj[],int n,int s)
{
    stack<int> st;
    bool visited[n] = {false};

    st.push(s);
    visited[s] = true;

    while(st.empty() == false)
    {
        int c = st.top();
        cout << c << " ";
        st.pop();

        for(auto x : adj[c])
        {
            if(visited[x] == false)
            {
                visited[x] = true;
                st.push(x);
            }
        }
    }
}

void dfsRec(vector<int> adj[],int x,bool visited[])
{
    cout << x << " ";
    visited[x] = true;
    for(auto c : adj[x])
    {
        if(visited[c] == false){
                 dfsRec(adj,c,visited);
        }
    }
}
void DFS(vector<int> adj[],int n,int s)
{
    bool visited[n] = {false};
    for(int i=0;i<n;i++)
    {
        if(visited[i] == false)
        {
            dfsRec(adj,i,visited);
            cout << "->" <<endl;//to show how many disconnected graph is there
        }
    }
}

int main()
{
    vector<int> adj[8];

    addEdge(0,1,adj);
    addEdge(0,2,adj);
    addEdge(1,3,adj);
    addEdge(1,4,adj);
    addEdge(2,5,adj);
    addEdge(3,6,adj);
    addEdge(3,7,adj);

    cout << "Graph element are :\n";
    display(adj,8);
    cout << "Dfs traversal is :\n";
    DFS(adj,8,0);
    return 0;
}
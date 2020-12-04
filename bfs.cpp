#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector <int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector <int> adj[], int v)
{
    vector <bool> visited(v,false);
    queue <int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty())
    {
        int t = q.front();
        q.pop();
        cout<<t<<" ";
        for(int i = 0; i< adj[t].size(); i++)
        {
            if(visited[adj[t][i]] == false)
            {
                q.push(adj[t][i]);
                visited[adj[t][i]] = true;
            }
            
        }
    }
}

int main()
{
    int v = 5;
    vector <int> adj[v];
    addEdge(adj, 0, 1); 
    addEdge(adj, 0, 4); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 3); 
    addEdge(adj, 1, 4); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 3, 4); 
    bfs(adj,v);
    return 0; 
} 

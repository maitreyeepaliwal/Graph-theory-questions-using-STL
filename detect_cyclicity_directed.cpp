#include<bits/stdc++.h> 
using namespace std; 

void addEdge(vector <int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool iscycleUtil(int u, vector<int> adj[], vector<bool> &visited, vector<bool> &cyclic ) 
{ 
    if(!visited[u])
    {
        visited[u] = true;
        cyclic[u] = true;
    }
    for (int i=0; i<adj[u].size(); i++) 
    {
        if (visited[adj[u][i]] == false && iscycleUtil(i,adj,visited,cyclic)) 
        {
            return true;
        }
        else if(cyclic[adj[u][i]] == true)
        {
            return true;
        }
    }
    cyclic[u] = false;
    return false;
} 

bool cyclic(vector <int> adj[], int v)
{
    vector <bool> visited(v,false);
    vector <bool> cycle(v, false);
    for (int u=0; u<v; u++) 
    {
        if (iscycleUtil(u, adj, visited,cycle))
        return true;
    }   
    return false;
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
    if(cyclic)
    cout<<"is cyclic";
    else
    cout<<"not cyclic";
    return 0; 
}


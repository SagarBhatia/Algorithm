#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void printGraph(vector <int> adj[],int n)
{
    int i;
    vector<int>:: iterator it;

    for(i=0;i<n;i++)
    {
        cout<<i<<" :";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void dfsT(vector <int> adj[],vector <bool> &visited,int i,int n)
{
    if(!visited[i])
        visited[i]=true;
    cout<<i+1<<" ";
    for(int j=0;j<adj[i].size();j++)
    {
        if(visited[adj[i][j]]==false)dfsT(adj,visited,adj[i][j],n);
    }
}
void DFS(vector <int> adj[],vector <bool> visited ,int n)
{
    for(int j=0;j<n;j++)
    {
        if(visited[j]==false)
        {
            dfsT(adj,visited,j,n);
        }
    }

}
int main()
{
    int n;
    cin>>n;
    vector <int> adj[n];
    vector <bool> visited(n,false);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 1, 2);
    addEdge(adj, 3, 6);
    addEdge(adj, 5, 6);
    addEdge(adj, 4, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    printGraph(adj, n);
    DFS(adj,visited,n);

    return 0;
}

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void addEdge(vector <int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void PrintGraph(vector <int> adj[],int n)
{
    int i;
    vector<int>:: iterator it;
    for(i=0;i<n;i++)
    {
        cout<<i<<"  :  ";
        for(it=adj[i].begin();it!=adj[i].end();it++)
        {
            cout<<*it<<"  ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    vector <int> adj[n];
    vector <bool> visited(n.false);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    PrintGraph(adj, n);
    return 0;
}

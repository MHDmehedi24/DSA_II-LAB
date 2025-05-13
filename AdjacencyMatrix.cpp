#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;

    int adj[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            adj[i][j]=0;
        }
    }

    for(int i=0; i<e; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v]=w;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

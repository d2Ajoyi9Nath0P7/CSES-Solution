#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
const long long int INF = 1e18;
using namespace std;
#define fr(i,n) for(int i = 0; i <= n ; i++)
int node,edge,q;
 
void debug()
{
    cout<<"#BUG"<<"\n";
}
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void floyed_warshall()//
{
    ll dist[node+1][node+1];
    memset(dist,INF,sizeof(dist));
 
    for(int i = 1 ; i <= node ; i++)
    {
        for(int j = 1; j <= node ; j++)
        {
            if(i == j)
            {
                dist[i][j] = 0;
            }
            else{
                dist[i][j] = INF;
            }
        }
    }
    ll a, b, w;
    while(edge--)//o(E)
    {
        cin>>a>>b>>w;//1 2 1
        dist[a][b] = min(dist[a][b], w);//1
        dist[b][a] = min(dist[b][a], w);//1
    }
 
    for(int k = 1 ; k <= node; k++)
    {
        for(int row = 1; row <= node ; row++)
        {
            for(int col = 1 ; col <= node ; col++)
            {
                if(dist[row][col] > dist[row][k] + dist[k][col])//dist[row][k] != INF && dist[k][col] != INF
                {
                    dist[row][col] = min(dist[row][col], dist[row][k] + dist[k][col]);
                }
            }
        }
    }
 
    while(q--)//o(Q * E log(V))
    {
        int u,v;
        cin>>u>>v;
 
        if(dist[u][v] == INF)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<dist[u][v]<<"\n";
        }
    }
}
 
void solve()
{
    cin>>node>>edge>>q;
    floyed_warshall();
}
 
int main()
{
    fastIO();
    solve();
}
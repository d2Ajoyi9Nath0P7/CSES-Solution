#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
vector<int>vec[100001];
int vis[100001];
int dis[100001];
int parent[100001];
int n,m;
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
bool bfs(int node)
{
    queue<int>q;
    vis[node] = 1;
    dis[node] = 1;
    q.push(node);
    parent[node] = 0;
 
    while(!q.empty())
    {
        int nd = q.front();
        q.pop();
 
        if(n == nd)
        {
            return true;
        }
 
        for(int child : vec[nd])
        {
            if(vis[child] == 0)
            {
                dis[child] = dis[nd] + 1;
                vis[child] = 1;
                q.push(child);
                parent[child] = nd;
            }
        }
    }
    return false;
}
 
void solve()
{
    cin>>n>>m;
 
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    if(bfs(1) == true)
    {
        cout<<dis[n]<<"\n";
        int path = n;
        vector<int>v;
 
        while(parent[path] != 0)
        {
            v.pb(path);
            path = parent[path];
        }
        v.pb(path);
        reverse(v.begin(),v.end());
        for(int i : v)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    else
    {
        cout<<"IMPOSSIBLE"<<"\n";
    }
}
 
int main()
{
    fastIO();
    solve();
}

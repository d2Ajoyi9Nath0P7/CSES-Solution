#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
vector<int>vec[100001];
int vis[100001];
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void dfs(int node)
{
    vis[node] = 1;
    for(int child : vec[node])
    {
        if(vis[child] == 0)
        {
            dfs(child);
        }
    }
}
 
void solve()
{
    vector<int>vec2;
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int x,y;
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    int cnt = 0;
    for(int i = 1 ; i <= node; i++)
    {
        if(vis[i] == 0)
        {
            vec2.pb(i);
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt-1<<"\n";
 
    for(int i = 1 ; i < cnt ; i++)
    {
        cout<<vec2[i-1]<<" "<<vec2[i]<<"\n";
    }
}
 
 
int main()
{
    fastIO();
    solve();
}

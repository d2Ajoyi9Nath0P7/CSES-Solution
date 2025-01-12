#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
const int N = 100005;
const int INF = 1e9 + 7;
using namespace std;
#define fr(i,n) for(int i = 0; i <= n ; i++)
int node,edge;
void debug()
{
    cout<<"#BUG"<<"\n";
}
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void mark_dfs(int node,vector<int>&vis,vector<int>adj[])
{
    vis[node] = 1;
    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            mark_dfs(child,vis,adj);
        }
    }
}
 
int dfs(int node,vector<int>&dp,vector<int>adj[],int lastNode,vector<int>&child)
{
    if(node == lastNode)
    {
        return 1;
    }
 
    if(dp[node] != -1)
    {
        return dp[node];
    }
    int len = 0;
    for (auto c : adj[node])
    {
        int temp = dfs(c,dp,adj,lastNode,child);//dfs(2) -> dfs(3) -> dfs(4)
        int temp_len;
 
        if(temp == 0)
        {
            temp_len = 0;
        }
        else
        {
            temp_len = temp + 1;
        }
        if(temp_len > len)//(2 > 0)
        {
            child[node] = c;//child[1] = 5
            len = temp_len;//2
        }
    }
    return dp[node] = len;
}
 
void solve()
{
    int node,edge;
    cin>>node>>edge;//3 3
    int lastNode = node;
    vector<int>vis(node+1,0);
    vector<int>adj[node+1];
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
    }
 
    mark_dfs(1,vis,adj);
 
    if(!vis[node])
    {
        cout<<"IMPOSSIBLE\n";
    }
    else
    {
        vector<int>dp(node+1,-1);
        vector<int>child(node+1,0);
 
        int len = dfs(1,dp,adj,node,child);
        int node = 1;
        vector<int>path;
 
        while(node)
        {
            path.pb(node);//1 3 4 5
            node = child[node];
        }
        cout<<len<<"\n";
        for(auto it : path)
        {
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}
 
int main()
{
    fastIO();
    solve();
}
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
const int N = 100005;
const int INF = 1e9 + 7;
using namespace std;
vector<int>adj[N];
#define fr(i,n) for(int i = 0; i <= n ; i++)
int node,edge;
#define mod 1000000007;
 
void debug()
{
    cout<<"#BUG"<<"\n";
}
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve()
{
    int node,edge;
    cin>>node>>edge;//3 3
    vector<int>vis(node+1,0);
    vector<int>indeg(node+1,0);
 
    while(edge--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        indeg[b]++;
    }
 
    vector<int>dp(node+1,0);
    queue<int>q;
    for(int i = 1 ; i <= node ; i++)
    {
        if(indeg[i] == 0)
        {
            q.push(i);
        }
    }
 
    dp[1] = 1;
 
 
    while(!q.empty())
    {
        int nd = q.front();
        q.pop();
 
        for(auto child : adj[nd])
        {
            dp[child] = (dp[child] + dp[nd]) % mod;
            indeg[child]--;
 
            if(indeg[child] == 0)
            {
                q.push(child);
            }
        }
    }
    cout<<dp[node]<<"\n";
}
 
int main()
{
    fastIO();
    solve();
}

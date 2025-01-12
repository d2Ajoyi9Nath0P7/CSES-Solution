#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define N 100005
#define INF INT_MAX
#define minINF INT_MIN
 
vector<pair<int,int>>vec[N];
 
int dx[] = {0, -1,0,1};
int dy[] = {-1, 0,1,0};
 
void debug()
{
    cout<<"#Debugger"<<"\n";
}
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
const int mask = (1 << 20) + 200;
int n,m;
int dp[20][mask];
const int mod = 1000000007;
vector<int>adj[20];
 
 
int bitmask(int i,int mask)
{
    if(mask == ((1 << n) - 1) && i == n-1)
    {
        return 1;
    }
    if(i == n-1)
    {
        return 0;
    }
 
    if(dp[i][mask] != -1)
    {
        return dp[i][mask];
    }
 
    int res = 0;
 
    for(auto j : adj[i])
    {
        if((mask & (1 << j)) == 0)
        {
            res = (res + bitmask(j,(mask | (1 << j)))) % mod;
        }
    }
    return dp[i][mask] = res;
}
 
void solve()
{
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
    }
    memset(dp,-1,sizeof(dp));
    cout<<bitmask(0,1)<<"\n";
}
 
int main()
{
    fastIO();
    solve();
}
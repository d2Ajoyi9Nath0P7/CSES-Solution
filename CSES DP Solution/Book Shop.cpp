#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define repl(i,n) for(int i = 0; i <= n ; i++)
const ll INF = 1e18;
int node,edge;
#define mx 2 * 100005
int arr[mx];
ll tree[mx * 4];
ll mod = 1e9 + 7;
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
int maxPage(int index,int target,int n,vector<int>&price,vector<int>&page,vector<vector<int>>&dp)
{
    if(index == n || target == 0)
    {
        return 0;
    }
 
    if(dp[index][target] != -1)
    {
        return dp[index][target];
    }
 
    int not_take = maxPage(index+1,target,n,price,page,dp);
    int take = 0;
 
    if(target >= price[index])
    {
        take = page[index] + maxPage(index+1,target-price[index],n,price,page,dp);
    }
    return dp[index][target] = max(take,not_take);
}
 
void solve()
{
    int n,x;
    cin>>n>>x;
 
    vector<int>price(n);
    vector<int>page(n);
 
    for(int i = 0 ; i < n ; i++)
    {
        cin>>price[i];
    }
    for(int i = 0 ; i < n ; i++)
    {
        cin>>page[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,0));
 
 
    for(int i = n-1 ; i >= 0 ; i--)
    {
        for(int target = 0 ; target <= x; target++)
        {
            int not_take = 0 + dp[i+1][target];//dp[4][0]
            int take = 0;
 
            if(target >= price[i])
            {
                take = page[i] + dp[i+1][target-price[i]];
            }
 
            dp[i][target] = max(take,not_take);//dp[3][0] =
        }
    }
    cout<<dp[0][x]<<"\n";
    //cout<<maxPage(0,x,n,price,page,dp)<<"\n";
}
 
int main()
{
    fastIO();
    solve();
 
    return 0;
}
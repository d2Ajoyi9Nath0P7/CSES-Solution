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
 
ll dp[mx];
 
int max_elementt(int val)//int
{
    string number = to_string(val);//string
    char max_val = number[0];
 
    for(int i = 1 ; i < number.size() ; i++)
    {
        if(max_val < number[i])
        {
            max_val = number[i];
        }
    }
    return (max_val - '0');//
}
 
void solve()
{
    int n;
    cin>>n;
 
    for(int i = 1 ; i <= n ; i++)
    {
        int max_va = max_elementt(i);//int
        dp[i] = dp[i-max_va] + 1;//dp[20] = dp[20-2] + 1,dp[18] = dp[18-8] + 1,dp[10] = dp[10-1] + 1,dp[9] = dp[9-9]
    }
    cout<<dp[n]<<"\n";
}
 
int main()
{
    fastIO();
    solve();
 
    return 0;
}

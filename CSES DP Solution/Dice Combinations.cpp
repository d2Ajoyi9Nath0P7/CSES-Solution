#include<bits/stdc++.h>
using namespace std;
#define MAX 1000001
const int mod = (int) 1e9 + 7;
 
int dp[MAX];
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
int dice_combination(int n)
{
    if(n == 0 || n == 1){
        return dp[n];
    }
    if(dp[n] != 0){
        return dp[n];
    }
    for(int i = 1 ; i <= 6 ; i++)
    {
        if(n - i >= 0){
            dp[n] += dice_combination(n - i);
            dp[n] = dp[n] %  mod;
        }
    }
    return dp[n];
}
 
void solve()
{
    int n;
    cin>>n;
    memset(dp,0,sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    cout<<dice_combination(n);
}
int main()
{
    fastIO();
    solve();
}

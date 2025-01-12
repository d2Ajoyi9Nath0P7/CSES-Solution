#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
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
 
bool is_prime(ll n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if(prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }
 
    if(prime[n])
    {
        return true;
    }
 
    return false;
}
 
struct Coordinate
{
    int x,y;
} coordinate;
 
void solve()
{
    int t;
    cin>>t;
    vector<pair<int,int>>vp;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        vp.pb(make_pair(x,y));
    }
    ll ans = 0;
    int n = vp.size();
    int x1,x2;
    for(int i = 0 ; i < n; i++)//i = three
    {
        ans = ans + ((1LL * vp[i].ff * vp[(i+1) % n].ss) - (1LL * vp[(i+1) % n].ff *  vp[i].ss));
    }
    cout<<abs(ans)<<"\n";
}
int main()
{
    fastIO();
    solve();
}

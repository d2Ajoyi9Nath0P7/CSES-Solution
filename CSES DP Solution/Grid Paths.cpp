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
 
void init(ll Node, ll i,ll j)
{
    if(i == j)
    {
        tree[Node] = arr[i];
        return;
    }
    ll mid = (i + j) / 2;
    init(Node * 2,i,mid);
    init(Node * 2 + 1,mid + 1, j);
    tree[Node] = min(tree[Node * 2], tree[Node * 2 + 1]);
}
ll query(ll node, ll b, ll e, ll i, ll j)
{
    if(i > e || j < b)
    {
        return INF;
    }
    if(b >= i && e <= j)
    {
        return tree[node];
    }
 
    ll mid = (b + e) / 2;
    ll left = query(node * 2, b, mid, i, j);
    ll right = query(node * 2 + 1, mid + 1, e, i, j);
 
    return min(left, right);
}
 
void update(ll node,ll b,ll e,ll i,ll value)
{
    if(i > e || b > i)
    {
        return;
    }
    if(b >= i && e <= i)
    {
        tree[node] = value;
        return;
    }
    ll mid = (b + e) / 2;
    update(node * 2, b, mid, i, value);
    update(node * 2 + 1, mid + 1, e, i,value);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
 
 
 
/*ll grid_solve(ll n,ll m){
 
    if(n == 0 || m == 0){
        return 1;
    }
    if(vec[n][m] == '#'){
        return 0;
    }
    ll cnt = grid_solve(n-1,m) + grid_solve(n,m-1);
    cout<<cnt<<"\n";
    return cnt;
}*/
 
void solve()
{
    int n;
    cin>>n;
    vector<string>vec(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>vec[i];
    }
    vector<vector<int>>v(n,vector<int>(n));
 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(vec[i][j] == '*')
            {
                v[i][j] = 0;
                continue;
            }
            if(i == 0 and j == 0)
            {
                v[i][j] = 1;
                continue;
            }
            if(i == 0)
            {
                v[i][j] = v[i][j-1];
            }
            else if(j == 0)
            {
                v[i][j] = v[i-1][j];
            }
            else
            {
                v[i][j] = (v[i-1][j] % mod + v[i][j-1] % mod) % mod;
            }
        }
    }
    cout<<v[n-1][n-1]<<"\n";
}
int main()
{
    fastIO();
    solve();
 
    return 0;
}
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
 
    tree[Node] = min(tree[Node * 2] , tree[Node * 2 + 1]);
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
 
    return min(left,right);
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
    int left = node  * 2;
    int right  = node * 2 + 1;
    tree[node] = min(tree[left],tree[right]);
}
 
void solve()
{
    ll n,q;
    cin>>n>>q;
    for(int i = 1 ; i <= n ;i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    while(q--)
    {
        ll x,y,z;
        cin>>x>>y>>z;
 
        if(x == 1)
        {
            update(1, 1, n, y, z);
        }
        if(x == 2)
        {
            cout<<query(1, 1, n, y, z)<<"\n";
        }
    }
}
int main()
{
    solve();
    return 0;
}
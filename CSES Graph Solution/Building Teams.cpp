#include<bits/stdc++.h>
#define ins insert
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
//using namespace __gnu_pbds;
using namespace std;
//typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> OMS;
const int   N                               = (int) 1e6+5;
const int   M                               = (int) 1e9+5;
const int   mod                             = (int) 1000000007;
 
#define mx 200007
 
#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define vpp vector<pair<ll, ll>>
#define pb push_back
 
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/*SEGMENT tree and lazy propagation
struct NODE
{
    ll value = 0;
    ll lazy = 0;
 
} tree[mx*4];
ll arr[mx];
void ref()
{
    for(int i = 0; i <= 4*mx; i++)
    {
        tree[i].value = tree[i].lazy = 0;
    }
}
void build(ll node,ll b,ll  e)
{
    if(b == e)
    {
        tree[node].value = arr[b];//
        return;
    }
    ll mid = (b + e) >> 1;//3 1 0
    build(2 * node, b, mid);//(0,3,2) (0,1,4) (0,0,8)
    build(2*node + 1,mid + 1,e);
    tree[node].value += tree[2 * node].value + tree[2 * node + 1].value;
}
void update(ll  node,ll  b,ll  e,ll  i,ll  j,ll  x)//(1,1,8,2,5,2) (2,1,4,2,5,2) (4,1,2,2,5,2) (8,1,1,2,5,2) (9,2,2,2,5,2)
{
    if(i > e || j < b)
    {
        return;
    }
    if(b >= i && e <= j)
    {
        tree[node].value += (e - b + 1) * x;
        tree[node].lazy += x;
        return;
    };
    ll  mid = (b + e) >> 1;
    update( node * 2, b, mid, i, j, x);
    update(node * 2 + 1, mid + 1, e, i, j, x);
    tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value + (e - b + 1) * tree[node].lazy;
}
ll  query(ll  node,ll  b,ll  e,ll  i,ll  j,ll  carry = 0)
{
    if(i > e || j < b)
    {
        return 0;
    }
    if(b >= i && e <= j)
    {
        return tree[node].value + carry * (e - b + 1);
    }
    ll mid = (b + e) / 2;//2
    ll carryValue = carry + tree[node].lazy;//(0 + 2) (2 + 0)
    ll p1 = query(node * 2,b,mid,i,j,carryValue);//(2,1,4,2,4,2)
    ll p2 = query(node * 2 + 1,mid+1,e,i,j,carryValue);
    return p1 + p2;
}
*/
 
/*
geometry template :
 
 
*/
 
 
void lower_bound(vector<int>&v,int element)
{
    int left = 0,right = v.size()-1,mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(v[mid] == element)
        {
            break;
        }
        else if(v[mid] > element)
        {
            right = mid - 1;
        }
        else if(v[mid] < element)
        {
            left = mid + 1;
        }
    }
    cout<<"Lower bound : "<<mid<<"\n";
}
void upper_bound(vector<int>&v,int element)
{
    int left = 0,right = v.size()-1,mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        if(v[mid] == element)
        {
            break;
        }
        else if(v[mid] > element)
        {
            right = mid - 1;
        }
        else if(v[mid] < element)
        {
            left = mid + 1;
        }
    }
    cout<<"Lower bound : "<<mid<<"\n";
}
int prime_factor(int n)/////27 45
{
    int cnt = 0;
    vector<int>vec;
    for (int i = 3; i * i <= n; i = i + 2)
    {
        if(n % i == 0)// (9 % 3 == 0)
        {
            vec.pb(i);//3
            vec.pb(n/i);  //9 3 0
            break;
        }
    }
    sort(vec.begin(),vec.end());
    int val = *vec.rbegin();
 
    return val;
}
bool is_Prime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for(int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            return false;
        }
    return true;
}
bool counter(int n)
{
    set<int>st;
    for(int i = 2 ; i * i <= n ; i++)
    {
        if(n % i == 0)// 6 2
        {
            if(is_Prime(n/i))
            {
                st.insert(n/i);
            }
            if(is_Prime(i))
            {
                st.insert(i);//2
            }
        }
    }
    if(st.size() == 2)
    {
        return true;
    }
    return false;
}
void two_D_prefix_sum()
{
    int row,col;
    cin>>row>>col;
    vector<vector<int>>arr(row,vector<int>(col));
    vector<vector<int>>pref(row,vector<int>(col));
    for(int i = 0 ; i < row; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cin>>arr[i][j];
        }
    }
    pref[0][0] = arr[0][0];
    for(int i = 0 ; i < 1 ; i++)
    {
        for(int j = 1; j < col ; j++)
        {
            pref[i][j] = arr[i][j] + pref[i][j-1];
        }
    }
    for(int i = 1 ; i < row ; i++)
    {
        for(int j = 0; j < 1 ; j++)
        {
            pref[i][j] = arr[i][j] + pref[i-1][j];
        }
    }
    for(int i = 1 ; i < row ; i++)
    {
        for(int j = 1 ; j < col ; j++)
        {
            pref[i][j] = arr[i][j] + pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1];
        }
    }
    for(int i = 0 ; i < row ; i++)
    {
        for(int j = 0 ; j < col ; j++)
        {
            cout<<pref[i][j]<<" ";
        }
        cout<<"\n";
    }
}
 
bool dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&color,int col)
{
    vis[node] = 1;
    color[node] = col;
 
    for(auto child : adj[node])
    {
        if(!vis[child])
        {
            bool res = dfs(child,adj,vis,color,col^1);
            if(res == false)
            {
                return false;
            }
        }
        else{
            if(color[node] == color[child])
            {
                return false;
            }
        }
    }
 
    return true;
}
 
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int>vis(n+1,0);
    vector<int>color(n+1,-1);
    vector<int>adj[n+1];
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    bool ck = 1;
    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            if(!dfs(i,adj,vis,color,1))
            {
                ck = 0;
                cout<<"IMPOSSIBLE\n";
                break;
            }
        }
    }
    if(ck == 1)
    {
        for(int i = 1 ; i <= n; i++)
    {
        if(color[i] == 0)
        {
            color[i] = 2;
        }
    }
    for(int i = 1 ; i <= n ;i++)
    {
        cout<<color[i]<<" ";
    }
    cout<<"\n";
    }   
}
int main()
{
    fastIO();
    solve();
}
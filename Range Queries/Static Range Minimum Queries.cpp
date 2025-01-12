#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define repl(i,n) for(int i = 0; i <= n ; i++)
const ll INF = 1e18;
int node,edge;
 
#define mx 2 * 100001
int arr[mx];
int tree[mx * 3];
 
void init(int Node,int i,int j)
{
    if(i == j)
    {
        tree[Node] = arr[i];
        return;
    }
    int mid = (i + j) / 2;
    init(Node * 2,i,mid);
    init(Node * 2 + 1,mid + 1, j);
    tree[Node] = min(tree[Node * 2],tree[Node * 2 + 1]);
}
 
int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
    {
        return INT_MAX;
    }
    if(b >= i && e <= j)
    {
        return tree[node];
    }
    int mid = (b + e) / 2;
 
    int left = query(node * 2, b, mid, i, j);
    int right = query(node * 2 + 1, mid + 1, e, i, j);
 
    return min(left,right);
}
 
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i = 1 ; i <= n ;i++)
    {
        cin>>arr[i];
    }
    init(1,1,n);
    while(q--)
    {
        int x,y;
        cin>>x>>y;
 
        cout<<query(1,1,n,x,y)<<"\n";   
    }
}
 
int main()
{
    solve();
    return 0;
}
bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define pb push_back
using namespace std;
#define MAX 100000
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
vector<int>vec[100001];
bool vis[100001];
int color[100001];
int parent[100001];
int endVertex,startVertex;
int node,edge;
 
bool dfs(int n,int par)//(1,-1) (3,1) (5,3)
{
    vis[n] = 1;//1 3 5
    parent[n] = par;//-1 1 3
 
    for(int child : vec[n])//2 3 5    1 4    2 5    4 1
    {
        if(child == par)
        {
            continue;
        }
        if(vis[child] == 0)//
        {
            if(dfs(child,n))//(3,1) ()
            {
                return true;
            }
        }
        else
        {
            if(child != par)
            {
                startVertex = child;
                endVertex = n;
                return true;
            }
        }
 
    }
    return false;
}
 
bool visitedNode()
{
    for(int i = 1 ; i <= node ; i++)
    {
        if(vis[i] == 0)
        {
            if(dfs(i,-1))
            {
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
    fastIO();
 
 
    int x,y;
    cin>>node>>edge;
    while(edge--)
    {
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    vector<int>res;
    if(!visitedNode())
    {
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else
    {
        int ev = endVertex;//3*
        res.pb(endVertex);//3 5
 
        while(ev != startVertex)//
        {
            res.pb(parent[ev]);//5
            ev = parent[ev];//7
        }
        res.pb(endVertex);
        cout<<res.size()<<"\n";
        for(int i : res)
        {
            cout<<i<<" ";
        }
    }
}
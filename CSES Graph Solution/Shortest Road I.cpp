#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
const int N = 100002;
const long long int INF = 1e18;
using namespace std;
vector<pair<int,int>>vec[N];
#define fr(i,n) for(int i = 0; i <= n ; i++)
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
void dijkstra(int source)//
{
    ll dist[100002];
    int  vis[100002];
    fr(i, 100002) dist[i] = INF;
    dist[source] = 0;//dist[1] = 0;
    fr(i, 100002) vis[i] = 0;
    set<pair<ll,int>>st;//(dis,node)
    st.insert({0,source});//(log N) cmplexity  // (0,1)//(dis,Node)
    while(st.size() > 0)//E
    {
        auto node = *st.begin(); //(0,1)
        int v = node.second; //1
        ll v_dist = node.first; //0
        st.erase(st.begin());//(0,1)
        if(vis[v] == 1)
        {
            continue;
        }
        else
        {
            vis[v] = 1; //vis[1] = 1;
            for(auto child : vec[v])//
            {
                int child_v = child.first;//2   
                ll child_wt = child.second;//6   2
 
                if(v_dist + child_wt < dist[child_v])// 0+6 < INF, 0+2 < INF
                {
                    dist[child_v] = v_dist + child_wt;//dist[2]=0+6   dist[3]=0
                    st.insert({dist[child_v],child_v});//(6,2)
                }
            }
        }
 
    }
 
    for(int i = 1 ; i <= node ; i++)
    {
        cout<<dist[i]<<" ";
    }
 
} //o (V + E log (V))
void solve()
{
    int a, b, w;
    cin>>node>>edge;//3 3
    while(edge--)
    {
        cin>>a>>b>>w;
        vec[a].pb({b,w});
    }
    dijkstra(1);// o(V + E * log(V))
}
int main()
{
    fastIO();
    solve();
}
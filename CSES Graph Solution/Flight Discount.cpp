#include<bits/stdc++.h>
#define pb push_back
#define ll long long int
using namespace std;
 
#define INF (ll) 1e15
#define negINF INT_MIN
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void dijkstra(ll node,ll dis,vector<pair<ll,ll>>adj[],vector<ll>&distance)
{
    distance[node] = dis;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>>pq;
    pq.push({dis,node});//(0,1)
 
    while(!pq.empty())
    {
        pair<ll,ll>frnt = pq.top();
        ll dist = frnt.first;
        ll node = frnt.second;
        pq.pop();
 
        if(distance[node] < dist)//optimization            ------------ if this graph, 1-->2(10),1-->2(5),2-->3(10),1-->3(6)
        {
            continue;
        }
 
        for(auto i : adj[node])
        {
            ll v = i.first;//2
            ll wt = i.second;//3
 
            if(dist + wt < distance[v])
            {
                distance[v] = dist + wt;
                pq.push({distance[v],v});
            }
        }
    }
}
 
void reverseGraph(vector<pair<ll,ll>>adj[],vector<pair<ll,ll>>reverseAdj[],ll node)
{
    for(int i = 1 ; i <= node ; i++)
    {
        for(auto edge : adj[i])
        {
            int v = edge.first;
            int wt = edge.second;
            reverseAdj[v].pb({i,wt});
        }
    }
}
 
ll res(vector<pair<ll,ll>>adj[],ll node,vector<ll>&distance1,vector<ll>&distance2)
{
    ll minPrice = 1e15 + 5;
    for(int i = 1 ; i <= node ; i++)
    {
        for(auto it : adj[i])
        {
            int u = i;//1
            int v = it.first;//2
            int wt = it.second;//3
 
            if (distance1[u] != INF && distance2[v] != INF)
            {
                minPrice = min(minPrice,distance1[u] + distance2[v] + (wt/2));
            }
        }
    }
    return minPrice;
}
 
void solve()
{
    ll node,edge;
    scanf("%lld %lld", &node, &edge);
    vector<pair<ll,ll>>adj[node+1];
    vector<pair<ll,ll>>reverseAdj[node+1];
 
    while(edge--)
    {
        ll a,b,c;
         scanf("%lld %lld %lld", &a, &b, &c);
        adj[a].pb({b,c});
    }
 
    vector<ll>distance1(node+1,INF);
    dijkstra(1,0,adj,distance1);
    reverseGraph(adj,reverseAdj,node);
    vector<ll>distance2(node+1,INF);
    dijkstra(node,0,reverseAdj,distance2);
    printf("%lld\n", res(adj, node, distance1, distance2));
}
 
int main()
{
    fastIO();
    solve();
}
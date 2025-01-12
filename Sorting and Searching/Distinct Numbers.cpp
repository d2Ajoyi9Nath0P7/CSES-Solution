#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
const int N = 100005;
const int INF = 1e9 + 7;
using namespace std;
vector<int>adj[N];
#define fr(i,n) for(int i = 0; i <= n ; i++)
int node,edge;
#define mod 1000000007;
 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;//vector<vector<int>>vvi;
typedef vector<vl> vvl;//vector<vector<long long,long long>>vvl;
typedef pair<int,int> pii;//
typedef pair<double, double> pdd;//vector<pair<double,double>>pdd
typedef pair<ll, ll> pll;//vector<pair<long long,long long>>pll;
typedef vector<pii> vii;//vector<pair<int,int>>vii;
typedef vector<pll> vll;//vector<pair<ll,ll>>vll;
typedef double dl;
 
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(x) (int)x.size()
 
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
 
void debug()
{
    cout<<"#BUG"<<"\n";
}
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void dijkstra(int src,vector<pii>adj[],vector<int>&distance)
{
    distance[src] = 0;
    priority_queue<pii,vii,greater<pii>>pq;
    pq.push({0,src});
 
    while(!pq.empty())//V log(V)
    {
        pair<int,int>front = pq.top();
        int dis = front.first;//4
        int node = front.second;//1
        pq.pop();//log(V)
 
        if(distance[node] < dis)
        {
            continue;
        }
 
        for(auto i : adj[node])//E * log(V)
        {
            int nd = i.first;
            int wt = i.second;
 
            if(dis != INF && dis + wt < distance[nd])//log(V)
            {
                distance[nd] = dis + wt;
                pq.push({distance[nd],nd});
            }
        }
    }
}
 
void solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin>>vec[i];
    }
    set<int>st;
    for(int i = 0 ; i < n ; i++)
    {
        st.insert(vec[i]);
    }
    cout<<st.size()<<"\n";
}
 
int main()
{
    fastIO();
    solve();
}
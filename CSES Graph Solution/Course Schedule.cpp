#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>vec[100001];
int in[100001];
vector<int>v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
bool solve(int node)
{
    queue<int>q;
    for(int i = 1 ;i <= node ;i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int element = q.front();
        v.pb(element);
        q.pop();
        for(int i : vec[element])
        {
            in[i]--;
            if(in[i] == 0)
            {
                q.push(i);
            }
        }
    }
 
    return node == v.size();
}
int main()
{
    fastIO();
    int n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        vec[x].pb(y);
        in[y]++;
    }
    if(!solve(n))
    {
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else{
        for(int i : v)
        {
            cout<<i<<" ";
        }
    }
}

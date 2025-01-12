#include<bits/stdc++.h>
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
 
int main()
{
    fastIO();
    int n,q;
    cin>>n>>q;
    int arr[n];
    for(int i = 0 ; i < n; i++)
    {
        cin>>arr[i];
    }
    ll sum = 0;
    ll arr2[n];
 
    for(int i = 0 ; i < n; i++)
    {
        sum = sum + arr[i];//2
        arr2[i] = sum ;
    }
 
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
 
        if(x == 0 || y == 0)
        {
            cout<<arr2[y]<<"\n";
        }
        else
        {
            cout<<arr2[y] - arr2[x-1]<<"\n";
        }
    }
}
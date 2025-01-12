#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define pb push_back
using namespace std;
#define MAX 200006
int arr[MAX];
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
    for(int i = 1 ; i <= n; i++)
    {
        cin>>arr[i];//o(N)
        arr[i] = arr[i] ^ arr[i-1];
    }
    while(q--)//o(Q * N) + o (Q)
    {
        int x,y;
        cin>>x>>y;
        cout<<(arr[y] ^ arr[x-1])<<"\n";
    }
}

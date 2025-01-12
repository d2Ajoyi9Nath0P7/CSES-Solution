#include<bits/stdc++.h>
#define ins insert
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
using namespace __gnu_pbds;
using namespace std;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> OS;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> OMS;
const int   N                               = (int) 1e6+5;
const int   M                               = (int) 1e9+5;
const int   mod                             = (int) 1000000007;
 
#define mx 200007
 
#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define vpp vector<pair<ll, ll>>
#define pb push_back
#define ff first
#define ss second
#define case_(tc) cout << "Case " << tc << ": ";
#define mem(a, b) memset(a, b, sizeof(a))
#define all(vtor) vtor.begin(), vtor.end()
#define rall(vtor) vtor.rbegin(), vtor.rend()
 
#define pi 2 * acos(0.0)
#define tani(a) atan(a) / (pi / 180)
#define sini(a) asin(a) / (pi / 180)
#define cosi(a) cos(a) / (pi / 180)
#define cos(a) cos(a *pi / 180)
#define sin(a) sin(a *pi / 180)
#define tan(a) tan(a *pi / 180)
//const ll mod = 1e9 + 7;
 
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
 
#define eps 1e-7
#define maxii 32000
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
void solve()
{
    ll n,product,sm = 0;
    cin>>n>>product;
    vector<int>vec(n);
 
    for(int i = 0 ; i < n ; i++){
        ll x;
        cin>>x;
        vec[i] = x;
    }
 
    ll left = 0,right = 1e18,ans = 0,mid,sum = 0;
 
    while(left <= right)
    {
        sum = 0;
        mid = (left + right)>>1;
        for(int i = 0 ; i < vec.size() ; i++){
            sum += (mid / vec[i]);
 
            if (sum >= product) {
				break;
			}
        }
        if(sum >= product){
            right = mid - 1;
            ans = mid;
        }
        else{
            left = mid + 1;
        }
    }
    cout<<ans<<"\n";
}
 
int main()
{
    fastIO();
    solve();
}
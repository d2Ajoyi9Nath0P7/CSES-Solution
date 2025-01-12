/*
        author : Ajoy Nath
*/
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
 
/*ll power(ll base,ll power)
{
    ll result = 1;
 
 
    while(power)
    {
        if(power % 2 == 1)
        {
            result = (result * base)%md;
            power--;
        }
        else
        {
            base = (base * base)%md;
            power = power / 2;
        }
    }
 
    return result ;
}
*/
//prime_checking
 
bool is_prime(ll sum)
{
    for(int i=2; i<sum; i++)
    {
        if(sum % i == 0)
        {
            return true;
        }
    }
    return false;
}
 
//binary_To_Decimal
 
ll binaryToDecimal(ll number)
{
    ll num = number;//1010
    ll dec_value = 0;//0
    ll base = 1;//1
 
    ll temp = num;//1010
 
 
    while(temp)
    {
        ll last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += (last_digit * base);
        base = base * 2;
    }
 
    return dec_value;
}
 
void SieveOfEratosthenes(int n)
{
    if(n < 2)
    {
        cout<<"Error!"<<"\n";
    }
    bool prime_number[n + 1];//
    memset(prime_number,true,sizeof(prime_number));
    for (int i = 2; i * i <= n; i++)
    {
        if (prime_number[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime_number[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime_number[i] == true)
        {
            cout <<i<< " ";
        }
    }
}
void debugger()
{
    cout<<"##Debugger##"<<"\n";
}
ll Pow(ll c, ll d)
{
    return d == 0 ? 1 : c * pow(c, d - 1);
}
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return ((a * b) / gcd(a, b));
}
ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}
ll bigMod(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}
inline ll MOD(ll a)
{
    return (a % mod + mod) % mod;
}
inline ll modAdd(ll a, ll b)
{
    return MOD(MOD(a) + MOD(b));
}
inline ll modSub(ll a, ll b)
{
    return MOD(MOD(a) - MOD(b));
}
inline ll modMul(ll a, ll b)
{
    return MOD(MOD(a) * MOD(b));
}
inline ll modInv(ll a)
{
    return bigMod(a, mod - 2);
}
inline ll modDiv(ll a, ll b)
{
    a = MOD(a);
    b = modInv(b);
    return (a * b) % mod;
}
 
vector<string> v;
map<char, ll> mp;
set<string> vs;
void permute(string str, string out)
{
    // When size of str becomes 0, out has a
    // permutation (length of out is n)
    if (str.size() == 0)
    {
        vs.insert(out);
        return;
    }
 
    // One be one move all characters at
    // the beginning of out (or result)
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and
        // add it to out
        permute(str.substr(1), out + str[0]);
 
        // Rotate string in a way second character
        // moves to the beginning.
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
ll ncr(ll nn, ll rr)
{
    if (rr > nn)
        return 0;
    if (rr == 0)
        return 1;
    if (rr == 1)
        return nn;
    if (nn == rr)
        return 1;
    return ncr(nn - 1, rr - 1) + ncr(nn - 1, rr);
}
bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    ll ans1, ans2;
    ans1 = min(2 * p1.ff, p1.ss) - min(p1.ff, p1.ss);
    ans2 = min(2 * p2.ff, p2.ss) - min(p2.ff, p2.ss);
    if (ans1 > ans2)
        return true;
    else
        return false;
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
void binary_search(int& left,int& right,vector<int>&vec,int& find_value)
{
    while(right - left > 1)
    {
        int mid = (left + right) / 2;
        if(vec[mid] < find_value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    if(vec[left] == find_value)
    {
        cout<<left<<"\n";
    }
    else if(vec[right] == find_value)
    {
        cout<<right<<"\n";
    }
    else
    {
        cout<<"Not found"<<"\n";
    }
}
int lower_bound(vector<int>&v,int element)
{
    int left = 0,right = v.size()-1,mid;
    while(right - left > 1)
    {
        mid = (left + right) / 2;
        if(v[mid] < element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    if(v[left] >= element)
    {
        return left;
    }
    else if(v[right] >= element)
    {
        return right;
    }
    return v.size();
}
int upper_bound(vector<int>&v,int element)
{
    int left = 0,right = v.size()-1,mid;
    while(right - left > 1)
    {
        mid = (left + right) / 2;
        if(v[mid] <= element)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    if(v[left] > element)
    {
        return left;
    }
    else if(v[right] > element)
    {
        return right;
    }
    return v.size();
}
double multiply(double mid,int n)
{
    double ans = 1;
    for(int i = 0 ; i < n ; i++)
    {
        ans *= mid;
    }
    return ans;
}
void precision()
{
    double x;
    int n;
    cin>>x>>n;
    double low = 1,high = x,mid;
    int i = 0;
    while(high - low > eps)//(1 > 0.01) (0.5 > 0.01) (0.25 > 0.01) (0.125 > 0.01) (0.0625 > 0.01) (0.03125 > 0.01) (0.015625 > 0.01)
    {
        mid = (high + low) / 2;//1.5  1.25  1.125  1.1875  1.21875  1.203125  1.1953125
        if(multiply(mid,n) < x)
        {
            low = mid;//1  1.125  1.1875
        }
        else
        {
            high = mid;//1.5  1.25  1.21875  1.203125  1.1953125
        }
    }
    cout<<setprecision(10)<<low<<" "<<high<<"\n";
    cout<<pow(x,1.0/n)<<"\n";
 
    //time complexity : p * log(N * (10^d))
    //for p-th root of number N with d decimal place
}
 
ll n,x;
ll dp[1000005];
ll vec[1000005];
 
int coin(int extra)
{
    ll res = 0;
    if(extra == 0)
    {
        //dp[0] = 1;
        return 1;
    }
    else if(extra < 0)
    {
        return 0;
    }
    if(dp[extra] != -1)
    {
        return dp[extra];
    }
    for(int i = 0 ; i < n ; i++)
    {
        res += coin(extra - vec[i]);
    }
    return dp[extra] = res % mod;
}
 
void solve()
{
    cin>>n>>x;
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < n ; i++)
    {
        cin>>vec[i];
    }
    cout<<coin(x)<<"\n";
}
int main()
{
    fastIO();
    solve();
}
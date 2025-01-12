#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define repl(i,n) for(int i = 0; i <= n ; i++)
const ll INF = 1e18;
int node,edge;
#define mx 2 * 100005
int arr[mx];
ll tree[mx * 4];
ll mod = 1e9 + 7;
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
/*
 
//hashing
 
void preComputingPower(string const& s)
{
    int n = s.size();
    vector<ll>p_pow(n);
    const int p = 31;
    const int m = 1e9 + 9;
    p_pow[0] = 1;
 
    for(int i = 1 ; i < n ; i++)
    {
        p_pow[i] = (p_pow[i-1] * p) % m;
    }
}
 
long long compute_hash(string s)
{
    preComputingPower(s);
    const int m = 1e9 + 9;
 
    ll hash_val = 0;
 
    for(int i = 0 ; i < n ; i++)
    {
        int val = (s[i] - 'a') + 1;
        hash_val = (hash_val + val * p_pow[i]) % m;
    }
    return hash_val;
}
*/
 
vector<int>createTempArray(string& pattern)
{
    vector<int>LPS(pattern.size(),0);
 
    int i = 0;
    for(int j = 1 ;  j < pattern.size() ; )
    {
        if(pattern[i] == pattern[j])
        {
            LPS[j] = i + 1;
            i++;
            j++;
        }
        else
        {
            if(i != 0)
            {
                i = LPS[i-1];
            }
            else
            {
                LPS[j] = 0;
                j++;
            }
        }
    }
 
    return LPS;
}
 
vector<int> kmp(string& text,vector<int>&res)
{
    vector<int>lps = createTempArray(text);
 
    if(lps[text.size()-1] != 0)
    {
        res.pb(lps[text.size()-1]);
    }
    else{
        return res;
    }
 
    int temp = lps[text.size()-1];
 
    while(temp)
    {
        temp = lps[temp-1];
        if(temp > 0)
        {
            res.pb(temp);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
 
int main()
{
    fastIO();
 
    string text;
    cin>>text;
    vector<int>res;
    vector<int>result = kmp(text,res);
 
    for(auto i : result)
    {
        cout<<i<<" ";
    }
}

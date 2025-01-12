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
 
vector<int>createTempArray(string pattern)
{
    vector<int>LPS(pattern.size(),0);
    int i = 0;
 
    for(int j = 1 ; j < pattern.size() ; )
    {
        if(pattern[i] == pattern[j])
        {
            i++;
            LPS[j] = i;
            j++;
        }
        else
        {
            if(i != 0)
            {
                i = LPS[i-1];
            }
            else{
                LPS[j] = 0;
                j++;
            }
        }
    }
    return LPS;
}
 
int kmp(string& text,string& pattern)
{
    vector<int>lps = createTempArray(pattern);
    int i = 0, j = 0;
    int cnt = 0;
 
    while(i < text.size())
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i++;
            }
        }
        if(j == pattern.size())
        {
            cnt++;
        }
    }
    return cnt;
}
 
int main()
{
   fastIO();
 
   string text,pattern;
   cin>>text>>pattern;
 
   cout<<kmp(text,pattern)<<"\n";
}
/*
 
 Author:Ajoy Nath
 
*/
 
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
 
int vis[1001][1001];
char arr[1001][1001];
char brr[1001][1001];
int row,col;
 
//int dx[] = {0, -1,0,1};
//int dy[] = {-1, 0,1,0};
 
void debug()
{
    cout<<"#Debugger"<<"\n";
}
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
bool isValid(int r,int c)
{
    if(r < 1 || r > row || c < 1 || c > col)
    {
        return false;
    }
    if(arr[r][c] == '#')
    {
        return false;
    }
 
    return true;
}
 
vector<char>vec;
 
bool bfs(int x,int y)
{
    queue<pair<int,int>>q;
    vis[x][y] = 1;
    q.push({x,y});
 
    while(!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
 
        q.pop();
 
        if(arr[a][b] == 'B')
        {
            while(1)
            {
                vec.pb(brr[a][b]);
 
                if(vec.back() == 'L')
                {
                    b++;
                }
                else if(vec.back() == 'R')
                {
                    b--;
                }
                else if(vec.back() == 'U')
                {
                    a++;
                }
                else if(vec.back() == 'D')
                {
                    a--;
                }
 
                if(arr[a][b] == 'A')
                {
                    break;
                }
            }
            return true;
        }
 
        if(isValid(a,b-1) && vis[a][b-1] == 0)
        {
            brr[a][b-1] = 'L';
            int newX = a;
            int newY = b - 1;
            q.push({newX,newY});
            vis[newX][newY] = 1;
        }
 
        if(isValid(a-1,b) && vis[a-1][b] == 0)
        {
            brr[a-1][b] = 'U';
            int newX = a - 1;
            int newY = b;
            q.push({newX,newY});
            vis[newX][newY] = 1;
        }
 
        if(isValid(a,b+1) && vis[a][b+1] == 0)
        {
            brr[a][b+1] = 'R';
            int newX = a;
            int newY = b + 1;
            q.push({newX,newY});
            vis[newX][newY] = 1;
        }
 
        if(isValid(a+1,b) && vis[a+1][b] == 0)
        {
            brr[a+1][b] = 'D';
            int newX = a + 1;
            int newY = b;
            q.push({newX,newY});
            vis[newX][newY] = 1;
        }
    }
    return false;
}
 
 
void solve()
{
    cin>>row>>col;
    int a_x,a_y;
 
    for(int i = 1 ; i <= row ; i++)
    {
        for(int j = 1; j <= col ; j++)
        {
            cin>>arr[i][j];
            if(arr[i][j] == 'A')
            {
                a_x = i;
                a_y = j;
            }
        }
    }
 
    if(bfs(a_x,a_y) == true)
    {
        cout<<"YES"<<"\n";
        cout<<vec.size()<<"\n";
        reverse(vec.begin(),vec.end());
        for(auto i : vec)
        {
            cout<<i;
        }
    }
    else
    {
        cout<<"NO"<<"\n";
    }
 
}
 
int main()
{
    fastIO();
    solve();
}
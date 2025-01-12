/*
    CSES problem : Counting Rooms
    Author : Ajoy Nath
*/
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
 
 
vector<vector<char>>grid;
vector<vector<bool>>visited;
 
int dx[] = {-1,0,1,0};
int dy[] = { 0,1,0,-1};
int n,m;
 
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
 
bool safe(int x,int y)
{
    if(x < 0 or x >= n or y < 0 or y >= m or grid[x][y] == '#' or visited[x][y] == true)
    {
        return false;
    }
    return true;
}
 
 
void dfs(int row,int col)
{
    visited[row][col] = true;
    int new_x,new_y;
 
    for(int i = 0 ; i < 4 ; i++)
    {
        new_x = row + dx[i];//1
        new_y = col + dy[i];//2
 
        if(safe(new_x,new_y) == true)
        {
            dfs(new_x,new_y);
        }
    }
}
 
void solve()
{
    cin>>n>>m;
 
    grid.resize(n,vector<char>(m));
    visited.resize(n,vector<bool>(m,false));
 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin>>grid[i][j];
        }
    }
 
    int ans = 0;
 
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m; j++)
        {
            if(grid[i][j] == '.' and visited[i][j] == false)
            {
                ans++;
                dfs(i,j);
            }
        }
    }
 
    cout<<ans<<"\n";
}
 
int main()
{
    fastIO();
    solve();
}
#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
#define mx 2000010
struct node
{
    int value=0;
    int lazy=0;
 
} tree[mx*4];
int arr[mx];
 
void build(int Node,int b,int e)//(0,7,1) (0,3,2)  (0,1,4) (0,0,8)
{
    if(b==e)
    {
        tree[Node].value = arr[b];//
        return;
    }
    int mid = (b + e) / 2;//3 1 0
    build(2 * Node, b, mid);//(0,3,2) (0,1,4) (0,0,8)
    build(2*Node + 1,mid + 1,e);
    tree[Node].value += tree[2 * Node].value + tree[2*Node + 1].value;
}
 
void update(int node,int b,int e,int i,int j,int x)//(1,1,8,2,5,2) (2,1,4,2,5,2) (4,1,2,2,5,2) (8,1,1,2,5,2) (9,2,2,2,5,2)
{
    if(i > e || j < b)
    {
        return;
    }
    if(b >= i && e <= j)//
    {
        /*for(int i = b ; i <= e ; i++)
        {
            arr[i] = arr[i] + x;
        }*/
 
        tree[node].value += (e - b + 1) * x;
        tree[node].lazy += x;
        return;
    };
 
    int mid = (b + e) / 2;//4 2 1
    update( node * 2, b, mid, i, j, x);//(2,1,4,2,5,2) (4,1,2,2,5,2) (8,1,1,2,5,2)
    update(node * 2 + 1, mid + 1, e, i, j, x);//(9,2,2,2,5,2)
    tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value + (e - b + 1) * tree[node].lazy;
}
 
int query(int node,int b,int e,int i,int j,int carry = 0)
{
    if(i > e || j < b)
    {
        return 0;
    }
    if(b >= i && e <= j)
    {
        tree[node].value = tree[node].value + carry * (e - b + 1);
        return tree[node].value + carry * (e - b + 1);
    }
    int mid = (b + e) / 2;//2
    int carryValue = carry + tree[node].lazy;//(0 + 2) (2 + 0)
 
    int p1 = query(node * 2,b,mid,i,j,carryValue);//(2,1,4,2,4,2)
    int p2 = query(node * 2 + 1,mid+1,e,i,j,carryValue);
 
    return p1 + p2;
}
 
int main()
{
    int q;
    cin>>q;
 
    while(q--)
    {
        ll x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
 
        ll x = (y3 - y2) * (x2 - x1) - (x3 - x2) * (y2 - y1);
 
        if(x > 0)
        {
            cout<<"LEFT"<<"\n";
        }
        else if(x < 0)
        {
            cout<<"RIGHT"<<"\n";
        }
        else
        {
            cout<<"TOUCH"<<"\n";
        }
    }
    return 0;
}
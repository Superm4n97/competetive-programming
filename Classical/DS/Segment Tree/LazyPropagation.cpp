#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll S[maxn*4], lazy[maxn*4], n;
void relax(ll node, ll b, ll e)
{
      S[node]+=lazy[node];
      if (b!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
      }
      lazy[node] = 0;
      return;
}
ll Query(ll node, ll b, ll e, ll x, ll y)
{
      relax(node,b,e);
      if (b>x || e<y)return 0;
      if (b==x && e==y)return S[node];
      ll mid = (b+e)/2;
      return Query(node*2,b,mid,x,y)+Query(node*2+1,mid+1,e,x,y);
}
void Update(ll node, ll b, ll e, ll x, ll y, ll val)
{
      if (lazy[node])relax(node,b,e);
      if(b>y || e<x) return;
      if(b>=x && e<=y){
            lazy[node] = val;
            relax(node,b,e);
            return;
      }
      ll mid = (b+e)/2;
      Update(node*2,b,mid,x,y,val);
      Update(node*2+1,mid+1,e,x,y,val);
      S[node] = S[node*2]+S[node*2+1];
      return;
}
int main()
{
      return 0;
}

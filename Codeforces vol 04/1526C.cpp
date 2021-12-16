#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);
#define maxn 200005
#define inf 100000000000000017

using namespace std;

ll n , A[maxn], cnt = 0 , st[maxn*4], prop[maxn*4];

void build(ll node,ll b, ll e)
{
      if (b==e){
            st[node] = A[b];
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      build(L,b,mid);
      build(R,mid+1,e);

      st[node] = min(st[L],st[R]);
      return;
}

void relax(ll node, ll b, ll e)
{
      if (prop[node]==0)return;

      if (b==e){
            st[node]+=prop[node];
            prop[node] = 0;
      }
      else {
            st[node]+=prop[node];
            prop[node*2]+=prop[node];
            prop[node*2+1]+=prop[node];
            prop[node] = 0;
      }
}

void rangeUpdate(ll node, ll b, ll e, ll x, ll y, ll val)
{
      relax(node, b, e);
      if (e<x || b>y)return;
      if (x<=b && e<=y){
            prop[node] = val;
            relax(node,b,e);
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      rangeUpdate(L,b,mid,x,y,val);
      rangeUpdate(R,mid+1,e,x,y,val);

      st[node] = min(st[L],st[R]);
      return;
}

ll rangeQuary(ll node, ll b, ll e, ll x, ll y)
{
      relax(node,b,e);
      if (e<x || b>y)return inf;
      if (x<=b && e<=y)return st[node];

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      ll t1 = rangeQuary(L,b,mid,x,y) , t2 = rangeQuary(R,mid+1,e,x,y);

      return min(t1,t2);
}

int main()
{
      vector<pair<ll,ll> >vp;

      scl(n);
      for (int i=1 ; i<=n ;i++){
            scl(A[i]);
            if (A[i]<0){
                  vp.push_back({A[i],i});
                  A[i] = A[i-1];
            }
            else {
                  A[i] += A[i-1];
                  cnt++;
            }
      }

      build(1,1,n);

      sort(vp.rbegin(),vp.rend());

      for (int i=0 ; i<vp.size() ; i++){
            ll a = vp[i].first, id = vp[i].second;
            ll temp = rangeQuary(1,1,n,id,n);
            if (temp+a>=0){
                  rangeUpdate(1,1,n,id,n,a);
                  cnt++;
            }
      }
      printf("%lld\n",cnt);

      return 0;
}

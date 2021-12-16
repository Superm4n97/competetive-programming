#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

ll n,m,p;
vector<pair<ll,ll> >A,B;
vector<pair<pair<ll,ll>,ll > >tpl;

ll S[maxn*4] , propagation[maxn*4];

void build(ll node, ll b, ll e)
{
      if (b==e){
            S[node] = -B[b].second;
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      build(L,b,mid);
      build(R,mid+1,e);

      S[node] = max(S[L],S[R]);
      return;
}

ll findUpperbound(ll val)
{
      ll b = 0 , e = m-1, ret = m;
      while(b<=e){
            ll mid = (b+e)/2;
            if (B[mid].first>val){
                  ret = min(ret,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      return ret;
}

void relax(ll node, ll b, ll e)
{
      if (b==e){
            S[node]+=propagation[node];
            propagation[node] = 0;
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      propagation[L]+=propagation[node];
      propagation[R]+=propagation[node];
      S[node]+=propagation[node];
      propagation[node] = 0;
      return;
}

void update(ll node, ll b, ll e, ll val, ll x)
{
      relax(node,b,e);

      if (e<x)return;
      if (b>=x){
            propagation[node] = val;
            relax(node,b,e);
            return;
      }

      ll mid = (b+e)/2 , L = node*2, R = node*2+1;
      update(L,b,mid,val,x);
      update(R,mid+1,e,val,x);

      S[node] = max(S[L],S[R]);
      return;
}

int main()
{
      scanf("%lld %lld %lld",&n,&m,&p);
      for (int i=0 ; i<n ; i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            A.push_back({a,b});
      }
      for (int i=0 ; i<m ; i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            B.push_back({a,b});
      }
      for (int i=0 ; i<p ; i++){
            ll x,y,z;
            scanf("%lld %lld %lld",&x,&y,&z);
            tpl.push_back({{x,y},z});
      }

      sort(A.begin(),A.end());
      sort(B.begin(),B.end());
      sort(tpl.begin(),tpl.end());

      build(1,0,m-1);

      ll tpl_idx = 0 , ans = -A[0].second-B[0].second;
      for (int i=0 ; i<n ;i++){
            ll a = A[i].first , ca = A[i].second;

            while(tpl_idx<p && tpl[tpl_idx].first.first<a){
                  ll idx_b = findUpperbound(tpl[tpl_idx].first.second);
                  if (idx_b<m){
                        update(1,0,m-1,tpl[tpl_idx].second,idx_b);
                  }
                  tpl_idx++;
            }
            ans = max(ans,S[1]-ca);
      }
      printf("%lld\n",ans);

      return 0;
}

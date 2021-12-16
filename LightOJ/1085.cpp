#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define mod 1000000007

using namespace std;

ll n,q,pre[maxn],st[maxn*4],ans[maxn];
vector<pair<ll,ll> > vp, vs;

ll amod(ll a)
{
      return a - a/mod*mod;
}

void clean()
{
      vp.clear();
      vs.clear();
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            st[node] = 0;
            return;
      }
      ll L = node*2 , R = node*2+1, mid = (b+e)/2;
      build(L,b,mid);
      build(R,mid+1,e);
      st[node] = 0;
      return;
}

void update(ll node, ll b, ll e, ll idx, ll val)
{
      if (b==e && b==idx){
            st[node] = val;
            return;
      }
      if (b>idx || e<idx)return;

      ll L = node*2, R = node*2+1, mid = (b+e)/2;
      update(L,b,mid,idx,val);
      update(R,mid+1,e,idx,val);

      st[node] = amod(st[L]+st[R]);
}

ll quary(ll node, ll b, ll e, ll idx)
{
      if (b>idx)return 0;
      if (e<=idx)return st[node];

      ll L = node*2, R = node*2+1, mid = (b+e)/2;
      return amod(quary(L,b,mid,idx)+quary(R,mid+1,e,idx));
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            scanf("%lld",&n);
            clean();
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  vp.push_back({a,i});
            }

            vs = vp;
            sort(vs.begin(),vs.end());

            for (int i=0 ; i<n ; i++){
                  ll id = vs[i].second;
                  vp[id].second = i;
            }
            pre[0] = -1;
            for (int i=1 ; i<n ; i++){
                  if (vs[i].first!=vs[i-1].first)pre[i] = i-1;
                  else pre[i] = pre[i-1];
            }

            build(1,0,n-1);

            for (int i=0 ; i<n ; i++){
                  ans[i] = amod(quary(1,0,n-1,pre[vp[i].second])+1);
                  update(1,0,n-1,vp[i].second,ans[i]);
                  if (ans>0)ans[i] = amod(ans[i]+ans[i-1]);
            }
            printf("Case %d: %lld\n",_t,ans[n-1]);
      }

      return 0;
}

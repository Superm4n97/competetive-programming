#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n , eb,ob;
vector<ll> G[maxn];

void clean()
{
      eb = ob = 0;
      for (int i=0 ; i<n+2 ; i++)G[i].clear();
}

ll dfs(ll u, ll p,ll l)
{
      if (G[u].size()==1){
            return 1;
            if (l%2==1){
                  show(u);
                  show(l);
                  return 1;
            }
            else return 0;
      }
      ll ret = 0 , e = 0, o = 0;
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (v==p)continue;
            if (G[v].size()==1){
                  if (l%2==0)e = 1;
                  else o = 1;
            }
            ret+=dfs(v,u,l+1);
      }
      eb+=e;
      ob+=o;
      return ret;
}

int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            clean();
            scanf("%lld",&n);

            for (int i=0 ; i<n-1 ; i++){
                  ll a, b;
                  scanf("%lld %lld",&a,&b);
                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            ll ans = dfs(1,0,0);

            ans = max(ans-ob+1,1LL);

//            show(ans);

            printf("%lld\n",ans);

      }

      return 0;
}

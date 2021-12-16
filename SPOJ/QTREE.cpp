#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

vector<ll> G[maxn] , W[maxn];
ll n , P[maxn] , childMX[maxn], subTreeSize[maxn] , tme;

ll E[maxn], index[maxn];
void clean()
{
      tme = 1;
      memset(index,0,sizeof index);
      memset(parentMX,0,sizeof parentMX);
      memset(P,0,sizeof P);
      memset(E,0,sizeof E);
      memset(subTreeSize,0,sizeof subTreeSize);
      for (int i=0 ; i<=n+2 ; i++){
            G[i].clear();
            W[i].clear();
      }

      return 0;
}

void dfsSubTree(ll u, ll p)
{
      subTreeSize[u] = 1;
      ll child = 0 , childSZ = 0;
      for (int i=0 ;i<G[u].size() ; i++){
            ll v = G[u][i];
            if (v==p)continue;
            dfsSubTree(v,u);
            subTreeSize[u]+=subTreeSize[v];
            if (childSZ<subTreeSize[v]){
                  childSZ = subTreeSize[v];
                  child = v;
            }
      }
      childMX[u] = child;
}

void eulerHeavyLight(ll u, ll p)
{
      E[tme] = u;
      index[u] = tme;
      tme++;

      if (childMX[u] != 0)eulerHeavyLight(v,u);
      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (v==p || v==childMX[u])continue;
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            scanf("%lld",&n);

            clean();

            for (int i=1 ; i<n ; i++){
                  ll a,b,c;
                  scanf("%lld %lld %lld",&a,&b,&c);
                  G[a].push_back(b);
                  G[b].push_back(a);
                  W[a].push_back(c);
                  W[b].push_back(c);
            }
            dfsSubTree(1,1);
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 200005

using namespace std;

ll n, A[maxn],P[maxn], cnt[maxn], vis[maxn], par[maxn], X[maxn];
vector<ll> roots;

ll findParent(ll a)
{
      if (par[a]==a)return a;
      return par[a] = findParent(par[a]);
}

void makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);
      if (a!=b)par[a] = b;
}

void rec(ll u, ll rt)
{
      vis[u] = 1;

      ll v = A[u];
      if (vis[v]){
            if (findParent(v)==findParent(rt)){
                  P[rt] = u;
                  A[u] = rt;
                  return;
            }
            ll a = P[v];
            A[a] = rt;
            P[rt] = a;
            P[v] = u;
            return;
      }
      else {
            makeParent(v, u);
            P[v] = u;
            rec(v,rt);
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n);
            roots.clear();
            for (int i=1 ; i<=n ; i++){
                  scl(A[i]);
                  if (A[i]==i){
                        A[i]++;
                        if (A[i] == n+1)A[i] = 1;
                  }
                  par[i] = i;
                  X[i] = A[i];
                  vis[i] = cnt[i] = 0;
            }
            for (int i=1 ; i<=n ; i++){
                  cnt[A[i]]++;
            }
            for (int i=1 ;i<=n ; i++){
                  if (cnt[i]==0)roots.push_back(i);
            }

            for (int i=0 ; i<roots.size() ; i++){
                  if (vis[roots[i]]==0)rec(roots[i],roots[i]);
            }

            ll cnt_x = 0;
            for (int i=1 ; i<=n ; i++){
                  if (X[i]==A[i])cnt_x++;
            }


            printf("%lld\n",cnt_x);
            for (int i=1 ; i<=n ; i++)printf("%lld ",A[i]);
            printf("\n");
      }


      return 0;
}

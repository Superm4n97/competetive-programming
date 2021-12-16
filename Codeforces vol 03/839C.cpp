#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

vector < ll > G[maxn];
ll n , dep[maxn];
double probability[maxn] , ans = 0;

void dfs(ll u, ll p)
{

      ll childs = 0;

      if (u==1)childs = G[u].size();
      else childs = G[u].size()-1;

      if (childs==0){
            ans+=(probability[u]*(double)dep[u]*1.0);
            return;
      }

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];

            if (v!=p){
                  dep[v] = dep[u]+1;
                  probability[v] = probability[u]/childs;

                  dfs(v,u);
            }
      }
}

int main()
{
      cin >> n;

      for (int i=1 ; i<n ; i++){

            ll a, b;
            cin >> a >> b;

            G[a].push_back(b);
            G[b].push_back(a);
      }

      probability[1] = 1;
      dep[1] = 0;
      dfs(1,0);

      printf("%.15lf\n",ans);


      return 0;
}
/**

**/

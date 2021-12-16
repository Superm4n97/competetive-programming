#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,m,t[maxn],s[maxn] , sum_t , sum_s , is_bipertite , even_sum,odd_sum,L[maxn];
vector<ll> G[maxn];

void clean()
{
      is_bipertite = true;
      sum_s = sum_t = 0;
      even_sum = odd_sum = 0;
      for (int i=0 ; i<n+4 ; i++){
            G[i].clear();
            L[i] = -1;
      }
}

void dfs(ll u)
{
      if (L[u]%2)odd_sum+=(t[u]-s[u]);
      else even_sum+=(t[u]-s[u]);

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (L[v] == -1){
                  L[v] = L[u]+1;
                  dfs(v);
            }
            if (L[u]%2 == L[v]%2)is_bipertite = false;
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n >> m;
            clean();
            for (int i=1 ; i<=n ; i++){
                  cin >> s[i];
                  sum_s+=s[i];
            }
            for (int i=1 ; i<=n ; i++){
                  cin >> t[i];
                  sum_t+=t[i];
            }

//            for (int i=1 ; i<=n ; i++)cout << t[i]-s[i] << " ";
//            cout << endl;


            for (int i=0 ; i<m ; i++){
                  ll a,b;
                  cin >> a >> b;
                  G[a].push_back(b);
                  G[b].push_back(a);
            }
//            show(sum_s%2);
//            show(sum_t%2);
            if ((sum_s%2+2)%2 != (sum_t%2+2)%2){
                  cout << "NO" << endl;
                  continue;
            }

            L[1] = 0;
            dfs(1);

            if (is_bipertite && even_sum!=odd_sum)cout << "NO" << endl;
            else cout << "YES" << endl;

      }

      return 0;
}
/*
1
5 6
124 -884 758 -96 460
-872 -807 -895 -866 -45
2 3
4 5
1 4
3 1
2 4
1 5

1
5 10
521 696 891 558 787
-902 275 -957 818 531
2 3
5 4
1 4
1 3
2 4
1 2
5 3
2 5
1 5
4 3
*/

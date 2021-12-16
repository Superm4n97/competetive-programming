#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 10004

using namespace std;

ll n, A[maxn] , cnt[maxn] , g[maxn];
vector<ll> D[maxn];

ll initialize()
{
      for (int i=1 ; i<maxn ; i++){
            for (int j=i ; j<maxn ; j+=i)D[j].push_back(i);
      }
}

ll nc4(ll a)
{
      return a*(a-1)*(a-2)*(a-3)/24;
}

/*2 4 6 12
2-> 4
4-> 2
6-> 2*/

void solve()
{
      memset(cnt,0,sizeof cnt);
      memset(g,0,sizeof g);

      for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<D[A[i]].size() ; j++){
                  cnt[D[A[i]][j]]++;
            }
      }
      for (int i=maxn-3 ; i>=1 ; i--){
            g[i] = nc4(cnt[i]);
            for (int j=i+i ; j<maxn ; j+=i)g[i]-=g[j];
      }
      printf("%lld\n",g[1]);
}

int main()
{
      initialize();
      while(scanf("%lld",&n) != EOF){
            for (int i=0 ; i<n ; i++)scanf("%lld",&A[i]);
            solve();
      }

      return 0;
}

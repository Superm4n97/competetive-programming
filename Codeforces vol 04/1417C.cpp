#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 100000000000014

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            scanf("%I64d",&n);

            vector < ll > G[n+5];

            for (int i=1 ; i<=n ; i++)G[i].push_back(0);

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  scanf("%I64d",&a);

                  G[a].push_back(i);
            }
            for (int i=1 ; i<=n ; i++)G[i].push_back(n+1);

            ll sub[n+5];
            memset(sub,-1,sizeof sub);

            for (int i=1 ; i<=n ; i++){
                  if (G[i].size()==2)continue;

                  for (int j = 1 ; j<G[i].size()-1 ; j++){
                        sub[i] = max(sub[i] , max(G[i][j] - G[i][j-1] , G[i][j+1]-G[i][j]));
                  }
            }


            ll ans[n+5];
            for (int i=0 ; i<n+3 ; i++)ans[i] = inf;

            for (ll i=1 ; i<=n ; i++){
                  if (sub[i]==-1)continue;
                  ans[sub[i]] = min(ans[sub[i]] , i);
            }

            //for (int i=1 ; i<=n ; i++)cout << ans[i] << " ";
            //cout << endl;

            ll mn = inf;

            for (int i=1 ; i<=n ; i++){
                  mn = min(ans[i],mn);

                  if (ans[i] == inf){
                        printf("-1 ");
                  }
                  else {
                        printf("%I64d ",ans[i]);
                  }
                  ans[i+1] = min(ans[i] , ans[i+1]);
            }
            printf("\n");
      }

      return 0;
}

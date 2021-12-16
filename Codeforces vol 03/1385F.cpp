#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n , k;
            cin >> n >> k;

            vector < ll > G[n+5];
            ll leaf[n+5] , finish[n+5];
            memset(leaf, 0,sizeof leaf);
            memset(finish,0,sizeof finish);

            for (int i = 1 ; i<n ; i++){

                  ll a, b;
                  cin >> a >> b;
                  G[a].push_back(b);
                  G[b].push_back(a);
            }

            if (n==2){
                  if (k==1)cout << 1 << endl;
                  else cout << 0 << endl;
                  continue;
            }

            for (int i=1 ; i<=n ; i++){
                  if (G[i].size()==1){
                        leaf[G[i][0]]++;
                        finish[i] = 1;
                  }
            }

            queue < ll > q;

            for (int i=1;  i<=n ; i++){
                  if (leaf[i]>=k)q.push(i);
            }

            ll ans = 0;

            while(!q.empty()){

                  ll u = q.front();
                  q.pop();

                  //show(u);

                  if (leaf[u]<k)continue;

                  //show(u);

                  ans+=leaf[u]/k;
                  leaf[u]%=k;

                  if (leaf[u]==0){
                        ll cnt = 0 , node = 0;
                        for (int i=0 ; i<G[u].size() ; i++){

                              ll v = G[u][i];
                              if (finish[v]==0){
                                    cnt++;
                                    node = v;
                                    /*leaf[v]++;
                                    if(leaf[v]>=k){
                                          q.push(v);
                                          break;
                                    }
                                    */
                              }
                        }

                        if (cnt==1){
                              leaf[node]++;
                              if (leaf[node]>=k)q.push(node);
                              finish[u] = 1;
                        }

                  }
            }

            cout << ans << endl;
      }


      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n , P[maxn] , A[maxn] , sz[maxn] , degree1[maxn] , degree2[maxn] , ans = 0;
vector <ll > G[maxn];

void clean()
{
      ans = 0;
      for (int i=0 ; i<n+3 ; i++){
            G[i].clear();
            P[i] = i;
            sz[i] = 1;
            degree1[i] = 0;
            degree2[i] = 0;
      }
}

ll findParent(ll a)
{
      if (P[a]==a)return a;
      return P[a] = findParent(P[a]);
}

void makeParent(ll a, ll b)
{
//      show(a);
//      show(P[a]);
      a = findParent(a);
      b = findParent(b);
//      show(b);

      P[a] = b;
      sz[b]+=sz[a];
}


int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n;
            clean();
            for (int i=1 ; i<=n ; i++){

                  ll a, b;
                  cin >> a >> b;

                  G[a].push_back(b);
                  G[b].push_back(a);
                  degree1[a]++;
                  degree1[b]++;

                  degree2[a]++;
                  degree2[b]++;
            }

            queue<ll> q1,q2;

            for (int i=1 ; i<=n ; i++){
                  if (degree1[i]==1){
                        q1.push(i);
                        q2.push(i);

                        degree1[i] = 0;
                        degree2[i] = 0;
                  }
            }


            while(!q1.empty()){

                  ll u = q1.front();
                  q1.pop();
//                  show(u);
                        for (int j = 0 ; j<G[u].size() ; j++){

                              ll v = G[u][j];
//                              show(v);
                              if (degree1[v]>0){
                                    makeParent(u,v);
//                                    show(P[u]);
                                    degree1[v]--;
                                    if (degree1[v]==1){
                                          q1.push(v);
                                          degree1[v] = 0;
                                    }
                                    break;
                              }
                        }
            }

//            show(P[1]);

            ll rem = n;

            while(!q2.empty()){

                  ll u = q2.front();
                  q2.pop();


                  ll root = findParent(u);

                  ans += (sz[root]-1) + (rem-sz[root])*2;
                  rem--;
                  sz[root]--;

//                  show(u);
//                  show(ans);
//                  show(root);
//                  show(sz[root]);

                  for (int i=0 ; i<G[u].size() ; i++){

                        ll v = G[u][i];
                        if (degree2[v]>0){
                              degree2[v]--;
                              if (degree2[v]==1){
                                    q2.push(v);
                                    degree2[v] = 0;
                              }
                              break;
                        }
                  }
            }

//            show(rem);

            ans+=(rem*(rem-1));

            cout << ans << "\n";
      }

      return 0;
}

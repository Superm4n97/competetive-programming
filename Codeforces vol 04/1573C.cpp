#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      scanf("%lld",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);

            vector<ll> G[n+5];
            ll k[n+5],id[n+5];
            memset(id,0,sizeof id);

            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&k[i]);

                  for (int j=0 ; j<k[i] ; j++){
                        ll a;
                        scanf("%lld",&a);
                        G[a].push_back(i);
                        id[i]++;
                  }
            }

            ll cnt_node = 0, ans = 0, vis[n+5];
            priority_queue<ll>pq, snd;
            memset(vis,0,sizeof vis);

                  for (int i=1 ; i<=n ; i++){
                        if (id[i]==0 && vis[i]==0)snd.push(-i);
                  }

            while(true){

                  if (snd.empty())break;

                  while(!snd.empty()){
                        pq.push(snd.top());
                        snd.pop();
                  }

                  ans++;
                  while(!pq.empty()){
                        ll u = -pq.top();
                        vis[u]++;
                        pq.pop();
                        cnt_node++;

//                        cout << u << " ";

                        for (int i=0 ; i<G[u].size() ; i++){
                              ll v = G[u][i];
                              id[v]--;
                              if (id[v]==0){
                                    if (v>u)pq.push(-v);
                                    else snd.push(-v);
                              }
                        }
                  }
            }

            if (cnt_node!=n)printf("-1\n");
            else {
                  printf("%lld\n",ans);
            }
      }

      return 0;
}
/*
1
4
1 2
0
2 1 4
1 2
*/

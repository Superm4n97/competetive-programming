#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,cost[maxn] , vis[maxn];
vector < ll > G[maxn];

void bfs()
{
      for (int i=0 ; i<maxn ; i++)cost[i] = maxn;

      queue < ll > q;
      q.push(1);
      cost[1] = 0;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            //show(u);

            for (int i=0 ; i<G[u].size() ; i++){
                  ll v = G[u][i];

                  if (cost[v]>cost[u]+1){
                        cost[v] = cost[u]+1;
                        q.push(v);
                  }
            }
      }
}

int main()
{
      cin >> n;
      for (int i=1 ; i<n;i++){
            ll a=i , b = i+1;
            G[a].push_back(b);
            G[b].push_back(a);
      }

      for (int i=1 ; i<=n ; i++){
            ll a;
            cin >> a;

            if (a==i)continue;
            else {
                  G[i].push_back(a);
            }
      }

      bfs();

      for (int i=1 ; i<=n ; i++)cout << cost[i] << " ";
      cout << endl;

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define 200005

using namespace std;

ll n ,m ,k , dis[maxn] , P[maxn];
vector<ll> G[maxn] , R[maxn];

void bfs()
{
      for (int i=0 ; i<n+4 ; i++)dis[i] = maxn+5;

      dis[P[k]] = 0;

      queue<ll> q;
      q.push(P[k]);

      while(!q.empty()){

            ll u = q.front();
            q.pop();

            for (int i=0 ;i<R[u].size() ; i++){

                  ll v = R[u]][i];
                  if (dis[v]>dis[u]){

                        dis[v] = dis[u]+1;
                        q.push(v);
                  }
            }
      }
}

int main()
{
      cin >> n >> m;

      for (int i=0 ; i<m ; i++){

            ll a, b;
            cin >> a >> b;

            G[a].push_back(b);
            R[b].push_back(a);
      }
      cin >> k;
      for (int i=1 ; i<=k ;i++)cin >> P[i];

      bfs();
      ll mn = 0 , mx = 0;

      for (int i=1 ; i<k ; i++){

            if (dis[P[i]] != dis[P[i+1]]+1)mn++;

            ll cnt = 0 , temp = 0;
            for (int j = 0 ; j<G[P[i]].size() ; i++){

                  ll v = G[u][P[i]];
                  if (dis[v]==dis[P[i]]-1)cnt++;
                  if (v==P[i+1] && dis[v]==dis[i]-1)temp = 1;
            }

      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define maxn 200005

using namespace std;

ll n,m , indegree[maxn];
vector < ll > G[maxn];
map < pair < ll ,ll > , ll > mp;
vector < pair < ll , ll > > edge;

void clean()
{
      for (int i=0 ; i<=n+4 ; i++){
            G[i].clear();
            indegree[i] = 0;
      }
      mp.clear();
      edge.clear();

      return;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            cin >> n >> m;

            clean();

            for (int i=0 ; i<m ; i++){
                  ll t,a,b;
                  cin >> t >> a >> b ;

                  G[a].push_back(b);
                  G[b].push_back(a);

                  if (t==1){
                        mp[{a,b}]=1;
                        mp[{b,a}]=2;
                        indegree[b]++;
                  }
                  edge.push_back({a,b});
            }

            ll ans = 0;
            queue < ll > q;
            for (int i=1; i<=n ; i++){
                  if(indegree[i]==0)q.push(i);
            }

            while(!q.empty()){

                  ll u = q.front();
                  q.pop();
                  ans++;

                  for (int i=0 ; i<G[u].size() ; i++){
                        ll v = G[u][i];

                        if (mp[{u,v}]==0){
                              mp[{u,v}] = 1;
                              mp[{v,u}] = 2;
                        }
                        else if (mp[{u,v}]==1){
                              indegree[v]--;
                              if (indegree[v]==0)q.push(v);
                        }
                  }
            }

            if (ans<n)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;

                  for (int i=0 ;i<edge.size() ; i++){

                        ll a = edge[i].first , b = edge[i].second;
                        if (mp[{a,b}]==1)cout << a << " " << b << endl;
                        else cout << b << " " << a << endl;
                  }
            }

      }

      return 0;
}

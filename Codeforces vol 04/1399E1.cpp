#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector <ll> G[maxn] , W[maxn];
ll n , S , sum, leaf[maxn];
priority_queue < pair < ll , pair < ll ,ll > > > pq;

void clean()
{
      for (int i = 0; i<=n+1; i++){
            G[i].clear();
            W[i].clear();
            leaf[i] = 0;
      }

      sum = 0;

      while(!pq.empty())pq.pop();
}

void findChild(ll u, ll p)
{
      if (G[u].size()==1 && u!=1){

            leaf[u] = 1;
            return;
      }

      for (int i=0; i<G[u].size() ; i++){

            ll v = G[u][i];

            if(v!=p){

                  findChild(v,u);
                  leaf[u]+=leaf[v];

                  sum += W[u][i]*leaf[v];

                  pq.push({W[u][i]*leaf[v] - W[u][i]/2 * leaf[v] , {leaf[v],W[u][i]}});
            }
      }
      return;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n >> S;
            clean();

            for (int i=1; i<n ; i++){
                  ll a, b, c;
                  cin >> a >> b >> c;

                  G[a].push_back(b);
                  G[b].push_back(a);

                  W[a].push_back(c);
                  W[b].push_back(c);
            }

            findChild(1,0);

            ll ans = 0;

            //show(sum);

            while(sum>S){

                  ll reduce = pq.top().first , cnt = pq.top().second.first , total = pq.top().second.second;
                  pq.pop();

                  sum-=reduce;

                  total/=2;

                  reduce = total*cnt - total/2*cnt;

                  pq.push({reduce,{cnt,total}});
                  ans++;
            }

            cout << ans << endl;
      }

      return 0;
}

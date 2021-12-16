#include<bits/stdc++.h>
#define ll long long int
#define maxn 100005

using namespace std;

vector<ll> G[maxn] , W[maxn];
ll n , k;
set<ll> ans;

int main()
{
      cin >> n >> k;
      for (int i=1 ; i<n ; i++){
            ll a, b , c;
            cin >> a >> b >> c;
            G[a].push_back(b);
            G[b].push_back(a);

            W[a].push_back(c);
            W[b].push_back(c);
      }

      for (int i=0 ; i<k ; i++){
            ll u , mn = 1000000000012 , cnt  = 0;
            cin >> u;
            ans.insert(u);
            for (int j = 0 ; j<G[u].size() ; j++){
                  if (W[u][j]<mn){
                        mn = W[u][j];
                        cnt = 1;
                  }
                  else if (W[u][j]==mn)cnt++;
            }

            if (cnt!=1)continue;

            for (int j=0 ; j<G[u].size() ; j++){
                  if (W[u][j]==mn){
                        ans.insert(G[u][j]);
                  }
            }
      }
      cout << ans.size() << endl;


      return 0;
}

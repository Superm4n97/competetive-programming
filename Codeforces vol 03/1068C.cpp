#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll n,m;
      cin >> n >> m;

      vector < ll> G[n+5];

      for(int i=1; i<=n; i++){
            G[i].push_back(i);
      }

      for (int i=1 ; i<=m ; i++){
            ll a,b;
            cin >> a >> b;

            G[a].push_back(n+i);
            G[b].push_back(n+i);
      }

      for (int i=1 ; i<=n ; i++){
            cout << G[i].size() << endl;
            for (int j=0 ; j<G[i].size() ; j++)cout << i << " " << G[i][j] << endl;
      }


      return 0;
}

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            ll P[n+5] , D[n+5] , C[n+5], dis[n+5] , sol = 1;
            memset(C,-1,sizeof C);
            memset(dis,0,sizeof dis);

            for (int i=1; i<=n ; i++)cin  >> P[i];
            for (int i=1; i<=n ; i++)cin  >> D[i];

            if (P[D[1]] != D[1]){
                  cout << -1 << endl;
                  continue;
            }

            C[D[1]] = 0;
            for (int i=2 ; i<=n ; i++){
                  if (C[P[D[i]]] == -1){
                        sol = 0;
                        break;
                  }
//                  C[D[i]] = i - C[P[D[i]]]-1;
                  dis[D[i]] = i-1;
                  C[D[i]] = dis[D[i]] - dis[P[D[i]]];
            }
            if (!sol){
                  cout << -1 << endl;
                  continue;
            }
            for (int i=1 ; i<=n ; i++)cout << C[i] << " ";
            cout << endl;
      }


      return 0;
}

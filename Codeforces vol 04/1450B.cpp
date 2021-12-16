#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,k;

ll dis(ll x1, ll y1, ll x2, ll y2)
{
      if (abs(x1-x2)+abs(y1-y2)<=k)return true;
      return false;
}

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            cin >> n >> k;

            ll x[n+5] , y[n+5];

            for (int i=0 ; i<n ; i++){
                  cin >> x[i] >> y[i];
            }

            bool sol = false;

            for (int i=0 ; i<n ; i++){
                  ll cnt = 0;
                  for (int j=0 ; j<n ; j++){
                        if (dis(x[i],y[i],x[j],y[j]))cnt++;
                  }
                  if (cnt==n)sol = true;
            }
            cout << (sol?"1":"-1") << "\n";
      }

      return 0;
}

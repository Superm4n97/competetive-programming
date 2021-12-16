#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl
#define maxn 100005
#define inf maxn*10

using namespace std;

ll x[85] , y[85] , cost[maxn] , n,m;

int main()
{
      cin >> n >> m;

      for (int i=0 ; i<n;i++){

            ll a,b;
            cin >> a >> b;

            x[i] = max(0LL,a-b);
            y[i] = min(m , a+b);
      }

      cost[m] = 0;

      for (ll i=m-1 ; i>=0 ; i--){

            cost[i] = m - i;
            for (int j = 0 ; j<n ; j++){
                  if(x[j] <= i+1 && i+1 <= y[j]){

                        cost[i] = cost[i+1];
                        break;
                  }
                  if (i<x[j]){

                        ll extra = x[j]-i-1;
                        ll d = min(m,y[j]+extra);
                        cost[i] = min(cost[i],cost[d]+extra);
                  }
            }
      }
      cout << cost[0] << endl;

}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,m;
            cin >> n >> m;
            ll A[n+5];
            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
            }

            ll x = n;

            for (int i=n ; i>=1 ; i--){
                  if (A[i]==i)x = i-1;
                  else break;
            }

            double ans = 1.0;

            for (int i=1 ; i<=m ; i++){
                  ll a;
                  double p;
                  cin >> a >> p;
                  if (a>=x){
                        ans*=(1.0-p);
                  }
            }
            if (x==0){
                  printf("1.0\n");
                  continue;
            }
            printf("%.9f\n",1.0-ans);
      }

      return 0;
}


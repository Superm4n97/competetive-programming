#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n,m;
            scl(n);
            ll A[n+5] , mx1 = 0 , mx2 = 0 , sum1 = 0 , sum2 = 0;
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  sum1+=a;
                  mx1 = max(mx1,sum1);
            }
            scl(m);
            for (int i=0 ; i<m ; i++){
                  ll a;
                  scl(a);
                  sum2+=a;
                  mx2= max(mx2,sum2);
            }
            cout << mx1+mx2 << endl;
      }

      return 0;
}

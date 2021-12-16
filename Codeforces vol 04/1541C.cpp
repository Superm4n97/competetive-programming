#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);
            vector<ll> v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  v.push_back(a);
            }

            sort(v.begin(),v.end());

            ll sum = 0 , csum[n+5], sub = 0;
            memset(csum,0,sizeof csum);

            for (int i=0 ; i<n-1 ; i++){
                  v[i] = v[i+1]-v[i];
                  sum+=v[i];
            }

            sub = csum[0] = v[0];
            for (int i=1 ; i<n-1 ; i++){
                  csum[i] = v[i]*(i+1) + csum[i-1];
                  sub+=csum[i];
            }

            printf("%lld\n",sum-sub);
      }

      return 0;
}

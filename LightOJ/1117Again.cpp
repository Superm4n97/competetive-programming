#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl;

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n,m;
            scanf("%lld %lld",&n,&m);
            ll A[m+5];
            for (int i=0 ; i<m ; i++)scanf("%lld",&A[i]);
            ll lim = 1 , ans = 0;
            for (int i=0 ; i<m ; i++)lim*=2;

            for (ll i = 1 ; i<lim ; i++){
                  ll cnt = 0 , lcm = 1 , a = i;
                  for(ll j = 0 ; j<m ; j++){
                        if (a&1){
                              cnt++;
                              ll g = __gcd(A[j],lcm);
                              lcm*=A[j];
                              lcm/=g;

                              if (lcm>n)break;
                        }

                        a/=2;
                  }
                  if (lcm>n)continue;


                  if(cnt&1)ans += (n/lcm);
                  else ans -= (n/lcm);
            }
            printf("Case %d: %lld\n",_t,n-ans);
      }

      return 0;
}

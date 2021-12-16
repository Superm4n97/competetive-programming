#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll P[15];

int main()
{
      P[0] = 1;
      for (int i=1 ; i<13 ; i++)P[i] = P[i-1]*2;

      int tc;
      scanf("%d0",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);

            ll dig[12], lim = 1024 , mp[1050] , cnt[1050];
            memset(mp,0,sizeof mp);
            memset(cnt,0,sizeof cnt);
            for (int i=1 ; i<=n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  memset(dig,0,sizeof dig);
                  while(a){
                        ll d = a%10;
                        dig[d] = 1;
                        a/=10;
                  }

                  ll temp = 0;

                  for (int i=0 ; i<=9 ; i++)temp += dig[i]*P[i];
                  mp[temp]++;
            }

//             110 mp[6] = 1
//            1010 mp[10] = 1

            for (ll i=1 ; i<lim ; i++){
                  for (ll j = 1 ; j<lim ; j++){
                        ll num = (i&j);
                        if (num==j){
                              ll bit = __builtin_popcount(num);
                              cnt[j]+=mp[i];
                        }
                  }
            }

            ll ans = 0;

            for (ll i=1 ; i<lim ; i++){
                  ll bit = __builtin_popcount(i);
                  if (bit&1)ans+=(cnt[i]*(cnt[i]-1))/2;
                  else ans-=(cnt[i]*(cnt[i]-1))/2;
            }
            printf("%lld\n",ans);
      }

      return 0;
}

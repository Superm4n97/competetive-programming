#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[1024][1005], A[15],d,len , cnt[12], F[13], maxMask;

ll rec(ll mask, ll rem)
{
      if (mask==maxMask){
            if (rem==0)return 1;
            else return 0;
      }
      if (dp[mask][rem] != -1)return dp[mask][rem];

      ll ret = 0;
      for (ll i=0 ; i<len ; i++){
            ll p = (1LL<<i);
            if ((mask&p)==0){
                  ret += rec((mask|p),(rem*10+A[i])%d);
            }
      }
      return dp[mask][rem] = ret;
}

int main()
{
      F[0] = 1;
      for (ll i = 1; i<12 ; i++)F[i] = F[i-1]*i;

      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            string s;
            cin >> s;
            scanf("%lld",&d);
            len = s.size();
            memset(cnt,0,sizeof cnt);

            for (int i=0 ; i<s.size() ; i++){
                  A[i] = (s[i]-'0');
                  cnt[A[i]]++;
            }

            memset(dp,-1,sizeof dp);
            maxMask = (1LL<<len)-1;
            ll ans = rec(0,0);
            for (int i=0 ; i<10 ; i++){
//                  show(cnt[i]);
                  ans = ans/F[cnt[i]];
            }
            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}

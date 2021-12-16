#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n,p,k,x,y;
            cin >> n >> p >> k;
            string s;
            cin >> s;
            cin >> x >> y;

            ll res[n+5] , ans = 10000000000000016;
            memset(res,0,sizeof res);

            for (int i=n ; i>=p ; i--){
                  if (s[i-1]=='0')res[i]+=x;
                  if (i+k<=n)res[i]+=res[i+k];

                  ll ex = (i-p)*y;
                  ans = min(res[i]+ex , ans);
            }
            cout << ans << "\n";
      }

      return 0;
}

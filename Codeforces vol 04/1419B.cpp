#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 10000000000000012
using namespace std;

ll cnt[1000005];

int main()
{
      int tc;
      cin >> tc;

      ll pre = 2;

      for (ll j=1 ;;j++){

            ll temp  = pre - 1;

            cnt[j] = temp*(temp+1)/2;
            cnt[j]+=cnt[j-1];

            //show(cnt[j]);
            if (cnt[j]>inf){
                 // show(j);
                 // show(cnt[j]);
                  break;
            }

            pre*=2;
      }

      while(tc--){

            ll n;
            cin >> n;

            ll ans = 0;

            for (int i=1 ; i<=32 ; i++){
                  if (cnt[i]>n)break;
                  ans = i;
            }

            cout << ans << endl;
      }

      return 0;
}

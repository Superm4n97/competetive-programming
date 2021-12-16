#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll m;

int main()
{
      cin >> m;

      ll b = 8 , e = 1e16 , ans = -1;

      while(b<=e){
            ll mid = (b+e)/2 , cnt  = 0;

            //show(mid);

            for (ll i=2 ;;i++){
                  ll start = i*i*i;
                  if (start>mid)break;
                  cnt+=(mid/start);
            }

            if (cnt>=m){
                  if(cnt==m){
                        if (ans == -1)ans = mid;
                        else ans = min(ans,mid);
                  }
                  e = mid-1;
            }
            else b = mid+1;
      }

      cout << ans << endl;

      return 0;
}

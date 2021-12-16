#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll A[200];
      for (int i=1 ; i<=n ; i++)cin >> A[i];

      ll ans = 100000000000000017;

      for (int x = 1 ; x<=100 ; x++){

            ll cnt = 0;

            for (int i=1 ; i<=n ; i++){

                  ll temp = abs(x-i) + x-1+i-1;
                  temp*=2;
                  cnt+=temp*A[i];
            }
            ans = min(ans,cnt);
      }

      cout << ans << endl;

      return 0;
}

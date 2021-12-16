#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n, t, k;
      cin >> n >> t;
      cin >> k;

      ll b = 1 , e = n, ans = n+1;
      while(b<=e){
            ll mid = (b+e)/2;
            cout << "? 1" << " " << mid << endl;
            fflush(stdout);
            ll a;
            cin >> a;
            a = mid-a;
            if (a>=k){
                  ans = min(ans,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      cout << "! " << ans << endl;
      fflush(stdout);


      return 0;
}

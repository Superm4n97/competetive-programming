#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;
      ll A[n+5];

      for (ll i=0 ; i<n ; i++)cin >> A[i];

      ll gcd = A[0];

      for (ll i=1 ; i<n ; i++){
            gcd = __gcd(gcd,A[i]);
      }

      //show(gcd);

      ll ans = 0;

      for (ll i=1 ; i*i<=gcd ; i++){

            if (gcd%i==0){
                  if (i==gcd/i)ans++;
                  else ans+=2;

                  //show(i);
                  //show(i*i);
            }
      }
      cout << ans << endl;


      return 0;
}

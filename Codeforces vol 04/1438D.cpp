#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      ll A[n+5];

      for (int i=1 ; i<=n ; i++)cin >> A[i];

      if (n%2==0){
            ll x = A[1], id;
            ll sol = false;
            for (ll i=2 ; i<=n ;i++)x = (x^A[i]);

            //show(x);

            if (x!=0)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  cout << n-2 << endl;
                  for (ll i = 3 ; i<=n ; i+=2)cout << 2 << " " << i << " " << i+1 << endl;
                  for (ll i = 3 ; i<=n ; i+=2)cout << 2 << " " << i << " " << i+1 << endl;
            }
      }
      else {
            cout << "YES" << endl;
            cout << (n-1) << endl;
            for (ll i=2 ; i<=n; i+=2)cout << 1 << " " << i << " " << i+1 << endl;
            for (ll i=2 ; i<=n; i+=2)cout << 1 << " " << i << " " << i+1 << endl;
      }


      return 0;
}
/**
101
100
010
011


**/

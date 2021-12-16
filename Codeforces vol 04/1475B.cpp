#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);

            ll d = n/2020 , rem = n%2020;
            if (d>=rem)cout << "YES" << endl;
            else cout << "NO" << endl;
      }

      return 0;
}

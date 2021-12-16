#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n, id = 2;
            cin >> n;
            if (n&1){
                  cout << "3 1 2 ";
                  id = 5;
            }

            for (int i=id ; i<=n ; i+=2)cout << i << " " << i-1 << " ";
            cout << endl;
      }

      return 0;
}

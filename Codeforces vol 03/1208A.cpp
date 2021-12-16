#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a,b,c,n;
            cin >> a >> b >> n;
            c = a^b;

            n%=3;

            if (n==0)cout << a << endl;
            else if (n==1)cout << b << endl;
            else cout << c<< endl;
      }

      return 0;
}

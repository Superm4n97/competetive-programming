#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll a,b;
            cin >> a >> b;
            ll d = abs(a-b);
            if (d%2==1)cout << -1 << endl;
            else if (d==0 && a==0)cout << 0 << endl;
            else if (d==0)cout << 1 << endl;
            else cout << 2 << endl;
      }

      return 0;
}

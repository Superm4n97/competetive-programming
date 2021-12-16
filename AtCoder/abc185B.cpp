#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m,t , pre  = 0 , cap;
      cin >> n >> m >> t;
      cap = n;

      bool sol = true;
      for (int i=0 ; i<m ; i++){
            ll a,b;
            cin >> a >> b;

            n = max(0LL,n-a+pre);
            if (n==0)sol = false;
            n+=(b-a);
            n = min(n,cap);
            pre = b;
      }

      n = max(0LL,n-t+pre);
      if (n==0)sol = false;

      if (!sol)cout << "No" << endl;
      else cout << "Yes" << endl;

      return 0;
}

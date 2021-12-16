#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n,x,a,b;
            cin >> n >> x >> a >> b;

            if (a>b)swap(a,b);

            ll ans = b-a;

            ll temp = a-1+n-b;
            ans+=min(x,temp);

            cout << ans << endl;
      }

      return 0;
}

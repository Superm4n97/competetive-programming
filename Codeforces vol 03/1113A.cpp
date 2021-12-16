#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,u;
      cin >> n >> u;

      ll ans = min(u,n-1);
      ll cnt = ans;
      for (int i=2 ; i<=n  ;i++){
            if (cnt<n-1)ans+=i , cnt++;
      }

      cout << ans << endl;

      return 0;
}

/// 1 1 2 3 4

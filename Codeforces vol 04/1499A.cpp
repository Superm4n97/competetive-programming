#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

bool Test(ll k1, ll k2, ll x)
{
      ll temp  = min(k1,k2) + (max(k1,k2)-min(k1,k2))/2;
      if (temp>=x)return true;
      return false;
}

int main()
{
      int tc;
      scanf("%d",&tc);
      while(tc--){
            ll n,k1,k2,w,b;
            cin >> n >> k1 >> k2 >> w >> b;
            if (Test(k1,k2,w) && Test(n-k1,n-k2,b))cout << "YES\n";
            else cout << "NO\n";
      }

      return 0;
}

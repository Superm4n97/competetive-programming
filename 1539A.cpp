#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            ll n,x,t;
            cin >> n >> x >> t;
            ll in = min(t/x,n);
            cout << (n-in)*in + in*(in-1)/2 << endl;
      }

      return 0;
}

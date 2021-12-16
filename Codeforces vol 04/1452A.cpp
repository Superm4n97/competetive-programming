#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll a,b;
            cin >> a >> b;

            cout << min(a,b)*2+max((max(a,b)-min(a,b))*2-1 , 0LL) << endl;
      }
}

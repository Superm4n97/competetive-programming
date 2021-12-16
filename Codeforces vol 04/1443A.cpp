#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

      ll mp[500];

int main()
{
      ll tc;
      cin >> tc;

      mp[8] = mp[16] = mp[32] = mp[64] = mp[128] = mp[256] = 1;

      while(tc--){

             ll n;
             cin >> n;

             ll cnt = 0;

             for (int i=0 ; i<n ; i++)cout << 4*n-i*2 << " ";
             cout << endl;
      }

      return 0;
}

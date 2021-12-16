#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n,k;
            cin >> n >> k;

            cout << k+(n-1)*9 << endl;
      }



      return 0;
}

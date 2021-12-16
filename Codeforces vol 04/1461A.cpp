#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,k;
            cin >> n >> k;

            for (int i=0 ; i<n ; i++){
                  if (i%3==0)cout << 'a';
                  else if (i%3==1)cout << 'b';
                  else cout << 'c';
            }
            cout << endl;
      }

      return 0;
}

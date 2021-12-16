#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n,k;
            cin >> n >> k;

            ll A[n+5] , mn = 1000000000000015 , id;

            for (int i=1 ; i<=n ; i++){
                  cin >> A[i];
                  if (A[i]<mn){
                        mn = A[i];
                        id = i;
                  }
            }

            ll ans  = 0;

            for (int i=1;  i<=n ; i++){
                  if (i==id)continue;

                  ans+=(k-A[i])/A[id];
            }

            cout << ans << endl;
      }

      return 0;
}

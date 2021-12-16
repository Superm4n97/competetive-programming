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

            ll A[n+5] , curr = 0 , mn = 1000000009 , cnt = 0;
            bool solution = false;

            for (int i=1 ; i<=n ; i++)cin >> A[i];

            if (n==1){
                  if (A[1]==k)cout << "yes" << endl;
                  else cout << "no" << endl;

                  continue;
            }

            for (int i=1; i<=n; i++){
                  if (A[i]>=k){
                        curr++;
                        if (mn<=curr)solution = true;
                        mn = min(curr,mn);
                        if (A[i]==k)cnt=1;
                  }
                  else curr--;
            }

            cout << (cnt&solution?"yes":"no") << endl;
      }

      return 0;
}

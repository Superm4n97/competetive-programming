#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;
            ll A[n+5] , ans[n+5];

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  cin >> a;

                  A[a] = i;
            }

            ll l = 1 , r = n;

            for (int i = n; i>=1 ; i--){

                  /*show(i);
                  show(l);
                  show(r);
                  cout << endl;
                  */

                  if (A[i]>=l && A[i]<=r){

                        if(r-l+1==i) ans[i] = 1;
                        else ans[i] = 0;

                        if (A[i]==l)l++;
                        else if (A[i]==r)r--;
                        else {

                              ll p = l , q = A[i]-1 , x = A[i]+1 ,y = r;

                              if (A[1]>=p && A[1]<=q)l = p , r = q;
                              else l = x , r = y;
                        }
                  }
                  else ans[i] = 0;
            }

            for (int i=1 ; i<=n ; i++)cout << ans[i];
            cout << endl;
      }



      return 0;
}

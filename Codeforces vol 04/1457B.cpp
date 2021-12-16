#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int t;
      cin >> t;

      while(t--){

            ll n,k;
            cin >> n >> k;

            ll A[n+5] , ans = n;
            for (int i=1 ; i<=n ; i++)cin >> A[i];

            for (int c = 1 ; c<=100 ; c++){

                  ll temp = 0 , res = 0;
                  for (int i=1 ; i<=n ; i++){

                        if (i>temp && A[i]!=c){
                              temp=i+k-1;
                              res++;
                        }
                  }
                  ans = min(ans,res);
            }
            cout << ans << "\n";
      }

      return 0;
}

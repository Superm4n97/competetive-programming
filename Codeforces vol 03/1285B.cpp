#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;
            ll A[n+5] , total = 0;
            A[0] = 0;

            for (int i=1; i<=n; i++){
                  cin >> A[i];
                  total+=A[i];
            }

            ll sum = 0 , mx = A[1] , x = 0 , sol = 0;

            for (int i=1 ; i<=n ; i++){


                  //show(i);
                  //show(sol);

                  sum+=A[i];

                  if (sum<=0){
                        sum = 0;
                        x = 1;
                  }
                  if (sum>total){
                        x = 1;
                        sol = 1;
                        //show(sum);
                        //show(total);
                  }
                  if (sum==total){
                        if (i<n || x==1){
                              sol = 1;
                              x = 1;
                              //show(sum);
                        }
                  }
            }

            if (sol==1)cout << "NO" << endl;
            else cout <<"YES" << endl;
      }


      return 0;
}

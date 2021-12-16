#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,m;
            cin >> n >> m;

            ll mn = 10000 , neg = 0 , sum = 0;

            for (int i=1 ; i<=n ; i++){
                  for (int j=1 ; j<=m ; j++){

                        ll a;
                        cin >> a;

                        if (a>0){
                              sum+=a;
                              mn = min(mn,a);
                        }
                        else {
                              sum-=a;
                              mn = min(mn,-a);
                              neg++;
                        }
                  }
            }
//
//            show(sum);
//            show(mn);

            if (neg%2==0)cout <<  sum << endl;
            else {
                  cout << sum - (2*mn) << endl;
            }
      }

      return 0;
}

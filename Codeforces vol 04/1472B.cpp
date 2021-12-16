#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){

            ll n , sum = 0 , one = 0;
            cin >> n;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  if (a%2)one++;
                  sum+=a;
            }

            if (sum%2)cout << "NO" << endl;
            else {
                  if (sum%4==0 || one)cout << "YES" << endl;
                  else cout << "NO" << endl;
            }
      }

      return 0;
}

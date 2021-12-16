#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,m;
            cin >> n >> m;

            ll temp = m , tut = 0 , ans = 0;

            for (int i=1 ; i<=9 ;i++){
                  tut+= (temp%10);
                  temp+=m;
            }

            ll x = m*10;

            temp = n/x;
            ans = temp*tut;

            temp = n%x;
            ll y = m;

            while(y<=temp){
                  ans+= (y%10);
                  y+=m;
            }

            cout << ans << endl;
      }


      return 0;
}

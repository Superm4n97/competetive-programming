#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll d,k;
            cin >> d >> k;
            ll lose = 0 , win = 0;

            ll sol = false;

            for (ll i = d ; i>=0 ; i--){
            //show(i);
                  ll j = sqrt(d*d - i*i);
                  if (j>i)break;

                  if (i==j){
                        sol = true;
                        break;
                  }

                  ll temp = i-j;
                  if (temp%(k+1)==0)lose++;
                  else win++;
            }

            show(lose);
            show(win);
            show(sol);
            cout << endl;

      }

      return 0;
}

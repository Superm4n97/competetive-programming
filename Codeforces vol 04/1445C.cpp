#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll p,q;
            cin >> p >> q;


            if (p%q!=0){
                  cout << p << "\n";
                  continue;
            }

            ll mx = 0;

            for (ll i = 2 ; i*i<=q ; i++){
                  //if (i==3)show(i);
                  if (q%i==0){

                        ll cnt = 0 , x = 1 , temp = p , tut = q;
                        while(q%i==0){
                              q/=i;
                              cnt++;
                              x*=i;
                        }

                        while(temp%i==0)temp/=i;

                        temp*=x;
                        temp/=i;

                        mx = max(mx,temp);
                  }
            }

            if (q!=1){
                  ll cnt = 0 , x = 1 , temp = p , tut = q;
                  while(tut%q==0){
                        tut/=q;
                        cnt++;
                        x*=q;
                  }

                  while(temp%q==0)temp/=q;
                  temp*=x;
                  temp/=q;

                  mx = max(mx,temp);
            }

            cout << mx <<"\n";
      }

      return 0;
}

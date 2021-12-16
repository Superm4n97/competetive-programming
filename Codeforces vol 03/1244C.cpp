#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,p,w,d;
      cin>> n >> p>> w>> d;

      bool sol = false;
      ll x,y,z;

      for (ll i = 0; i<w ; i++){

            ll rem = p-i*d;
            if(rem%w==0 && rem>=0){
                  if(rem/w+i<=n){

                        sol = true;
                        x = rem/w;
                        y = i;
                        z = n-x-y;

                        break;
                  }
            }
      }

      if(!sol)cout << -1 << endl;
      else{
            cout<< x << " " << y << " "  << z <<endl;
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n , x;
            cin >> n >> x;

            ll nonzero = 0 , sum = 0 , eq = 0;

            for (int i=1 ; i<=n ; i++){
                  ll a;
                  cin >> a;

                  ll temp;

                  if (a<x){
                        temp = x - a;
                        sum+=temp;
                        nonzero = 1;
                  }
                  else if (a>x){
                        temp = a-x;
                        sum-=temp;
                        nonzero = 1;
                  }
                  else {
                        eq++;
                  }
            }

            if (nonzero==0)cout << 0 << endl;
            else if (sum==0 || eq)cout << 1 << endl;
            else cout << 2 << endl;
      }

      return 0;
}

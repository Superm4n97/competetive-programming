#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n, one, two, solotwo = 0 , ans = 0;
      cin >> n >> one >> two;

      for (int i=0 ; i<n ;i++){

            ll a;
            cin >> a;

            if (a==1){
                  if (one)one--;
                  else if(two){
                        two--;
                        solotwo++;
                  }
                  else if (solotwo){
                        solotwo--;
                  }
                  else ans++;
            }
            else {
                  if (two)two--;
                  else ans+=2;
            }
      }

      cout << ans << endl;

      return 0;
}
/**

**/

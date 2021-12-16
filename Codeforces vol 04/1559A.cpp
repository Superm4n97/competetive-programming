#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n,x;
            cin >> n;

            for (int i=0 ; i<n;  i++){
                  ll a;
                  cin >>a;
                  if (i==0)x= a;
                  else x = (a&x);
            }
            cout << x << endl;
      }

      return 0;
}

#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >>  n;
            vector < ll > v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            for (int i=n-1 ; i>=0 ; i--)cout << v[i] << " ";
            cout << endl;
      }


      return 0;
}

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            vector<ll> v;
            for (int i=0 ; i<7 ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            cout << v[0] << " " << v[1] << " ";
            if (v[0]+v[1]!=v[2])cout << v[2] << endl;
            else cout << v[3] << endl;
      }

      return 0;
}

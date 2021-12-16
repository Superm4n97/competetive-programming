#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            vector < ll > v;
            cin >> n;

            for (int i=0 ; i<n; i++){
                  ll a;
                  cin >> a;

                  v.push_back(a);
            }

            sort(v.begin() , v.end());

            ll i = 0 , cnt = 0;

            while(i+v[i]-1 < n){

                  ll id = i+v[i]-1;
                  if(v[i]==v[id]){

                        cnt++;
                        i = id+1;

                        if (i>=n)break;
                  }
                  else {

                        v[i] = v[id];
                  }
            }
            cout << cnt << endl;
      }


      return 0;
}

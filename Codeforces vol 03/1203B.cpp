#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            vector < ll > v;

            map < ll , ll > mp;

            for (int i=0 ; i<4*n ; i++){

                  ll a;
                  cin >> a;

                  v.push_back(a);

                  mp[a]++;
            }

            bool sol = true;

            for (int i=0 ; i<4*n ; i++){

                  if (mp[v[i]]%2)sol = false;
            }

            if (!sol){
                  cout << "NO" << endl;
                  continue;
            }

            sort(v.begin(),v.end());

            set < ll > st;

            ll i = 0 , j = 4*n-1;

            while(i<j){
                  st.insert(v[i]*v[j]);
                  i+=2;
                  j-=2;
            }

            if (st.size()==1)cout << "YES" << endl;
            else cout << "NO" << endl;
      }


      return 0;
}

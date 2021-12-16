#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n,k;
            string s;
            vector <ll> v;

            cin >> n >> k;
            cin >> s;

            ll w = 0 , l = 0;

            for (int i=0 ; i<n ; i++)if (s[i]=='W')w++;

            if(w==0){

                  k = min(n,k);
                  cout << (k-1)*2 + 1 << endl;
            }
            else {

                  ll i  = -1;
                  while(s[i+1]=='L')i++;

                  ll temp = -1;

                  if (l!=0)temp = i+1;

                  i++;
                  l = 0;

                  while(i<n){

                        if (s[i]=='W')l = 0;
                  }
            }
      }


      return 0;
}

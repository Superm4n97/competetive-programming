#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n, sum = 0;
            cin >> n;

            vector < ll > v;

            for (int i = 0; i<n; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
                  sum+=a;
            }

            if (sum==0)cout << "NO" << endl;
            else{
                  if(sum<0)sort(v.begin(),v.end());
                  else sort(v.rbegin(),v.rend());

                  cout << "YES" << endl;
                  for (int i = 0;i<n ; i++)cout << v[i] << " ";
                  cout << endl;
            }
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n,l,r,k;
            cin >> n >> l >> r >> k;

            vector<ll>v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }

            sort(v.begin(),v.end());

            ll cnt = 0;

            for (int i=0 ; i<n ; i++){
                  if (v[i]>=l && v[i]<=r && v[i]<=k){
                        cnt++;
                        k-=v[i];
                  }
            }
            cout << cnt << endl;
      }

      return 0;
}

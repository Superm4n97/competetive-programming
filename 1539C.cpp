#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,k,x , ans = 0;
      cin >> n >> k >> x;
      vector<ll> v,vs;

      for (int i=0 ; i<n ; i++){
            ll a;
            cin >> a ;
            v.push_back(a);
      }

      sort(v.begin(),v.end());

      for (int i=1 ; i<n; i++){
            if ((v[i]-v[i-1]-1)/x > 0)vs.push_back((v[i]-v[i-1]-1)/x);
      }
      if (!vs.empty())sort(vs.begin(),vs.end());

      ans = (ll)vs.size()+1;

//      show(ans);
//      for (int i=0 ; i<vs.size() ; i++){
//            cout << vs[i] << " ";
//      }
//      cout << endl;

      for (int i=0 ; i<vs.size() ; i++){
            k-=vs[i];
            if (k>=0)ans--;
      }
      cout << ans << endl;

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

unordered_map<ll,ll> mp;

void mrg(vector<ll> v)
{
      ll n = v.size();
      vector<ll> new1,new2;

//      show(n);

      ll sum = 0;
      ll mid = (v[0]+v[n-1])/2;
      for (int i=0 ; i<n ; i++){
            sum += v[i];
            if (v[i]<=mid)new1.push_back(v[i]);
            else new2.push_back(v[i]);
      }
      mp[sum] = 1;
      if(new2.empty())return;

      mrg(new1);
      mrg(new2);
      return;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,q;
            cin >> n >> q;
            vector < ll> v;

            for (int i=0 ; i<n ; i++){
                  ll a;
                  cin >> a;
                  v.push_back(a);
            }
            sort(v.begin(),v.end());

            mrg(v);

            while(q--){
                  ll s;
                  cin >> s;
                  if (mp[s]==1){
                        printf("Yes\n");
                  }
                  else printf("No\n");
            }

            mp.clear();
      }

      return 0;
}

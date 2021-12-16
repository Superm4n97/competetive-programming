#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n , m;
vector <ll> v,csum;

ll bs(ll value)
{
      ll ret = -1 , b = 0 , e = n-1;
      while(b<=e){

            ll mid = (b+e)/2;

            if (v[mid]>=value){
                  ret = max(ret,mid);
                  b = mid+1;
            }
            else {
                  e = mid-1;
            }
      }

      return ret+1;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            v.clear();
            csum.clear();

            vector <pair<ll,ll> > vp;

            cin >> m >> n;
            for (int i=0 ; i<n ; i++){

                  ll a, b;
                  cin >> a >> b;
                  v.push_back(a);
                  vp.push_back({a,b});
            }

            sort(v.rbegin(),v.rend());
            csum = v;
            ll ans = 0;

            for (int i=1 ; i<n ; i++)csum[i] += csum[i-1];

            for (int i=0 ; i<n ; i++){

                  ll a = vp[i].first , b = vp[i].second;
                  ll num = bs(b) , sat = a;

                  if (num==0){
                        sat += (m-1)*b;
                        ans = max(ans,sat);
                        continue;
                  }

                  if (a>=b){
                        ll x = min(num-1,m-1) , temp = 0;
                        if (x>0) temp = csum[x-1];
                        sat += temp + (m-1 - x)*b;

                        if (v[x]<a)sat+=v[x]-a;
                        ans = max(ans,sat);
                  }
                  else {
                        ll x = min(num,m-1) , temp = 0;
                        if (x>0) temp = csum[x-1];
                        sat+=temp + (m-1-x)*b;

                        ans = max(ans,sat);
                  }
            }
            cout << ans << endl;
      }


      return 0;
}

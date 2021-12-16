#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m,d , ans[200005];
vector < pair < ll,ll > > v;

int main()
{
      cin >> n >> m >> d;

      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;

            v.push_back({a,i});
      }

      sort(v.begin() , v.end());

      ll b = 1 , e = n , ret = 1;
      while(b<=e){

            ll mid = (b+e)/2;
            bool sol = false;

            for (int i=mid-1 ; i<n; i++){
                  if (v[i].first - v[i-mid+1].first <= d){
                        sol = true;
                        //show(i);
                        //show(mid);
                  }
            }

            if (sol){
                  b = mid+1;
                  ret = max(ret,mid);
            }
            else e = mid-1;
      }

      for (int i=0 ; i<n ; i++){
            ans[v[i].second] = i%ret;
      }

      cout << ret << endl;
      for (int i=0 ;i<n ; i++){
            cout << ans[i]+1 << " ";
      }
      cout << endl;


      return 0;
}
/**

**/

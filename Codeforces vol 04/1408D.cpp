#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2004
#define inf 1000000000000000018

using namespace std;

ll a[maxn] , b[maxn] , c[maxn], d[maxn] , n , m, max_y[4000006];

vector <pair<ll,ll> > vp;

int main()
{
      cin >> n >> m;
      for (int i=1 ; i<=n ; i++)cin >> a[i] >> b[i];
      for (int i=1 ; i<=m ; i++)cin >> c[i] >> d[i];

      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if(a[i]<=c[j] && b[i]<=d[j])vp.push_back({c[j]+1-a[i],d[j]+1-b[i]});
            }
      }

      if (vp.empty()){
            cout << 0 << endl;
            return 0;
      }

      sort(vp.begin(),vp.end());

      n = vp.size();
      max_y[n-1] = vp[n-1].second;

      for (int i=n-2 ; i>=0 ; i--)max_y[i] = max(max_y[i+1],vp[i].second);

      ll ans = max_y[0];

      for (int i=0 ; i<n ; i++)ans = min(ans,vp[i].first+max_y[i+1]);

      cout << ans << endl;


      return 0;
}

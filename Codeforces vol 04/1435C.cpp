#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define inf             10000000000000016
using namespace std;

ll S[8] , F[maxn] , n , fre[maxn] , cnt = 0 , ans = inf;
vector <pair<ll,ll> > v;

int main()
{
      for (int i=1 ; i<=6 ; i++)cin >> S[i];
      cin >> n;
      for (int i=1 ; i<=n ; i++){
            ll a;
            cin >> a;
            for (int j=1 ; j<=6 ; j++)v.push_back({a-S[j],i});
      }

      sort(v.begin(),v.end());

      ll b = 0 , e = 0;
      while(e<v.size()){

            ll a = v[e].first , id = v[e].second;
            fre[id]++;

            if (fre[id]==1)cnt++;

            while(fre[v[b].second]>1){
                  fre[v[b].second]--;
                  b++;
            }

            if (cnt==n){
                  ans = min(ans,v[e].first-v[b].first);
            }

            e++;
      }

      cout << ans << endl;

      return 0;
}

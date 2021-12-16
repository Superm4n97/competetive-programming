#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 100000000000014

using namespace std;

ll n[4],m[5] , ans = inf;
vector<pair<ll,ll> >v[5] , E[5];
map <pair<ll,ll> , ll> mp[5];

void solve(ll pos)
{
      sort(v[pos-1].begin(),v[pos-1].end());
      for (int i=0 ; i<n[pos] ; i++){
            bool done = false;
            for (int j=0 ; j<n[pos-1] ; j++){
                  if (mp[pos][{v[pos-1][j].second,v[pos][i].second}] == 0){
                        v[pos][i].first += v[pos-1][j].first;
                        if (pos==3)ans = min(ans,v[pos][i].first);
                        done = true;
                        break;
                  }
            }
            if (!done)v[pos][i].first = inf;
      }
}

int main()
{
      for (int i=0 ; i<4 ; i++)scanf("%I64d",&n[i]);
      for (int i=0 ; i<4 ; i++){
            for (ll j=1 ; j<=n[i] ; j++){
                  ll a;
                  scanf("%I64d",&a);
                  v[i].push_back({a,j});
            }
      }

      scanf("%I64d",&m[1]);
      for (int i=0 ; i<m[1] ; i++){
            ll a,b;
            scanf("%I64d %I64d",&a,&b);
            E[1].push_back({a,b});
            mp[1][{a,b}] = 1;
      }

      scanf("%I64d",&m[2]);
      for (int i=0 ; i<m[2] ; i++){
            ll a,b;
            scanf("%I64d %I64d",&a,&b);
            E[2].push_back({a,b});
            mp[2][{a,b}] = 1;
      }

      scanf("%I64d",&m[3]);
      for (int i=0 ; i<m[3] ; i++){
            ll a,b;
            scanf("%I64d %I64d",&a,&b);
            E[3].push_back({a,b});
            mp[3][{a,b}] = 1;
      }

      for (int i=1 ; i<4 ; i++)solve(i);

      if (ans>=inf)printf("-1\n");
      else printf("%I64d\n",ans);

      return 0;
}

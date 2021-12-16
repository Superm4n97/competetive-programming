#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,m , P[maxn] , A[maxn] , mn = 10000000000000000 , id;

ll findParent(ll a)
{
      if (P[a] == a)return a;

      return P[a] = findParent(P[a]);
}

ll makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a!=b)P[a] = b;
}

int main()
{
      for (int i=0 ; i<maxn ; i++)P[i] = i;

      cin >> n >> m;

      for (int i=1 ; i<=n ; i++){
            cin >> A[i];
            if (A[i]<mn){
                  mn = A[i];
                  id = i;
            }
      }

      vector < pair <ll, pair <ll,ll> > > v;

      for (int i=1 ; i<=n ; i++){
            if (i==id)continue;

            v.push_back({A[id]+A[i] ,{id , i}});
      }

      for (int i=1 ; i<=m ; i++){
            ll a,b , c;
            cin >> a >> b >> c;

            v.push_back({c,{a,b}});
      }

      sort(v.begin() , v.end());

      ll ans = 0;

      for (int i=0 ; i<v.size() ; i++){
            ll c = v[i].first , b = v[i].second.first , a = v[i].second.second;

            if (findParent(a)==findParent(b))continue;
            ans+=c;
            makeParent(a,b);
      }

      cout << ans << endl;


      return 0;
}

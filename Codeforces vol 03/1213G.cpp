#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

ll n,m, P[maxn] ,  sz[maxn] , ans[maxn] , total = 0;
vector < pair < ll , pair < ll , ll > > > edge;
vector < pair < ll,ll > > query;

ll findParent(ll a)
{
      if (P[a]==a)return a;
      return P[a] = findParent(P[a]);
}

ll makeParent(ll a, ll b)
{
      a = findParent(a);
      b = findParent(b);

      if (a!=b){
            P[b] = a;
            sz[a]+=sz[b];
      }
}

ll calculation(ll a)
{
      return a*(a-1)/2;
}

int main()
{
      cin >> n >> m;

      for (int i=0 ; i<=n+3 ; i++){
            P[i] = i;
            sz[i] = 1;
      }

      for(int i = 1 ; i<n ; i++){
            int a,b,w;
            cin >> a >> b >> w;

            edge.push_back({w,{a,b}});
      }

      for (int i = 1; i<=m ; i++){
            ll a;
            cin >> a ;
            query.push_back({a,i});
      }

      sort(query.begin(),query.end());
      if (!edge.empty())sort(edge.begin(),edge.end());

      queue < pair < ll , pair <ll,ll> > > q;

      for (int i=0 ; i<n-1 ; i++)q.push(edge[i]);

      for (int i=0 ; i<m ; i++){

            while(!q.empty()){

                  ll w = q.front().first , a = q.front().second.first , b = q.front().second.second;
                  if (w>query[i].first)break;

                  q.pop();

                  a = findParent(a);
                  b = findParent(b);

                  if (a!=b){
                        total = total - calculation(sz[a]) - calculation(sz[b]);
                        makeParent(a,b);
                        total+=calculation(sz[a]);
                  }
            }

            ans[query[i].second] = total;
      }

      for (int i=1 ; i<=m ; i++)cout << ans[i] << " ";
      cout << endl;


      return 0;
}

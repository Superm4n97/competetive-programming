#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

vector < ll > G[maxn];
vector < pair < ll,ll> > query[maxn];
ll S[maxn*4], lazy[maxn*4], n, ans[maxn];

void relax(ll node, ll b, ll e)
{
      S[node]+=lazy[node];

      if (b!=e){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
      }

      lazy[node] = 0;

      return;
}

ll findresultOfpoint(ll node, ll b, ll e, ll id)
{
      relax(node,b,e);

      if (b>id || e<id)return 0;

      if (b==id && e==id)return S[node];

      ll mid = (b+e)/2;

      return findresultOfpoint(node*2,b,mid,id)+findresultOfpoint(node*2+1,mid+1,e,id);
}

void update(ll node, ll b, ll e, ll x, ll y, ll val)
{
      if (lazy[node])relax(node,b,e);

      if(b>y || e<x) return;

      if(b>=x && e<=y){
            lazy[node] = val;
            relax(node,b,e);

            return;
      }

      ll mid = (b+e)/2;

      update(node*2,b,mid,x,y,val);
      update(node*2+1,mid+1,e,x,y,val);

      S[node] = S[node*2]+S[node*2+1];

      return;
}

void dfs(ll u, ll p, ll d)
{
      for (int i = 0 ; i<query[u].size() ; i++)
            update(1,1,n,d,min(n,d+query[u][i].first),query[u][i].second);

      ans[u] = findresultOfpoint(1,1,n,d);

      for (int i=0 ; i<G[u].size(); i++){

            ll v = G[u][i];
            if (v!=p)dfs(v,u,d+1);
      }

      for (int i = 0 ; i<query[u].size() ; i++)
            update(1,1,n,d,min(n,d+query[u][i].first),query[u][i].second*-1);

      return;
}

int main()
{
      //cin >> n;
      scanf("%I64d",&n);
      for (int i =1; i<n ; i++){

            ll a,b;
            //cin >> a >> b;
            scanf("%I64d %I64d",&a,&b);

            G[a].push_back(b);
            G[b].push_back(a);
      }


      ll q;
      //cin >> q;
      scanf("%I64d",&q);

      while(q--){

            ll u, a,b;
            //cin >> u >> a >> b;
            scanf("%I64d %I64d %I64d",&u,&a,&b);

            query[u].push_back({a,b});
      }

      dfs(1,0,1);

      for (int i=1 ; i<=n; i++)printf("%I64d ",ans[i]);
            //cout << ans[i] << " ";

      return 0;
}

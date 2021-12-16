#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x)         cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            200005

using namespace std;

pair <ll ,ll > segtree[4*maxn];
vector < ll > G[maxn] , test[maxn];
map < pair < ll , ll > , ll > mp;
vector < pair < ll , ll > > edge;
ll n , m , indegree[maxn] , falsedegree[maxn] , vis[maxn];

void clean()
{
      for (int i=0 ; i<n*4+3 ; i++)segtree[i].first = segtree[i].second = 0;
      for (int i=0 ; i<=n+5 ; i++){
            G[i].clear();
            test[i].clear();
            indegree[i] = falsedegree[i] = 0;
            vis[i] = 0;
      }
      edge.clear();
      mp.clear();

}

bool valid(ll u)
{
      vis[u] = 1;
      bool ret = false;

      for (int i=0 ; i<test[u].size() ; i++){
            ll v = test[u][i];

            if (vis[v])return true;

            ret|=valid(v);
      }

      return ret;
}


void build(ll node, ll b, ll e)
{
      if (b==e){
            segtree[node].first = indegree[b];
            segtree[node].second = b;
            return;
      }

      ll mid = (b+e)/2;

      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      if(segtree[node*2].first <= segtree[node*2+1].first){
            segtree[node].first = segtree[node*2].first;
            segtree[node].second = segtree[node*2].second;
      }
      else{
            segtree[node].first = segtree[node*2+1].first;
            segtree[node].second = segtree[node*2+1].second;
      }

      return;
}

void update(ll node, ll b, ll e, ll id , ll val)
{
      if (b>id || e<id)return;
      if (b==e && b==id){
            segtree[node].first = val;
            return;
      }

      ll mid = (b+e)/2;

      update(node*2,b,mid , id,val);
      update(node*2+1,mid+1,e,id,val);

      if(segtree[node*2].first <= segtree[node*2+1].first){
            segtree[node].first = segtree[node*2].first;
            segtree[node].second = segtree[node*2].second;
      }
      else{
            segtree[node].first = segtree[node*2+1].first;
            segtree[node].second = segtree[node*2+1].second;
      }

      return;
}

int main()
{
      int tc;
      scd(tc);

      while(tc--){
            scl(n);
            scl(m);
            clean();

            for (int i =0;i<m ; i++){
                  ll t, a,b;
                  scl(t);
                  scll(a,b);

                  if (t==0){
                        G[a].pb(b);
                        G[b].pb(a);
                  }
                  else {
                        G[a].pb(b);
                        test[a].pb(b);
                        indegree[b]++;
                        falsedegree[b]++;

                        mp[{a,b}] = 1;
                        mp[{b,a}] = 2;
                  }
                  edge.push_back({a,b});
            }

            bool sol = true;
            vector < ll > check;
            queue < ll > q;

            for (int i=1 ; i<=n ; i++){
                  if (falsedegree[i]==0)q.push(i);
            }
            while(!q.empty()){

                  ll u = q.front();

                  //show(u);
                  q.pop();

                  check.push_back(u);

                  for (int i=0 ; i<test[u].size() ; i++){
                        ll v = test[u][i];
                        falsedegree[v]--;
                        if (falsedegree[v]==0)q.push(v);
                  }
            }

            //show(check.size());

            if (check.size()<n){
                  cout << "NO" << endl;
                  continue;
            }

            build(1,1,n);

            for (int i=0 ; i<=n+4 ; i++)vis[i] = 0;

            while(true){

                  ll index = segtree[1].second , in = segtree[1].first;

                 // show(index);
                 // show(in);

                  if (in>=inf)break;

                  for (int i=0 ; i<G[index].size() ; i++){

                        ll v = G[index][i];
                        if (mp[{index,v}]==0){
                              mp[{index,v}] = 1;
                              mp[{v,index}] = 2;
                              indegree[v]++;
                        }
                        update(1,1,n,v,indegree[v]);
                  }

                  indegree[index] = inf;
                  update(1,1,n,index,indegree[index]);
            }

            cout << "YES" << endl;

            for (int i=0 ; i<edge.size() ; i++){
                  ll a = edge[i].first , b = edge[i].second;
                  if (mp[{a,b}]==1)cout << a << " " << b << endl;
                  else cout << b << " " << a << endl;
            }
      }


      return 0;
}

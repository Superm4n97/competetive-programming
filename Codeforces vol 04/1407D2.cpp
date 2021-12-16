#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005
#define inf 1000000000012

using namespace std;

pair<ll,ll> S[4*maxn];
ll A[maxn] , n;
vector < ll > G[maxn];

void build(ll node, ll b, ll e)
{
      if (b==e){
            {/**Initial Value assign**/
                  S[node] = make_pair(A[b],A[b]);
            }
            return;
      }

      ll mid = (b+e)/2;
      build(node*2 , b, mid);
      build(node*2+1 , mid+1, e);

      { /**Merging two childes**/
            S[node].first = max(S[node*2].first, S[node*2+1].first);
            S[node].second = min(S[node*2].second , S[node*2+1].second);
      }

      return;
}


pair<ll,ll> query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            /**Base Value of extra segments**/
            return make_pair(0,inf);
      }

      if(b>=x && e<=y){
            return S[node];
      }

      ll mid = (b+e)/2;
      pair<ll,ll> t1 = query(node*2,b,mid ,x,y);
      pair<ll,ll> t2 = query(node*2+1,mid+1,e,x,y);

      {/**main calculation**/

            return make_pair(max(t1.first,t2.first),min(t1.second,t2.second));
      }
}

void makeEdge(ll a, ll b)
{
      G[a].push_back(b);
      G[b].push_back(a);
}

int main()
{
      vector < pair <ll,ll> > vp;
      cin >> n;

      for (ll i = 1; i<=n ; i++){
            cin >> A[i];
            vp.push_back({A[i],i});
            if(i>1){
                  makeEdge(i,i-1);
            }
      }

      build(1,1,n);

      sort(vp.begin() , vp.end());

      for (int i=1 ; i<vp.size() ; i++){

            ll a = vp[i-1].first , b = vp[i].first;
            ll a_id = vp[i-1].second , b_id = vp[i].second;

            if (abs(b_id-a_id)==1)continue;

            pair <ll,ll> p = query(1,1,n,min(a_id,b_id)+1 , max(a_id,b_id)-1);

            if (p.first < min(a,b) || p.second>max(a,b)){
                  makeEdge(a_id,b_id);
            }
      }

      ll level[n+5] , vis[n+5];
      for (int i=0 ; i<=n+2 ; i++)level[i] = inf , vis[i] = 0;

      queue < ll > q;
      q.push(1);
      level[1] = 0;

      while(!q.empty()){

            ll u = q.front();
            q.pop();

            for (int i=0 ; i<G[u].size() ; i++){

                  ll v = G[u][i];

                  if (level[v]>level[u]+1){
                        level[v] = level[u]+1;
                        q.push(v);
                  }
            }
      }

      cout << level[n] << endl;


      return 0;
}

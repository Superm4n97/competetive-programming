#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005

using namespace std;

vector < ll > Tree[maxn];
ll SP[maxn][30] , L[maxn] , P[maxn] , vis[maxn] , tme = 1;
ll N;///number of nodes in Tree 1 based
ll in[maxn] , timereverse[maxn] , Smx[maxn*4] , Smn[maxn*4] , que;

void makeLCA(ll source)
{
      queue < ll > q;

      L[source] = 0;
      q.push(source);
      vis[source] = 1;

      while(!q.empty()){
            ll u = q.front();
            q.pop();

            for (int i=0; i<Tree[u].size() ; i++){
                  ll v = Tree[u][i];

                  if (!vis[v]){
                        L[v] = L[u]+1;
                        vis[v] = 1;
                        P[v] = u;
                        q.push(v);
                  }
            }
      }

      for (int i=1;i<=N;i++)///Nodes are 1 to N
            SP[i][0] = P[i];


      for (int j = 1 ; j<29 ; j++){
            for (int i = 1 ; i<= N ;i++){
                  SP[i][j] = SP[SP[i][j-1]][j-1];/// sparse table has additional data, here must be implemented
            }
      }

      return;
}

ll LCA(ll a, ll b)
{
      if (L[a]>L[b])swap(a,b);


      for (int i=28 ; i>=0 ; i--){
            if (L[b] - (1<<i) >= L[a]){
                  b = SP[b][i];
            }
      }


      if (b==a)return a;


      for (int i=28 ; i>= 0 ; i--){
            if (SP[a][i] != SP[b][i]){
                  a = SP[a][i];
                  b = SP[b][i];
            }
      }

      return P[a];
}

void dfs(ll u)
{
      vis[u] = 1;
      in[u] = tme;
      timereverse[tme] = u;
      tme++;

      for (int i=0 ; i<Tree[u].size() ; i++){

            ll v = Tree[u][i];

            if(vis[v]==0){
                  dfs(v);
            }
      }

      return;
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            Smx[node] = in[b];
            Smn[node] = in[b];
            return;
      }

      ll mid = (b+e)/2;
      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      Smx[node] = max(Smx[node*2],Smx[node*2+1]);
      Smn[node] = min(Smn[node*2],Smn[node*2+1]);

      return;
}

pair<ll,ll> querySeg(ll node ,ll b, ll e, ll x, ll y)
{
      if (b>y || e<x)return {-1,maxn};
      if (b>=x && e<=y)return {Smx[node] , Smn[node]};

      ll mid = (b+e)/2;

      pair < ll , ll > p1,p2;

      p1 = querySeg(node*2,b,mid,x,y);
      p2 = querySeg(node*2+1,mid+1,e,x,y);

      return {max(p1.first,p2.first) , min(p1.second,p2.second)};
}

ll solve(ll l, ll r, ll u)
{
      if (u==l){
            pair < ll , ll > p = querySeg(1,1,N,l+1,r);
            return L[LCA(timereverse[p.first],timereverse[p.second])];
      }
      else if (u==r){
            pair < ll , ll > p = querySeg(1,1,N,l,r-1);
            return L[LCA(timereverse[p.first],timereverse[p.second])];
      }
      else {
            pair < ll , ll > p1,p2;
            p1 = querySeg(1,1,N,l,u-1);
            p2 = querySeg(1,1,N,u+1,r);

            ll a = LCA(timereverse[p1.first],timereverse[p1.second]);
            ll b = LCA(timereverse[p2.first],timereverse[p2.second]);

            return L[LCA(a,b)];
      }
}

int main()
{
      cin >> N >> que;

      for (int i=2 ; i<=N ; i++){
            ll a = i, b;
            cin >> b;

            Tree[a].push_back(b);
            Tree[b].push_back(a);
      }

      makeLCA(1);

      memset(vis,0,sizeof vis);
      dfs(1);

      build(1,1,N);

      while(que--){

            ll l,r;
            ll ans , lv = -1;
            pair < ll , ll > p1;

            scanf("%I64d %I64d",&l,&r);

            p1 = querySeg(1,1,N,l,r);

            ll a = timereverse[p1.first] , b = timereverse[p1.second];

            ans = l , lv = L[LCA(a,b)];

            ll lv1 = solve(l,r,a) , lv2 = solve(l,r,b);

            if (lv1>lv){
                  lv = lv1;
                  ans = a;
            }
            if (lv2>lv){
                  lv = lv2;
                  ans = b;
            }

            printf("%I64d %I64d\n",ans,lv);
      }



      return 0;
}

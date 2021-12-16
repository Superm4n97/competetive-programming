#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200050

using namespace std;

struct node
{
      ll l,r,qmx,id;
}qry[maxn];

ll n,m ,A[maxn],ST[maxn] , ED[maxn] , currNode = 1, C[maxn] , bucket;
vector<ll> G[maxn];
ll ans[maxn] , fre[maxn] , cnt[maxn];

void euler(ll u, ll p)
{
      A[currNode] = C[u];
      ST[u] = currNode;
      currNode++;

      for (int i=0 ; i<G[u].size() ; i++){
            ll v = G[u][i];
            if (v!=p){
                  euler(v,u);
            }
      }

      A[currNode] = 0;
      ED[u] = currNode;
      currNode++;
}

bool comp(node a, node b)
{
      if (a.l/bucket != b.l/bucket)return a.l/bucket<b.l/bucket;
      return a.r<b.r;
}

void add(ll i)
{
      if (A[i]==0)return;
      fre[A[i]]++;
      ll temp = fre[A[i]];
      cnt[temp]++;
      return;
}

void rem(ll i)
{
      if (A[i]==0)return;
      ll temp = fre[A[i]];
      fre[A[i]]--;
      cnt[temp]--;
      return;
}

int main()
{
      scanf("%I64d %I64d",&n,&m);
      for (int i=1 ; i<=n ; i++)scanf("%I64d",&C[i]);

      for (int i=1 ; i<n ; i++){
            ll a, b;
            scanf("%I64d %I64d",&a,&b);

            G[a].push_back(b);
            G[b].push_back(a);
      }

      euler(1,0);
      bucket = sqrt(2*n);

      for (int i=0 ; i<m ; i++){
            ll a,x;
            scanf("%I64d %I64d",&a,&x);

            qry[i].l = ST[a];
            qry[i].r = ED[a];
            qry[i].qmx = x;
            qry[i].id = i;
      }

      sort(qry,qry+m,comp);

      ll R = 0 , L = 1;

      for (int i=0 ; i<m ; i++){
            while(R<qry[i].r){
                  R++;
                  add(R);
            }
            while(R>qry[i].r){
                  rem(R);
                  R--;
            }
            while(L<qry[i].l){
                  rem(L);
                  L++;
            }
            while(L>qry[i].l){
                  L--;
                  add(L);
            }
            ans[qry[i].id] = cnt[qry[i].qmx];
      }
      for (int i=0 ; i<m ; i++)printf("%I64d\n",ans[i]);

      return 0;
}

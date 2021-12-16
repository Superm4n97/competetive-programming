#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200050
#define norm 100001

using namespace std;

ll n,q,bucket , A[maxn] , fre[maxn] , ans[maxn], res;
//unordered_map<ll,ll> ump;
ll ump[maxn];

struct node
{
      ll l,r,id;
} qry[maxn];

bool comp(node a, node b)
{
      if (a.l/bucket != b.l/bucket) return a.l/bucket < b.l/bucket;
      return a.r<b.r;
}

void add(ll i)
{
      ump[A[i]+norm]++;
      ll temp = ump[A[i]+norm];
      fre[temp]++;
      if (fre[temp] == 1)res = temp;
}

void del(ll i)
{
      ll temp = ump[A[i]+norm];
      fre[temp]--;
      if (fre[temp] == 0)res = temp-1;
      ump[A[i]+norm]--;
}

int main()
{
      while(true){
            scanf("%lld",&n);
            if (n==0)break;
            scanf("%lld",&q);

            bucket = sqrt(n);

            for (int i=1 ; i<=n; i++)scanf("%lld",&A[i]);

            for (int i=0 ; i<q ; i++){
                  scanf("%lld %lld",&qry[i].l,&qry[i].r);
                  qry[i].id = i;
            }
            sort(qry,qry+q,comp);

            for (int i=0 ; i<=n+3 ; i++)fre[i] = 0;
            res = 0;

            ll L = 1,  R = 0;

            for (int i=0 ;i<q; i++){
                  while(R<qry[i].r){
                        R++;
                        add(R);
                  }
                  while(R>qry[i].r){
                        del(R);
                        R--;
                  }
                  while(L<qry[i].l){
                        del(L);
                        L++;
                  }
                  while(L>qry[i].l){
                        L--;
                        add(L);
                  }
                  ans[qry[i].id] = res;
            }

            for (int i=0 ; i<q ; i++)printf("%lld\n",ans[i]);
            for (int i=1 ; i<=n ; i++)ump[A[i]+norm] = 0;
      }

      return 0;
}

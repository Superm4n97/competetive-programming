#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 2000050

using namespace std;

struct node
{
      ll l,r,id;
} qry[maxn];
ll n,m,k,A[maxn],cxor[maxn] , cnt[maxn] , ans[maxn] , bucket , cur = 0 , L = 1, R = 0;

bool comp(node a, node b)
{
      if (a.l/bucket != b.l/bucket)return a.l<b.l;
      return a.r<b.r;
}

void addR(ll i)
{
      ll x = k^A[i]^cxor[i-1];
      cnt[cxor[i]]++;/**/
      cur+=cnt[x];
      if (cxor[L-1]==x)cur++;
      return;
}

void remR(ll i)
{
      ll x = k^A[i]^cxor[i-1];
      cur-=cnt[x];
      if (cxor[L-1]==x)cur--;
      cnt[cxor[i]]--;/**/
      return;
}

void addL(ll i)
{
      ll x = k^cxor[i]^A[i];
      cnt[cxor[i]]++;/**/
//      if (x==0)cur+=(cnt[x]-1);
//      else cur+=cnt[x];
      cur+=cnt[x];
      return;
}

void remL(ll i)
{
      ll x = k^cxor[i]^A[i];
//      if (x==0) cur-=(cnt[x]-1);
//      else cur-=cnt[x];
      cur-=cnt[x];
      cnt[cxor[i]]--;
      return;
}

int main()
{
      scanf("%I64d %I64d %I64d",&n,&m,&k);
      for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);
      bucket = sqrt(n);
      for (int i=0 ; i<m ; i++){
            scanf("%I64d %I64d",&qry[i].l,&qry[i].r);
            qry[i].id = i;
      }
      sort(qry,qry+m,comp);

      for (int i=1 ; i<=n ; i++)cxor[i] = cxor[i-1]^A[i];
//      cnt[0] = 1;

//      for (int i=1 ; i<=n ; i++)cout << cxor[i] << " " ;
//      cout << endl;

      R = 0 , L = 1;
      for (int i=0 ; i<m ; i++){
            while(R<qry[i].r){
                  R++;
                  addR(R);
            }
            while(R>qry[i].r){
                  remR(R);
                  R--;
            }

            while(L<qry[i].l){
                  remL(L);
                  L++;
            }
            while(L>qry[i].l){
                  L--;
                  addL(L);
            }
            ans[qry[i].id] = cur;
      }
      for (int i=0 ; i<m ; i++)printf("%I64d\n",ans[i]);


      return 0;
}

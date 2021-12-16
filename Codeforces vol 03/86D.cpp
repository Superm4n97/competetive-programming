#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000050

using namespace std;

ll A[maxn], bucket , n , q , ans[maxn] , fre[maxn] , sum = 0;

struct node
{
      ll l,r,id;
} qry[maxn];

bool comp(node a, node b)
{
      ll bkt_a = a.l/bucket , bkt_b = b.l/bucket;
      if (bkt_a != bkt_b)return bkt_a < bkt_b;
      return a.r < b.r;
}

void add(ll i)
{
      sum -= (fre[A[i]]*fre[A[i]]*A[i]);
      fre[A[i]]++;
      sum += (fre[A[i]]*fre[A[i]]*A[i]);
      return;
}

void del(ll i)
{
      sum -= (fre[A[i]]*fre[A[i]]*A[i]);
      fre[A[i]]--;
      sum += (fre[A[i]]*fre[A[i]]*A[i]);
      return;
}

int main()
{
      scanf("%lld %lld",&n,&q);
      bucket = sqrt(n);

      for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);

      for (ll i=0 ; i<q ; i++){
            ll a, b;
            scanf("%lld %lld",&a,&b);
            qry[i].l = a , qry[i].r = b , qry[i].id = i;
      }
      sort(qry,qry+q,comp);

      ll L = 1 , R = 0;

      for (int i=0 ; i<q ; i++){
            ll a = qry[i].l , b = qry[i].r , id = qry[i].id;
            while(R<b){
                  R++;
                  add(R);
            }
            while(R>b){
                  del(R);
                  R--;
            }
            while(L<a){
                  del(L);
                  L++;
            }
            while(L>a){
                  L--;
                  add(L);
            }
            ans[id] = sum;
      }

      for (int i=0 ; i<q ; i++){
            printf("%lld\n",ans[i]);
      }

      return 0;
}
/*
9 5
1 2 3 4 5 6 7 8 9
1 5
3 4
1 2
2 4
1 9
sum - ((x-1)*(x-1))
*/

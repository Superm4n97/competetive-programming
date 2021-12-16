#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll n,q,R,L,mx_cnt,qx[maxn], qy[maxn],ans[maxn], mx[maxn], A[maxn], fre[maxn], cnt[maxn], bucket;
vector<pair<pair<ll,ll>,ll> >qry;

void add(ll id)
{
      fre[A[id]]++;
      cnt[fre[A[id]]]++;
      if (cnt[fre[A[id]]]==1)mx_cnt = fre[A[id]];
}

void del(ll id)
{
      cnt[fre[A[id]]]--;
      if (cnt[fre[A[id]]]==0)mx_cnt = fre[A[id]]-1;
      fre[A[id]]--;
}

int main()
{
      scanf("%lld %lld",&n,&q);
      bucket = sqrt(n)+1;

      for (int i=1 ; i<=n ; i++)scanf("%lld",&A[i]);
      for (ll i=1 ; i<=q ; i++){
            scanf("%lld %lld",&qx[i],&qy[i]);
            qry.push_back({{qx[i]/bucket,qy[i]},i});
      }

      sort(qry.begin(),qry.end());
      for (int i=0 ; i<q ; i++){
            ll x = qx[qry[i].second], y = qy[qry[i].second];

            while(x<L){
                  L--;
                  add(L);
            }
            while(R<y){
                  R++;
                  add(R);
            }
            while(x>L){
                  del(L);
                  L++;
            }
            while(R>y){
                  del(R);
                  R--;
            }
            mx[qry[i].second] = mx_cnt;
      }
      for (int i=1 ; i<=q ; i++){
            ll a = mx[i] , b = qy[i]-qx[i]+1 - mx[i];

            if (a<=b+1)printf("1\n");
            else printf("%lld\n",a-b);
      }


      return 0;
}
/*
6 5
1 3 2 3 3 2
1 6
2 5
1 3
1 4
4 4


*/

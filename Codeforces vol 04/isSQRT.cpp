#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005

using namespace std;

pair <ll,ll> S[maxn*4];
ll A[maxn] , Q[maxn] , n , qry;

pair<ll,ll> mergePairs(pair<ll,ll> t1 , pair<ll,ll> t2)
{
      if (t1.first>t2.first)return t1;
      else return t2;
}

void build(ll node, ll b, ll e)
{
      if (b==e){
            {/**Initial Value assign**/
                  S[node] = {A[b],b};
            }
            return;
      }

      ll mid = (b+e)/2;
      build(node*2 , b, mid);
      build(node*2+1 , mid+1, e);

      { /**Merging two childes**/
            S[node] = mergePairs(S[node*2],S[node*2+1]);
      }

      return;
}


pair<ll,ll> query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            /**Base Value of extra segments**/
            return {-1,-1};
      }

      if(b>=x && e<=y){
            return S[node];
      }

      ll mid = (b+e)/2;
      pair<ll,ll> t1 = query(node*2,b,mid ,x,y);
      pair<ll,ll> t2 = query(node*2+1,mid+1,e,x,y);

      {/**main calculation**/

            return mergePairs(t1,t2);
      }
}


ll solve()
{
      scanf("%lld %lld",&n,&qry);
      for (int i = 1; i<=n ; i++)scanf("%lld",&A[i]);
      for (int i = 1; i<=n ; i++)scanf("%lld",&Q[i]);
      build(1,1,n);

      while(qry--){

            ll type;
            //cin >> type;
            scanf("%lld",&type);

            if (type==1){

                  ll l,r,quantity;
                  //cin >> l >> r >> quantity;
                  scanf("%lld %lld %lld",&l,&r,&quantity);

                  pair<ll,ll> p = query(1,1,n,l,r);
                  ll id = p.second;

                  Q[id] += quantity;
            }
            else {
                  ll v, i, qt, thr;
                  //cin >> v >> i >> qt >> thr;
                  scanf("%lld %lld %lld %lld",&v,&i,&qt,&thr);

                  ll l = max(0LL,i-v) , r = min(n,i+v);

                  pair<ll,ll> p = query(1,1,n,l,r);
                  ll id = p.second;

                  if (A[id]<thr || Q[id]<qt)printf("No purchase\n");
                  else {
                        printf("%lld\n",id);
                        //cout << id << endl;
                        Q[id] -= qt;
                  }
            }
      }
}

int main()
{
      int tc;
      //cin >> tc;
      scanf("%d",&tc);

      while(tc--)solve();


      return 0;
}

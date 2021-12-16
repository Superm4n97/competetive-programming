#include<bits/stdc++.h>
#define show(x) cout << #x << " : " << x << endl
#define ll long long int
#define maxn 500005
#define scl(x) scanf("%lld",&x)
#define inf 10000000000000016

using namespace std;

ll S[4*maxn];
ll A[maxn] , n , q,ans;

void build(ll node, ll b, ll e)
{
      if (b==e){
            {/**Initial Value assign**/
                  S[node] = A[b];
            }
            return;
      }

      ll mid = (b+e)/2;
      build(node*2 , b, mid);
      build(node*2+1 , mid+1, e);

      { /**Merging two childes**/
            S[node] = S[node*2] + S[node*2+1];
      }

//      cout << b << " " << e << " " << S[node] << endl;

      return;
}

void update(ll node, ll b, ll e, ll index , ll value)
{
      if(b>index || e<index)return;

      if (b==e){
            {/**Update position**/
                  S[node] = value;
            }
            return;
      }

      ll mid = (b+e)/2;
      update(node*2,b,mid,index,value);
      update(node*2+1,mid+1,e,index,value);

      { /**Merging two childes**/
            S[node] = S[node*2]+S[node*2+1];
      }
      return;
}

ll query(ll node, ll b, ll e, ll x, ll y ,ll sum)
{
      if (b>y || e<x){
            /**Base Value of extra segments**/
            return sum;
      }

//      cout << b << " " << e << " - " << sum << endl;

      if(b>=x && e<=y){
            if (S[node]<sum) return sum - S[node];
            else {
                  if (b==e){
                        ans = min(ans,b);
                        return 0;
                  }
                  else {
                        ll mid = (b+e)/2;
                        ll t1 = query(node*2,b,mid,x,y,sum);
                        if (t1<=0)return 0;
                        ll t2 = query(node*2+1,mid+1,e,x,y,t1);
                        return 0;
                  }
            }
      }

      ll mid = (b+e)/2;
      ll t1 = query(node*2,b,mid ,x,y,sum);
      if (t1<=0){
            return 0;
      }
//      show("ck");
      return query(node*2+1,mid+1,e,x,y,t1);
}

int main()
{
      scl(n),scl(q);
      for (int i = 1; i<=n ; i++)scl(A[i]);

      build(1,1,n);

      while(q--){

            string s;
            cin >> s;

            if (s=="Query"){
                  ll x,l;
                  scl(l) , scl(x);

                  ans = n+1;

                  ll temp = query(1,1,n,l,n,x);
                  if (ans>n)printf("-1\n");
                  else printf("%lld\n",ans);
            }
            else {
                  ll index , val;
                  scl(index) , scl(val);

                  update(1,1,n,index,val);
            }
      }

      return 0;
}

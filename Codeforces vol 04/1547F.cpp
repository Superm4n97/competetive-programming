#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005
#define scl(x) scanf("%lld",&x)


using namespace std;

ll S[4*maxn];
ll A[maxn] , n;

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
            S[node] = __gcd(S[node*2] , S[node*2+1]);
      }

      return;
}

ll query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x){
            /**Base Value of extra segments**/
            return 0LL;
      }

      if(b>=x && e<=y){
            return S[node];
      }

      ll mid = (b+e)/2;
      ll t1 = query(node*2,b,mid ,x,y);
      ll t2 = query(node*2+1,mid+1,e,x,y);

      {/**main calculation**/

            return __gcd(t1,t2);
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            cin >> n;
            for (int i = 1; i<=n ; i++)cin >> A[i];
            for (int i=1 ; i<=n ; i++)A[n+i] = A[i];

            build(1,1,2*n);
            ll g = S[1] , ans = 0;
            for (ll i=1 ; i<=n ; i++){
                  ll b = i , e = i+n , res = i+n;
                  while(b<=e){
                        ll mid = (b+e)/2;
                        ll x = query(1,1,2*n,i,mid);
                        if (x==g){
                              res = min(res,mid);
                              e = mid-1;
                        }
                        else b = mid+1;
                  }
                  ans = max(res-i,ans);
            }
            printf("%lld\n",ans);
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define maxn 100050

using namespace std;

ll n,q,k ,A[maxn] , csum[maxn];

ll rng(ll x, ll y)
{
      if (x>y)return 0;
      return csum[y] - csum[x-1];
}

ll query(ll x, ll y)
{
      ll ret = max(0LL,A[x+1]-2) + max(0LL,k-A[y-1]-1);
//      show(ret);
      return max(0LL,ret+rng(x+1,y-1));
}

int main()
{
      scl(n) , scl(q) , scl(k);
      for (int i=1 ; i<=n ; i++)scl(A[i]);

      for (int i=2 ; i<n ; i++){
            csum[i] = A[i+1] - A[i-1] - 2;
            csum[i] += csum[i-1];
      }

      while(q--){
            ll a, b;
            scl(a),scl(b);
            if (a==b)printf("%I64d\n",k-1);
            else {
                  printf("%I64d\n",query(a,b));
            }
      }


      return 0;
}

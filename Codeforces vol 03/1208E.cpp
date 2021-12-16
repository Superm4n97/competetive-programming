#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006
#define inf 100000000000000017

using namespace std;

ll S[4*maxn] , ans[maxn] , A[maxn] , n, w , m;

void build(ll node, ll b, ll e)
{
      if (b==e){
            S[node] = A[b];
            return;
      }

      ll mid = (b+e)/2;

      build(node*2,b,mid);
      build(node*2+1,mid+1,e);

      S[node] = max(S[node*2],S[node*2+1]);

      return;
}

ll query(ll node, ll b, ll e, ll x, ll y)
{
      if (b>y || e<x)return -inf;
      if (b>=x && e<=y)return S[node];

      ll mid = (b+e)/2;

      return max(query(node*2,b,mid,x,y) , query(node*2+1,mid+1,e,x,y));
}

int main()
{
      scanf("%I64d %I64d",&m,&w);

      for (int j = 0 ; j<m ; j++){
            scanf("%I64d",&n);
            for (int i=1 ; i<=n ; i++)scanf("%I64d",&A[i]);

            build(1,1,n);


      }


      return
}

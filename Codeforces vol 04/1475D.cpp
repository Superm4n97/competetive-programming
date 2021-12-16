#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)
#define inf 1000000000012

using namespace std;

vector<ll> A,B;

ll bs(ll val)
{
      if (val<=0)return 0;
      if (B.empty())return inf;

      ll b = 0 , e = B.size()-1 , ret = B.size();
      if (B[e]<val)return inf;

      while(b<=e){
            ll mid = (b+e)/2;
            if (B[mid]>=val){
                  ret = min(ret,mid);
                  e = mid-1;
            }
            else b = mid+1;
      }
      return (ret+1)*2;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            A.clear();
            B.clear();

            ll n , m;
            scl(n) , scl(m);
            ll x[n+5] , t[n+5];
            for (int i=1 ; i<=n ; i++)scl(x[i]);
            for (int i=1 ; i<=n ; i++){
                  scl(t[i]);
                  if (t[i]==1)A.push_back(x[i]);
                  else B.push_back(x[i]);
            }
            sort(A.rbegin(),A.rend());
            sort(B.rbegin(),B.rend());

            for (int i=1 ; i<A.size() ; i++)A[i]+=A[i-1];
            for (int i=1 ; i<B.size() ; i++)B[i]+=B[i-1];

            ll ans = bs(m);
            for (int i=0 ; i<A.size() ; i++){
                  ll temp = m - A[i];
                  ans = min(ans,bs(temp)+(i+1));
            }
            if (ans>=inf)printf("-1\n");
            else printf("%I64d\n",ans);
      }


      return 0;
}

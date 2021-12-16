#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 100005

using namespace std;

ll n;
vector<ll> A,B;

ll rem(ll x)
{
      return x - (x/4);
}

ll calA(ll added , ll extra)
{
      if (extra>=added)return added*100;
      return (extra*100)+A[added-extra-1];
}

ll calB(ll added, ll extra)
{
      added = min(added,n);
      return B[added-1];
}

bool sol(ll mid)
{
      ll added = rem(mid);
      ll ex = max(0LL , mid - n);

      ll tA = calA(added,ex) , tB = calB(added,ex);
//      if (mid==n+2){
//            show(tA);
//            show(tB);
//            show(added);
//            show(ex);
//      }
      if (tA>=tB)return true;
      return false;
}

void clean()
{
      A.clear();
      B.clear();
}

int main()
{
      ll tc;
      scl(tc);
      while(tc--){
            scl(n);
            clean();
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  A.push_back(a);
            }
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scl(a);
                  B.push_back(a);
            }
            sort(A.rbegin(),A.rend());
            sort(B.rbegin(),B.rend());
            for (int i=1 ; i<n ; i++){
                  A[i]+=A[i-1];
                  B[i]+=B[i-1];
            }

            ll b = 0 , e = 10000000010 , ans = 10000000010;
            while(b<=e){
                  ll mid = (b+e)/2;
                  if (sol(n+mid)){
                        ans = min(ans,mid);
                        e = mid-1;
                  }
                  else {
                        b = mid+1;
                  }
            }
            printf("%lld\n",ans);
      }

      return 0;
}

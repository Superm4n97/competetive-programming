#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[105][105] , n,k,w;
vector<ll> v;

ll findNextPos(ll id, ll val)
{
      ll lm = v[id]+val , b = id , e = n-1, ret = -1;
      while(b<=e){
            ll mid = (b+e)/2;
            if (v[mid]<=lm){
                  ret = max(mid,ret);
                  b = mid+1;
            }
            else e = mid-1;
      }
      return ret+1;
}

ll rec(ll pos, ll mv)
{
      if (dp[pos][mv] != -1)return dp[pos][mv];
      if (pos==n || mv == 0)return dp[pos][mv] = 0;

      ll nxt = findNextPos(pos,w);
      return dp[pos][mv] = max(rec(pos+1,mv),rec(nxt,mv-1)+nxt-pos);
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc; _t++){
            scanf("%lld %lld %lld",&n,&w,&k);

            v.clear();
            memset(dp,-1,sizeof dp);

            for (int i=0 ; i<n ; i++){
                  ll a,b;
                  scanf("%lld %lld",&a,&b);
                  v.push_back(b);
            }

            sort(v.begin(),v.end());

            printf("Case %d: %lld\n",_t,rec(0,k));
      }

      return 0;
}

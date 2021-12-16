#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define inf 100000000000014

using namespace std;

ll dp[maxn][5] , A[maxn] , n, ans = 0;

ll rec(ll pos , ll type)
{
      //show(pos);

      if(type>3)return inf;
      if (dp[pos][type]!=-1)return dp[pos][type];

      if (pos==n){

            //if (type!=3)return dp[pos][type] = inf;
            if (A[n]!=type)return dp[pos][type] = 1;
            return dp[pos][type] = 0;
      }

      ll ret = 0;
      if (A[pos]!=type)ret = 1;

      ll t1 = rec(pos+1,type) , t2 = rec(pos+1,type+1) , t3 = rec(pos+1,type+2);


      /*
      show(pos);
      show(type);
      show(t1);
      show(t2);
      show(min(t1,t2)+ret);
      */


      return dp[pos][type] = ret+min(t1,min(t2,t3));
}

int main()
{
      memset(dp,-1,sizeof dp);

      ll k1,k2,k3;
      cin >> k1 >> k2 >> k3;
      n = k1+k2+k3;

      for (int i=1 ; i<=k1 ; i++){
            ll a;
            cin >> a;
            A[a] = 1;
      }
      for (int i=1 ; i<=k2 ; i++){
            ll a;
            cin >> a;
            A[a] = 2;
      }
      for (int i=1 ; i<=k3 ; i++){
            ll a;
            cin >> a;
            A[a] = 3;
      }

      //if (A[1]!=1)ans=1;

      ans += min(rec(1,1),min(rec(1,2),rec(1,3)));

      cout << ans << endl;


      return 0;
}

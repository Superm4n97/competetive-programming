#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%I64d",&w)
#define maxn 205

using namespace std;

ll dp[maxn][maxn*2] , n;
vector<ll> A;

void clean()
{
      A.clear();
      for (int i=0 ; i<=n+2 ; i++){
            for (int j = 0 ; j<=2*n+4 ; j++)dp[i][j] = -1;
      }
}

ll rec(ll pos, ll index)
{
      if (dp[pos][index] != -1)return dp[pos][index];
      if (pos>n)return 0;
      if (index>2*n)return -2;

      ll t1 = -2 , t2 = -2;
      {
            t1 = rec(pos , index+1);
      }
      {
            t2 = rec(pos+1,index+1);
            if(t2!=-2)t2+=abs(A[pos]-index);
      }

      if (t1==-2)return dp[pos][index] = t2;
      if (t2==-2)return dp[pos][index] = t1;
      return dp[pos][index] = min(t1,t2);
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            scl(n);
            clean();

            for (int i=1 ; i<=n ; i++){

                  ll a;
                  scl(a);
                  A.push_back(a);
            }
            A.push_back(0);
            sort(A.begin(),A.end());

            ll ans = rec(1,1);

            printf("%I64d\n",ans);
      }

      return 0;
}

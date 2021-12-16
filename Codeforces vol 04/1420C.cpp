#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll n,q , dp[maxn][3], A[maxn];


void clean()
{
      for (int i=0 ; i<=n+3 ; i++){
            dp[i][0] = dp[i][1] = dp[i][2] = -1;
      }
}

ll rec(ll pos, ll state)
{
      if (dp[pos][state] != -1)return dp[pos][state];

      //base
      if (pos>n){
            return 0;
      }


      ll t1 = 0 , t2 = 0;

      if (state==0){
            t2 = rec(pos+1,0);
            t1 = rec(pos+1,1) + A[pos];
      }
      else {
            t2 = rec(pos+1,1);
            t1 = rec(pos+1,0) - A[pos];
      }

      return dp[pos][state] = max(t1,t2);
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            scanf("%I64d %I64d",&n,&q);

            clean();

            for (int i = 1; i<=n ; i++){
                  scanf("%I64d",&A[i]);
            }

            printf("%I64d\n",rec(1,0));
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll dp[200005][3] , A[200005] , n;

ll rec(ll pos, ll person)
{
      if (dp[pos][person] != -1)return dp[pos][person];
      if (pos>n)return dp[pos][person] = 0;

      if (pos==n){
            if (person == 0 && A[n] == 1)return dp[pos][person] = 1;
            else return dp[pos][person] = 0;
      }

      ll t1 = 0 , t2 = 0;

      if (person==0 && A[pos]==1)t1++ , t2++;
      if (person==0 && A[pos+1]==1)t2++;

      t1 += rec(pos+1 , 1-person);
      t2 += rec(pos+2 , 1-person);

      return dp[pos][person] = min(t1,t2);
}

int main()
{
      int tc;
      scanf("%I64d",&tc);

      while(tc--){

            scanf("%I64d",&n);
            for (int i=1 ; i<=n ; i++){
                  scanf("%I64d",&A[i]);

                  dp[i][0] = dp[i][1] = -1;
            }

            A[0] = A[n+1] = 0;
            dp[0][0] = dp[0][1] = dp[n+1][0] = dp[n+1][1] = -1;

            printf("%I64d\n",rec(1,0));
      }


      return 0;
}

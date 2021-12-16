#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define mod 1000000007

using namespace std;

ll n , dp[maxn][3] , A[maxn];

void clean()
{
      for (int i=0 ; i<=n+100 ; i++){
            dp[i][0] = dp[i][1] = A[i] = 0;
      }
}

void clearIndex(int i)
{
      if (A[i]%2==1){
            A[i]+1
      }
}
/**
1 2 1
1 1 0
1 0 1
**/

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1; _t<=tc ; _t++){
            scanf("%lld",&n);
            clean();

            for (int i=1 ; i<=n ; i++){
                  ll a, b;
                  scanf("%lld %lld",&a,&b);

            }
            for (int i=1 ; ;i++){

            }
      }


      return 0;
}

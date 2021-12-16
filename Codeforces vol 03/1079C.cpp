#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn  100005

using namespace std;

ll dp[maxn][7] , A[maxn] , n;

ll rec(ll pos, ll fig)
{
      if (dp[pos][fig] != -1) return dp[pos][fig];
      if (pos==n)return dp[pos][fig] = 1;

      if (A[pos]>A[pos+1]){
            ll ret = 0;
            for (int i=1 ; i<fig ; i++){
                  if (rec(pos+1,i)==1){
                        ret = 1;
                  }
            }
            return dp[pos][fig] = ret;
      }
      else if (A[pos]<A[pos+1]){

            ll ret = 0;
            for (int i=fig+1 ; i<=5; i++){
                  if (rec(pos+1,i)==1){
                        ret = 1;
                  }
            }
            return dp[pos][fig] = ret;
      }
      else {
            ll ret = 0;
            for (int i=1 ; i<=5 ; i++){
                  if (i==fig)continue;

                  if (rec(pos+1,i)==1)ret = 1;
            }

            return dp[pos][fig] = ret;
      }
}

void solutionPrint(ll pos, ll fig)
{
      //show(pos);
      //show(n);
      cout << fig << " ";

      if (pos==n)return;

      if (A[pos]>A[pos+1]){
            for (int i=1 ; i<fig ; i++){
                  if (dp[pos+1][i]==1){
                        solutionPrint(pos+1,i);
                        return;
                  }
            }
      }
      else if (A[pos]<A[pos+1]){
            for (int i=fig+1 ; i<=5 ; i++){
                  if (dp[pos+1][i] == 1){
                        solutionPrint(pos+1,i);
                        return;
                  }
            }
      }
      else {
            /*if (pos==5){
                  show(dp[pos][fig]);
            }*/
            for (int i=1;  i<=5 ; i++){
                  if (i==fig)continue;

                  if (dp[pos+1][i]==1){
                        solutionPrint(pos+1,i);
                        return;
                  }

                  //show(dp[pos+1][i]);
            }
      }
}

int main()
{
      memset(dp,-1,sizeof dp);

      cin >> n;
      for (int i=1 ; i<=n ; i++)cin >> A[i];

      ll ans = 0;

      for (int i=1 ; i<=5 ; i++){
            if (rec(1,i)==1)ans = 1;
      }

      if (ans==0)cout << -1 << endl;
      else {
            for (int i=1 ; i<=5 ; i++){
                  if (dp[1][i]==1){
                        solutionPrint(1,i);
                        break;
                  }
            }
      }

      return 0;
}
/**

**/

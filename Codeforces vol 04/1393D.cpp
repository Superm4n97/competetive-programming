#include<bits/stdc++.h>
#define ll long long int
#define maxn 2005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int n,m,A[maxn][maxn],U[maxn][maxn],D[maxn][maxn],L[maxn][maxn],R[maxn][maxn],minUD[maxn][maxn];
ll ans=0;

int main()
{
      cin >> n >> m;
      for (int i=1 ; i<=n; i++){

            string s;
            cin >> s;
            for (int j=0 ; j<m; j++)A[i][j+1] = (s[j] - 'a') + 1;
      }

      for (int j=1 ; j<=m ; j++){
            for (int i=1 ; i<=n ; i++){
                  if(A[i][j]==A[i-1][j])U[i][j] = U[i-1][j]+1;
                  else U[i][j] = 1;
            }
      }
      for (int j = 1 ; j<=m ; j++){
            for (int i=n ; i>=1 ; i--){
                  if (A[i][j]==A[i+1][j])D[i][j] = D[i+1][j]+1;
                  else D[i][j] = 1;
            }
      }
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if (A[i][j]!=A[i+1][j] || A[i][j]!=A[i-1][j])minUD[i][j] = 1;
                  else minUD[i][j] = min(U[i-1][j],D[i+1][j])*2 + 1;
            }
      }
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if (A[i][j-1]!=A[i][j])L[i][j] = 1;
                  else L[i][j] = min(L[i][j-1]+2 , minUD[i][j]);
            }
      }
      for (int i=1 ; i<=n ; i++){
            for (int j=m ; j>=1 ; j--){
                  if (A[i][j]!=A[i][j+1])R[i][j] = 1;
                  else R[i][j] = min(R[i][j+1]+2 , minUD[i][j]);
            }
      }
      for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if (A[i][j]!=A[i][j-1] || A[i][j]!=A[i][j+1] || A[i][j]!=A[i-1][j] || A[i][j]!=A[i+1][j]){
                        ans++;
                  }
                  else {
                        int temp = min(min(L[i][j-1]+2,R[i][j+1]+2),minUD[i][j]);
                        ans += (temp+1)/2;
                  }
            }
      }

      cout << ans << endl;


      return 0;
}

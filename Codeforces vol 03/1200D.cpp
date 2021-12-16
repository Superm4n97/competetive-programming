#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl
#define maxn 2005

using namespace std;

int A[maxn][maxn], n , k , ans[maxn][maxn] , L[maxn] , R[maxn];

void row()
{
      ///till k:
      int cnt = 0 , T[n+4];
      memset(T , 0, sizeof T);

      ///i = 1  , i = 1
      for (int i=1 ; i<=k ; i++){

      }
}

int main()
{
      scanf("%d%d",&n,&k);

      for (int i=1 ; i<=n; i++){
            string s;
            cin >> s;
            for (int j = 0 ; j<n ; j++){

                  if (s[j]=='B')A[i][j+1] = 0;
                  else A[i][j+1] = 1;
            }
      }

      for (int i=1 ; i<=n ; i++){
            L[i] = n+1;
            R[i] = 0;

            for (int j=1 ; j<=n ; j++){
                  if (A[i][j] == 0){

                        L[i] = min(L[i],j);
                        R[i] = max(R[i],j);
                  }
            }
      }

      row();
      column();


      return 0;
}

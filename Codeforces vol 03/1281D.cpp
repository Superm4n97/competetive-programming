#include<bits/stdc++.h>
#define ll long long int
#define scl(x) scanf("%I64d",&x)
#define show(x) cout << #x << " " << x << endl

using namespace std;

ll A[65][65] , n ,m;
ll csumr[65][65];
ll csumc[65][65];

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            scl(n),scl(m);

            for (int i=0 ; i<=n+2 ; i++){
                  for (int j = 0 ; j<=m+3 ; j++)A[i][j] = 0;
            }

            for (int i = 1 ; i<=n ;i++){
                  string s;
                  cin >> s;

                  for (int j=0 ; j<m ; j++){
                        if (s[j]=='A')A[i][j+1] = 1;
                  }
            }

            bool sol = false ;
            ll cnt = 0;

            for (int i=1 ; i<=n ; i++){
                  for (int j=1;  j<=m ; j++){
                        if (A[i][j]==1){
                              sol = true;
                              cnt++;
                        }
                  }
            }

            if (!sol){
                  cout << "MORTAL" << endl;
                  continue;
            }
            if (cnt==n*m){
                  cout << 0 << endl;
                  continue;
            }

            sol = false;
            ll t1 = 0 , t2 = 0;

            bool three = false;



            for (int j = 1 ; j<=m ; j++){
                  if (A[1][j]==1)t1++;
                  if (A[n][j]==1)t2++;
            }
            if (t1==m || t2==m)sol = true;
            if (t1>0 || t2>0)three = true;
            t1 = t2 = 0;

            for (int i=1 ; i<=n ; i++){
                  if (A[i][1]==1)t1++;
                  if (A[i][m]==1)t2++;
            }
            if (t1==n || t2==n)sol = true;
            if (t1>0 || t2>0)three = true;
            t1 = t2 = 0;


            if (sol){
                  cout << 1 << endl;
                  continue;
            }

            ///FOR ANS 2
            if (A[1][m]==1 || A[1][1]==1 || A[n][1]==1 || A[n][m]==1)sol = true;

            for (int i=1 ; i<=n ; i++){
                  t1 = 0;
                  for (int j = 1; j<=m ; j++){

                        if (A[i][j]==1)t1++;
                  }
                  if (t1==m)sol = true;
            }

            for (int j=1 ; j<=m ; j++){
                  t1 = 0;
                  for (int i=1 ; i<=n ;i++){
                        if (A[i][j]==1)t1++;
                  }
                  if (t1==n)sol = true;
            }

            /*
            ///


            int mx = 0 , mn = n;

            for (int i=1 ; i<=n ; i++){
                  for (int j = 1 ; j<=m ; j++){
                        if (A[i][j]==0)break;
                        mx = max(mx,j);
                  }
            }

            for (int i=1 ; i<=n ; i++){
                  for (int j=m ; j>=1 ; j--){
                        if (A[i][j]==0)break;
                        mn = min(mn,j);
                  }
            }

            if (mx+1>=mn)sol = true;

            mx = 0 , mn = m;

            for (int j = 1 ; j<=m ; j++){
                  for (int i = 1 ; i<=n ; i++){
                        if (A[i][j]==0)break;
                        mx = max(mx,i);
                  }
            }

            for (int j = 1 ; j<=m ; j++){
                  for (int i = n ; i>=1 ; i--){
                        if (A[i][j]==0)break;
                        mn = max(mn,i);
                  }
            }

            if (mx+1>=mn)sol = true;
            */
            ///

            if (sol){
                  cout << 2 << endl;
                  continue;
            }
            if (three){
                  cout << 3 << endl;
                  continue;
            }
            cout << 4 << endl;

      }
      return 0;
}

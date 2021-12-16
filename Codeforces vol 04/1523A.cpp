#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            ll n,m;
            cin >> n >> m;
            string s;
            cin >> s;

            ll A[n+5], L[n+5] , R[n+5];
            memset(A,0,sizeof A);

            for (int i=0 ;i<n ; i++){
                  if (s[i]=='1')A[i+1] = 1;
            }

            L[1] = R[n] = m+n+5;
            if (A[1]==1)L[1] = 0;
            if (A[n]==1)R[n] = 0;
            for (int i=2 ; i<=n ; i++){
                  if (A[i]==1)L[i] = 0;
                  else L[i] = L[i-1]+1;
            }
            for (int i=n-1 ; i>=1 ; i--){
                  if (A[i]==1)R[i] = 0;
                  else R[i] = R[i+1]+1;
            }

            for (int i=1 ; i<=n ; i++){
                  if ((L[i]<=m || R[i]<=m) && L[i] != R[i])A[i] = 1;
                  cout << A[i];
            }
            cout << endl;
      }
}

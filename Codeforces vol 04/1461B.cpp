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
            string s[n+5];
            for (int i=0 ; i<n ; i++)cin >> s[i];

            ll L[n+5][m+5] , R[n+5][m+5];
            memset(L,0,sizeof L);
            memset(R,0,sizeof R);

            for (int i=0 ; i<n ; i++){
                  if (s[i][0]=='*')L[i][0] = 1;
                  for (int j=1 ; j<m ; j++){
                        if (s[i][j]=='*'){
                              L[i][j] = L[i][j-1]+1;
                        }
                  }

                  if (s[i][m-1]=='*')R[i][m-1] = 1;
                  for (int j=m-2 ; j>=0 ; j--){
                        if(s[i][j]=='*'){
                              R[i][j] = R[i][j+1]+1;
                        }
                  }
            }

            ll ans = 0;

            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<m ; j++){
                        if (s[i][j] == '*'){

                              if (j==0 || j==m-1){
                                    ans++;
                                    continue;
                              }

                              ll h = 1;
                              for (int k = 1 ; i+k<n ; k++){
                                    if (L[i+k][j-1]>=k && R[i+k][j+1]>=k && s[i+k][j]=='*')h++;
                                    else break;
                              }
                              ans+=h;

                        }
                  }
            }
            cout << ans << "\n";
      }

      return 0;
}

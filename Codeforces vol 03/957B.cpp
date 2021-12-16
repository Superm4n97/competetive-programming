#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m;
      cin >> n >> m;

      vector < ll > G[55];
      string s[55];

      for (int i=0 ; i<n ; i++){
            cin >> s[i];

            for (int j=0 ;j<m ; j++){
                  if (s[i][j]=='#')G[i].push_back(j);
            }
      }

      bool sol = true;

      for (int j = 0 ; j<m ; j++){

            ll pre = -1;

            for (int i=0 ; i<n ; i++){
                  if (s[i][j]=='#'){
                        if (pre==-1)pre=i;
                        else {
                              if (G[i]!=G[pre])sol = false;
                        }
                  }
            }
      }

      if (sol)cout << "Yes" << endl;
      else cout << "No" << endl;



      return 0;
}
/**
1 3 6
5
1 3 6
0 2 7
5
**/

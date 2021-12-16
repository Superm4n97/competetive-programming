#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m;
ll dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1};

bool check(ll x, ll y)
{
      if (x<n && x>=0 && y<m && y>=0)return true;
      return false;
}

int main()
{
      cin >> n >> m;

      string G[505];

      for (int i=0 ; i<n; i++){
            cin >> G[i];
      }

      bool sol = true;

      for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){

                  if (G[i][j]=='S'){
                        for (int k = 0 ; k<4 ; k++){
                              ll x = i+dx[k] , y = j+dy[k];

                              if (check(x,y)){
                                    if (G[x][y]=='W')sol = false;
                                    if (G[x][y]=='.')G[x][y] = 'D';
                              }
                        }
                  }
            }
      }

      if (!sol)cout << "No" << endl;
      else {
            cout << "Yes" << endl;
            for (int i=0 ;i<n ; i++)cout << G[i] << endl;
      }


      return 0;
}

/**

**/

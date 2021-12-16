#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n, m, dx[]={-1,0,1,0},dy[]={0,1,0,-1}, tc;
ll vis[1004][1004] , dis[1004][1004] , cnt = 0;
vector < string > G;

bool checkSimilar(ll x, ll y, char ch)
{
      for (int i=0 ; i<4; i++){

            ll a = x+dx[i] , b = y+dy[i];
            if (a>=0 && a<n && b>=0 && b<m){

                  if (G[a][b]==ch)return true;
            }
      }

      return false;
}

bool checkBoundary(ll x, ll y)
{
      if (x>=0 && x< n && y>=0 && y<m)return true;
      return false;
}

void bfs()
{
      queue < pair < ll, ll > > q;

      for (ll i=0 ; i<n ; i++){
            for (ll j=0 ; j<m; j++){

                  dis[i][j] = 10000007;
                  if (G[i][j]=='1' && checkSimilar(i,j,G[i][j])){

                        q.push({i,j});
                        dis[i][j] = 0;
                        cnt++;
                  }
            }
      }
      for (ll i =0 ; i<n ; i++){
            for (ll j = 0; j<m; j++){

                  if (G[i][j]=='0' && checkSimilar(i,j,'0')){

                        q.push({i,j});
                        dis[i][j] = 1;
                        cnt++;
                  }
            }
      }

      while(!q.empty()){

            ll x = q.front().first , y = q.front().second;
            q.pop();

            for (int i=0 ; i<4 ; i++){

                  ll a = x+dx[i] , b = y+dy[i];
                  if (checkBoundary(a,b)){

                        ll temp = dis[x][y];
                        if (G[a][b]=='0')temp+=2;

                        if (dis[a][b]>temp){

                              q.push({a,b});
                              dis[a][b] = temp;
                        }
                  }
            }
      }

      return;
}

int main()
{
      cin >> n >> m >> tc;
      for (int i=0 ; i<n;i++){

            string s;
            cin >> s;
            G.push_back(s);
      }

      bfs();

      while(tc--){

            ll x, y, p;
            cin >> x >> y >> p;
            x-- , y--;

            if (cnt==0)cout << G[x][y] << endl;
            else {
                  if (p < dis[x][y])cout << G[x][y] << endl;
                  else {

                        p-=dis[x][y];
                        if (p%2)cout << '0' << endl;
                        else cout << '1' << endl;
                  }
            }
      }


      return 0;
}

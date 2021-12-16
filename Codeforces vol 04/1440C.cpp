#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s[105];
ll n,m , ans = 0;
vector<ll> G[10];

ll clean()
{
      for (int i=0 ; i<8 ; i++)G[i].clear();
}

char opps(char ch)
{
      if (ch=='0')return '1';
      return '0';
}

void solve(ll x, ll y)
{
//      show(x);
//      show(y);
      ll x2 = x , y2 = y+1 , x3 = x+1 , y3 = y , x4 = x+1 , y4 = y+1;
      ll cnt = 0;
      vector<pair <ll , pair <ll,ll> > > vp;

      if (s[x][y]=='1'){
            cnt++;
      }
      if (s[x2][y2]=='1'){
            cnt++;
      }
      if (s[x3][y3]=='1'){
            cnt++;
      }
      if (s[x4][y4]=='1'){
            cnt++;
      }

            vp.push_back({s[x4][y4]-'0',{x4,y4}});
            vp.push_back({s[x][y]-'0',{x,y}});
            vp.push_back({s[x2][y2]-'0',{x2,y2}});
            vp.push_back({s[x3][y3]-'0',{x3,y3}});
      if (cnt==0)return;

      sort(vp.begin(),vp.end());

      if (cnt==4){
                              G[1].push_back(x);
                              G[2].push_back(y);
                              G[3].push_back(x2);
                              G[4].push_back(y2);
                              G[5].push_back(x3);
                              G[6].push_back(y3);
                              s[x][y] = opps(s[x][y]);
                              s[x3][y3] = opps(s[x3][y3]);
                              s[x2][y2] = opps(s[x2][y2]);

                              solve(x,y);
      }

      else if (cnt==3){
                              G[1].push_back(vp[1].second.first);
                              G[2].push_back(vp[1].second.second);
                              G[3].push_back(vp[2].second.first);
                              G[4].push_back(vp[2].second.second);
                              G[5].push_back(vp[3].second.first);
                              G[6].push_back(vp[3].second.second);
                              s[vp[1].second.first][vp[1].second.second] = opps(s[vp[1].second.first][vp[1].second.second]);
                              s[vp[2].second.first][vp[2].second.second] = opps(s[vp[2].second.first][vp[2].second.second]);
                              s[vp[3].second.first][vp[3].second.second] = opps(s[vp[3].second.first][vp[3].second.second]);

      solve(x,y);
      }

      else if (cnt==2){
                              G[1].push_back(vp[1].second.first);
                              G[2].push_back(vp[1].second.second);
                              G[3].push_back(vp[2].second.first);
                              G[4].push_back(vp[2].second.second);
                              G[5].push_back(vp[0].second.first);
                              G[6].push_back(vp[0].second.second);
                              s[vp[1].second.first][vp[1].second.second] = opps(s[vp[1].second.first][vp[1].second.second]);
                              s[vp[2].second.first][vp[2].second.second] = opps(s[vp[2].second.first][vp[2].second.second]);
                              s[vp[0].second.first][vp[0].second.second] = opps(s[vp[0].second.first][vp[0].second.second]);

            solve(x,y);
            }
      else if (cnt==1){
                              G[1].push_back(vp[1].second.first);
                              G[2].push_back(vp[1].second.second);
                              G[3].push_back(vp[2].second.first);
                              G[4].push_back(vp[2].second.second);
                              G[5].push_back(vp[3].second.first);
                              G[6].push_back(vp[3].second.second);
                              s[vp[1].second.first][vp[1].second.second] = opps(s[vp[1].second.first][vp[1].second.second]);
                              s[vp[2].second.first][vp[2].second.second] = opps(s[vp[2].second.first][vp[2].second.second]);
                              s[vp[3].second.first][vp[3].second.second] = opps(s[vp[3].second.first][vp[3].second.second]);

            solve(x,y);
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            clean();
            cin >> n >> m;

            for (int i=0 ; i<n; i++){
                  cin >> s[i];
            }

            if (n%2){
                  ll x = n-1;
                  for (int y = 0 ; y<m ; y++){

                        if (s[x][y]=='1'){
                              ll x2 = n-2 , y2 = y , x3 = n-2 , y3 = y-1;
                              if (y3<0)y3+=2;

                              G[1].push_back(x);
                              G[2].push_back(y);
                              G[3].push_back(x2);
                              G[4].push_back(y2);
                              G[5].push_back(x3);
                              G[6].push_back(y3);

                              s[x][y] = opps(s[x][y]);
                              s[x3][y3] = opps(s[x3][y3]);
                              s[x2][y2] = opps(s[x2][y2]);
                        }
                  }
            }
            if (m%2){
                  ll y = m-1;
                  for (int x = 0 ; x<m ; x++){

                        if (s[x][y]=='1'){
                              ll x2 = x , y2 = y-1 , x3 = x-1 , y3 = y-1;
                              if (x3<0)x3+=2;

                              G[1].push_back(x);
                              G[2].push_back(y);
                              G[3].push_back(x2);
                              G[4].push_back(y2);
                              G[5].push_back(x3);
                              G[6].push_back(y3);

                              s[x][y] = opps(s[x][y]);
                              s[x3][y3] = opps(s[x3][y3]);
                              s[x2][y2] = opps(s[x2][y2]);
                        }
                  }
            }

            show(n);

            for (int i=0 ; i<n ; i+=2){
                  for (int j=0 ; j<m; j+=2){
                        solve(i,j);
                  }
            }

            cout << G[1].size() << endl;
            for (int i=0 ; i<G[1].size() ; i++)
                  cout << G[1][i]+1 << " " << G[2][i]+1 << " " << G[3][i]+1 << " " << G[4][i]+1 << " " << G[5][i]+1 << " " << G[6][i]+1 << endl;
      }

      return 0;
}

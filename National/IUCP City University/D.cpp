#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

ll k,n,m,G[30][30],mp[30][30] , vis[30][30],cnt[30][30];
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
ll hop_count , hop_dis;

bool check(ll x, ll y)
{
      if (x>=0 && x<n && y>=0 && y<m && G[x][y]==1)return true;
      return false;
}

void rec(ll x, ll y , ll p)
{
      vis[x][y] = p+1;

      if (mp[x][y]==1){
            hop_dis = max(hop_dis,vis[x][y]);
            hop_count++;
      }

      for (int i=0 ; i<4 ; i++){
            if (check(x+dx[i],y+dy[i]) && vis[x+dx[i]][y+dy[i]]==0)
                  rec(x+dx[i],y+dy[i],p+1);
      }
      return;
}

void solve(ll sx, ll sy)
{
      queue<pair<ll,ll> > q;
      for (int i=0 ; i<4 ; i++){
            if (check(sx+dx[i],sy+dy[i])){
                  vis[sx+dx[i]][sy+dy[i]] = 1;
                  q.push({sx+dx[i],sy+dy[i]});
            }
      }

      while(!q.empty()){
            ll x = q.front().first , y = q.front().second;
            q.pop();

            if (mp[x][y]==1){
                  hop_count++;
                  hop_dis = max(hop_dis,vis[x][y]);
            }

            for (int i=0 ; i<4 ; i++){
                  ll nx = x+dx[i] , ny = y+dy[i];
                  if (check(nx,ny) && vis[nx][ny]==0){
                        vis[nx][ny] = vis[x][y]+1;
                        q.push({nx,ny});
                  }
            }
      }
}

int main()
{
      while(scanf("%lld %lld %lld",&k,&n,&m) != EOF){
            memset(mp,0,sizeof mp);
            memset(cnt,0,sizeof cnt);

            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<m ; j++)scl(G[i][j]);
            }

            ll X[50],Y[50];
            for (int i=0 ; i<k ; i++){
                  scl(X[i]);
                  scl(Y[i]);
                  mp[X[i]][Y[i]] = 1;
            }

            ll ans = 10000000012;
            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<m ; j++){
                        if (G[i][j]==0){
                              memset(vis,0,sizeof vis);
                              hop_count = hop_dis = 0;
                              solve(i,j);
//                              show(hop_dis);
                              if (hop_count==k)ans = min(ans,hop_dis);
                        }
                  }
            }

            if (ans==10000000012)printf("-1\n");
            else printf("%lld\n",ans);

      }


      return 0;
}

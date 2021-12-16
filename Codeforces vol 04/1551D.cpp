#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%lld",&w)
#define show(x)         cout << #x << " : " << x << endl
#define inf             100000000000000017
#define maxn            1000006

using namespace std;

ll g[105][105] , n,m,k;
int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

void clean()
{
      for (int i=0 ; i<=n+1 ; i++){
            for (int j=0 ; j<=m+1 ; j++){
                  g[i][j] = 0;
            }
      }
}

ll parity(ll a)
{
      return a%2;
}

ll fillRest(ll domino)
{
      for (int i=1 ; i<n ; i++){
            for (int j=1 ; j<=m ; j++){
                  if (g[i][j]==0){
                        g[i][j] = g[i+1][j] = domino;
                        domino++;
                  }
            }
      }
}

bool solve(ll x, ll y, ll rem, ll domino)
{
//      show(x);
//      show(y);
//      show(rem);
      if (parity(n-x+1)){//n is odd
            if (rem>=(m-y+1)/2){
                  ll new_rem = rem-(m-y+1)/2;
                  for (int j=y ; j<=m ; j+=2){
                        g[x][j] = g[x][j+1] = domino;
                        domino++;
                  }

                  return solve(x+1,y,new_rem,domino);
            }
            else return false;
      }
      else {//n is even
            if (parity(rem))return false;
            else {
                  ll cnt = 0;
                  for (int j=y ; j<m ; j+=2){
                        for (int i=x ; i<=n ; i++){
                              if (cnt<rem){
//                                    cout << i << " : " << j << endl;
                                    g[i][j] = g[i][j+1] = domino;
                                    cnt++;
                                    domino++;
                              }
                        }
                  }
                  fillRest(domino);
                  if (cnt==rem)return true;
                  else return false;
            }
      }
}


set<ll> st;
void polish(ll x, ll y, ll turn)
{
      for (int i=0 ;i<4 ; i++){
            st.insert(g[x+dx[i]][y+dy[i]]);
            if (turn==0 && g[x+dx[i]][y+dy[i]]==g[x][y]){
                  polish(x+dx[i],y+dy[i],1);
            }
      }
      if (turn==0){
      ll found = 1;
      for (int i=0 ; i<26 ; i++){
            ll sz = st.size();
            st.insert(i);
            if (st.size()!=sz){
                  found = i;
                  break;
            }
      }
      for (int i=0 ;i<4 ; i++){
            if (turn==0 && g[x+dx[i]][y+dy[i]]==g[x][y]){
                  g[x+dx[i]][y+dy[i]]= g[x][y] = found;
                  break;
            }
      }
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n),scl(m),scl(k);
            clean();

            ll ans = solve(1,1,k,1);

//            for (int i=1 ; i<=n ; i++){
//                  for (int j=1 ;j<=m ; j++){
//                        cout << g[i][j] << " ";
//                  }
//                  cout << endl;
//            }

            if(ans){
                  printf("YES\n");
                  for (int i=1 ; i<=n ; i++){
                        for (int j=1 ; j<=m ; j++){
                              st.clear();
                              polish(i,j,0);
                        }
                  }

                  for (int i=1 ; i<=n ; i++){
                        for (int j=1 ; j<=m ; j++){
                              cout << (char)('a'+g[i][j]);
                        }
                        cout << endl;
                  }
            }
            else printf("NO\n");
      }

      return 0;
}

/**

*/

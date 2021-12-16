#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 1000000000012

using namespace std;

ll dp[105][105][2][2][2] , n, A[105];

//player 0 - alice , player 1 - bob
//direction 0 - left, direction 1 - right
ll rec(ll x, ll y, ll player, ll direction, ll cont)
{
//      cout << x << " " << y  << " " <<player<< " "<< direction << " " << cont << endl;
      if (dp[x][y][player][direction][cont] != -inf)return dp[x][y][player][direction][cont];
      if (x==y){
            if (player==0){
                  if (cont==0)return dp[x][y][player][direction][cont] = A[x];
                  return dp[x][y][player][direction][cont] = max(A[x],0LL);
            }
            else {
                  if (cont==0)return dp[x][y][player][direction][cont] = 0;
                  return dp[x][y][player][direction][cont] = min(0LL,A[x]);
            }
      }

      if (player==0){
            ll id_x = 1 , id_y = 0;
            if (direction==1)id_x = 0 , id_y = -1;

            ll ret = rec(x+id_x,y+id_y,0,direction,1) + A[x]*id_x + A[y]*(-id_y);
            if (cont==1)
                  ret=max(ret,min(rec(x,y,1,0,0),rec(x,y,1,1,0)));
            return dp[x][y][player][direction][cont] = ret;
      }
      else {
            ll id_x = 1 , id_y = 0;
            if (direction==1)id_x = 0 , id_y = -1;

            ll ret = rec(x+id_x,y+id_y,1,direction,1);
            if (cont==1)
                  ret = min(ret,max(rec(x,y,0,0,0),rec(x,y,0,1,0)));
            return dp[x][y][player][direction][cont] = ret;
      }
}

void clean()
{
      for (int i=0 ; i<105; i++){
            for (int j=0 ; j<105 ; j++){
                  for (int k=0 ; k<2 ; k++){
                        for (int l = 0 ; l<2 ; l++){
                              for (int m=0 ; m<2 ; m++)
                                    dp[i][j][k][l][m] = -inf;
                        }
                  }
            }
      }
}

int main()
{
      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            scanf("%lld",&n);
            ll sum = 0;
            for (int i=1 ; i<=n ; i++){
                  scanf("%lld",&A[i]);
                  sum+=A[i];
            }
            clean();

            ll ans = max(rec(1,n,0,0,0),rec(1,n,0,1,0));

            printf("Case %d: %lld\n",_t,ans+ans-sum);
      }

      return 0;
}
/*
2

4
4 -10 -20 7

4
1 2 3 4
*/

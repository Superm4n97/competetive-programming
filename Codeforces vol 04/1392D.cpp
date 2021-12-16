#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x)         cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            200005

using namespace std;

ll dp[maxn][3][3][3][3] , A[maxn] , n;

void clean()
{
      for (int i=0; i<=n+3 ; i++){
            for (int j = 0 ; j<3 ; j++){
                  for (int k=0 ; k<3 ; k++){
                        for (int l = 0 ; l<3 ; l++){
                              for (int m = 0 ; m<=3 ; m++)
                                    dp[i][j][k][l][m] = -1;
                        }
                  }
            }
      }
}

ll rec(ll pos, ll pre, ll curr, ll start, ll sec)
{

      if(dp[pos][pre][curr][start][sec]!=-1)return dp[pos][pre][curr][start][sec];

      /*if (pos==n+1){
            if (curr!=start)return dp[pos][pre][curr][start] = inf;
            else return dp[pos][pre][curr][start] = 0;
      }*/

      if (pos==n){
            ll a = pre , b = curr , c = start , d = sec;

            if (a==0 && b==0 && c==0)return dp[pos][pre][curr][start][sec] = inf;
            if (a==1 && b==1 && c==1)return dp[pos][pre][curr][start][sec] = inf;
            if (d==1 && b==1 && c==1)return dp[pos][pre][curr][start][sec] = inf;
            if (d==0 && b==0 && c==0)return dp[pos][pre][curr][start][sec] = inf;
            return dp[pos][pre][curr][start][sec] = 0;
      }

      if (pre==1 && curr==0){
            ll offset1 = 0 , offset2 = 0;

            if (pos<n && A[pos+1]!=0)offset1 = 1;
            offset1 += rec(pos+1,0,0,start,sec);

            if (pos<n && A[pos+1]!=1)offset2 = 1;
            offset2 += rec(pos+1,0,1,start,sec);

            return dp[pos][pre][curr][start][sec] = min(offset1,offset2);
      }
      else if (pre==1 && curr==1){
            ll offset = 0;
            if (pos<n && A[pos+1]!=0)offset = 1;

            return dp[pos][pre][curr][start][sec] = rec(pos+1,1,0,start,sec)+offset;
      }
      else if (pre==0 && curr==0){
            ll offset = 0;
            if (pos<n && A[pos+1]!=1)offset = 1;

            return dp[pos][pre][curr][start][sec] = rec(pos+1,0,1,start,sec)+offset;
      }
      else if (pre==0 && curr==1){

            ll offset1 = 0 , offset2 = 0;

            if (pos<n && A[pos+1]!=0)offset1 = 1;
            offset1+= rec(pos+1,1,0,start,sec);

            if (pos<n && A[pos+1]!=1)offset2 = 1;
            offset2+=rec(pos+1,1,1,start,sec);

            return dp[pos][pre][curr][start][sec] = min(offset1,offset2);
      }
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){


            cin >> n;
            clean();

            string s;
            cin >> s;

            for (int i=0 ; i<n ; i++){

                  int x = 0;
                  if (s[i]=='R')x = 1;

                  A[i+1] = x;
            }

            ll ans = inf;

            for (int i=0 ; i<=1 ; i++){
                  for (int j = 0 ; j<=1 ; j++){

                        ll offset = 0;
                        if (A[1]!=i)offset++;
                        if (A[2]!=j)offset++;

                        ll temp = rec(2,i,j,i,j)+offset;

                        /*if (i==1 && j==0){
                              show(temp);
                              show(offset);
                        }*/

                        ans = min(ans,temp);
                  }
            }

            cout << ans << endl;
      }


      return 0;
}

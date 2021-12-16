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

#define maxn            131079

using namespace std;

int dp[maxn][18][27] , n , pw[22];
string s;

ll rec(ll pos , ll len , ll good)
{
      if (dp[pos][len][good]!=-1)return dp[pos][len][good];

      if (len==0){
            ll temp = s[pos]-'a';
            if (temp==good)return dp[pos][len][good] = 0;
            else return dp[pos][len][good] = 1;
      }

      ll t1 = 0 , t2 = 0;

      for (int i=pos ; i<pos+pw[len-1] ; i++){

            ll temp = s[i] - 'a';
            if (temp!=good)t1++;
      }

      for (int i=pos+pw[len-1] ; i<pos+pw[len] ; i++){

            ll temp = s[i] - 'a';
            if (temp!=good)t2++;
      }

      return dp[pos][len][good] = min(rec(pos+pw[len-1] , len-1 ,good+1) + t1 , rec(pos,len-1,good+1)+t2);
}

int main()
{
      pw[0] = 1;
      //K[1] = 0;
      for (int i=1 ;i<=20 ; i++){
            pw[i] = pw[i-1]*2;
            //K[pw[i]] = i;
      }

      ll tc;
      scl(tc);

      while(tc--){

            scl(n);
            cin >> s;

            for (int i=0 ; i<=n+3 ; i++){
                  for (int j = 0 ; j<18 ; j++){
                        for (int k = 0 ; k<27 ; k++)dp[i][j][k] = -1;
                  }
            }

            ll temp = -1 , tut = n;

            while(tut){
                  temp++;
                  tut/=2;
            }



            printf("%I64d\n",rec(0,temp,0));

      }


      return 0;
}

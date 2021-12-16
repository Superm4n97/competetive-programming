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

#define maxn            1000006

using namespace std;

ll dp[105][105];

ll rec(ll even, ll odd)
{
      if (dp[even][odd] != -1)return dp[even][odd];

      if (odd==0){
            return dp[even][odd] = 0;
      }
      if (even==0){
            return dp[even][odd] = odd%2;
      }

      ll t1 = rec(even-1 , odd) , t2 = rec(even , odd-1);

      if(t1==0 || t2==0)return dp[even][odd] = 1;
      else return dp[even][odd] = 0;
}

int main()
{
      memset(dp,-1,sizeof dp);

      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll e = 0;

            for (int i=0 ; i<n ; i++){

                  ll a;
                  cin >> a;

                  if (a%2==0)e++;
            }

            if(n==1)cout << "T" << endl;
            else {
                  ll o = n-e;
                  ll t = 1 , t2 = 1;

                  if (e){
                        t = rec(e-1,o);
                  }
                  if (o)t2+=rec(e,o-1);

                  if (t==0 || t2==0)cout << "T" << endl;
                  else cout << "HL" << endl;
            }
      }


      return 0;
}

/**

*/


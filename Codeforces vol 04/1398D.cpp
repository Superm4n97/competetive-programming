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

ll nr,ng,nb;
ll  dp[205][205][205];

vector < ll > R,G,B;

bool check(ll i,ll j,ll k)
{
      if (i>nr && j>ng)return false;
      if (i>nr && k>nb)return false;
      if (j>ng && k>nb)return false;

      return true;
}

ll rec(ll pos1 , ll pos2 , ll pos3)
{
      if (dp[pos1][pos2][pos3]!=-1)return dp[pos1][pos2][pos3];
      if (!check(pos1,pos2,pos3))return dp[pos1][pos2][pos3] = 0;

      ll t1 = 0 , t2 = 0 , t3 = 0;

      if (pos1<=nr && pos2<=ng)t1 = rec(pos1+1,pos2+1,pos3) + R[pos1]*G[pos2];

      if (pos1<=nr && pos3<=nb)t2 = rec(pos1+1,pos2,pos3+1) + R[pos1]*B[pos3];

      if (pos2<=ng && pos3<=nb)t3 = rec(pos1,pos2+1,pos3+1) + G[pos2]*B[pos3];

//      cout << " \n " << pos1 << " " << pos2 << " " << pos3 << endl;
//      show(t1);
//      show(t2);
//      show(t3);

      return dp[pos1][pos2][pos3] = max(t1,max(t2,t3));
}

int main()
{
      memset(dp,-1,sizeof dp);

      cin >> nr >> ng >> nb;

      inputll(R,nr);
      inputll(G,ng);
      inputll(B,nb);

      srt(R);
      srt(G);
      srt(B);

      R.push_back(0);
      G.push_back(0);
      B.push_back(0);

      reverse(R.begin(),R.end());
      reverse(G.begin(),G.end());
      reverse(B.begin(),B.end());

      cout << rec(1,1,1) << endl;


      return 0;
}

/*
3 1 1
1 2 3
4
5
*/

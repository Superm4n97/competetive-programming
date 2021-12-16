#include<bits/stdc++.h>
#define ll long long int
#define maxn 2000006

using namespace std;

ll n, k = 0 , mod = 1e9+7;
ll dp[maxn][5][5];

string s;

ll pw(ll a, ll p)
{
      if (p==0)return 1;
      if(p==1) return a;

      ll temp = pw(a,p/2);
      temp = (temp*temp)%mod;

      if (p%2==1)temp = (temp*a)%mod;

      return temp;
}

ll rec(ll pos, ll mached, ll dcr)
{
      if (dp[pos][mached][dcr] != -1)return dp[pos][mached][dcr];
      if (mached==3){
            return pw(3,k-dcr);
            //return P[k-dcr];
      }
      if (pos>=n)return 0;

      ll t1 = rec(pos+1,mached,dcr) , t2 = 0;

      if (s[pos]=='?')t2 = rec(pos+1 , mached+1, dcr+1);
      else if ((s[pos]=='a'&&mached==0) || (s[pos]=='b'&&mached==1) || (s[pos]=='c'&&mached==2))
            t2 = rec(pos+1,mached+1,dcr);

      t1 = (t1+t2)%mod;

      return dp[pos][mached][dcr] = t1;
}

int main()
{
      cin >> n;
      cin >> s;

      memset(dp,-1,sizeof dp);

      for (int i=0 ;i<n ;i++){
            if (s[i]=='?')k++;
      }

      cout << rec(0,0,0) << "\n";

      return 0;
}

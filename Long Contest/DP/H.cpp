#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll palin[22] , n;
string s;
ll dp[22][4][4];

//0-equal, 1-small, 2-large
ll rec(ll l, ll lessL, ll lessR)
{
      if (dp[l][lessL][lessR] != -1)return dp[l][lessL][lessR];
      if (lessL==2)return dp[l][lessL][lessR] = 0;
      ll r = n-l-1;

      if (l>r){
            if (lessL==1)return dp[l][lessL][lessR] = 1;
            else{
                  if (lessR==2)return dp[l][lessL][lessR] = 0;
                  else return dp[l][lessL][lessR] = 1;
            }
      }

      if (lessL==0){
            ll ch = '0';
            if (l==0)ch = '1';
            ll ret = 0;
            for (char c = ch; c<='9' ; c++){
                  ll p,q;
                  if (c>s[l])p = 2;
                  else if (c<s[l])p = 1;
                  else p = 0;

                  if (c>s[r])q = 2;
                  else if (c<s[r])q = 1;
                  else q = lessR;
                  ret+=rec(l+1,p,q);
            }
            return dp[l][lessL][lessR] = ret;
      }
      else {
            ll ret = 0;
            for (char c = '0'; c<='9' ; c++){
                  ret+=rec(l+1,lessL,lessR);
            }
            return dp[l][lessL][lessR] = ret;
      }
}

ll howManyPalindrome(ll a)
{
      if (a<0LL)return 0;
      if (a==0)return 1;
      s = "";
      while(a){
            char ch = '0';
            ch+=(a%10);
            s.push_back(ch);
            a/=10;
      }
      n = s.size();
      reverse(s.begin(),s.end());
      memset(dp,-1,sizeof dp);
      return palin[n-1]+rec(0,0,0);
}

int main()
{
      palin[0] = 1;
      palin[1] = 9;
      for (int i=2 ; i<22 ; i++){
            if (i%2==1)palin[i] = palin[i-1]*10;
            else palin[i] = palin[i-1];
      }
      for (int i=1 ; i<22 ; i++)palin[i]+=palin[i-1];

      int tc;
      scanf("%d",&tc);

      for (int _t=1 ; _t<=tc ; _t++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            if (a>b)swap(a,b);

            printf("Case %d: %lld\n",_t,howManyPalindrome(b)-howManyPalindrome(a-1));
      }
}
/*
1
6022 6398

6116
6226
6336
*/

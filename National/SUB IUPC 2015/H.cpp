#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000050
#define mod 1000000007

using namespace std;

string s;
ll n = 22;
ll dp[25][3][3];

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll rec(ll pos, ll isStart, ll isSmall)
{
      if (pos==n){
            if (isStart==0)return 0;
            else return 1;
      }
      if (dp[pos][isStart][isSmall] != -1)return dp[pos][isStart][isSmall];

      if (isStart==0){
            ll x_sm =isSmall;
            if (s[pos] != '0')x_sm = 1;
            ll ret = rec(pos+1,isStart,x_sm);

            if (isSmall==1){
                  for (ll i = 1 ; i<10 ; i++){
                        ret = amod(ret+amod(i*rec(pos+1,1,1)));
                  }
            }
            else if (s[pos]>'0'){
                  for (ll i = 1 ; i+'0'<s[pos] ; i++){
                        ret = amod(ret+amod(i*rec(pos+1,1,1)));
                  }
                  if (s[pos]!='0')ret = amod(ret+amod(((ll)(s[pos]-'0'))*rec(pos+1,1,0)));
            }
            return dp[pos][isStart][isSmall] = ret;
      }
      else {
            ll ret = 0;
            if (isSmall==1){
                  for (ll i = 1 ; i<10 ; i++){
                        ret = amod(ret+amod(i*rec(pos+1,1,1)));
                  }
            }
            else{
                  for (ll i = 1 ; i+'0'<s[pos] ; i++){
                        ret = amod(ret+amod(i*rec(pos+1,1,1)));
                  }
                  if (s[pos]!='0')ret = amod(ret+amod(((ll)(s[pos]-'0'))*rec(pos+1,1,0)));
            }
            return dp[pos][isStart][isSmall] = ret;
      }

}

void makeString(ll x)
{
      memset(dp,-1,sizeof dp);
      s = "";
      for (int i=0 ; i<22 ; i++)s.push_back('0');
      for (int i=21 ; x>0 ; i--){
            s[i] = (x%10)+'0';
            x/=10;
      }
      n = s.size();
}

int main()
{
      memset(dp,-1,sizeof dp);
      int tc;
      scanf("%d",&tc);

      for (int i=1 ; i<=tc ; i++){
            ll a,b;
            scanf("%lld %lld",&a,&b);
            makeString(b);
            b = rec(0,0,0);
            makeString(a-1);
            a = rec(0,0,0);
            printf("Case %d: %lld\n",i,amod(b-a+mod));
      }


      return 0;
}

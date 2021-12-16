#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define mod 1000000007

using namespace std;

ll F[maxn], ncr[maxn][maxn];

ll amodb(ll a)
{
      return  a - a/mod*mod;
}

ll combination(ll n, ll r)
{
      if (ncr[n][r] != -1)return ncr[n][r];
      if (r>n)return 0;
      if (n==r || r==0)return ncr[n][r] = 1;
      if (r==1)return ncr[n][r] = n;

      return ncr[n][r] = amodb(combination(n-1,r) + combination(n-1,r-1));
}

ll pw(ll a,ll p)
{
      if (p==0)return 1;
      ll temp = pw(a,p/2);
      temp = amodb(temp*temp);
      if (p%2)temp = amodb(temp*a);
      return temp;
}

ll Stirling(ll n, ll k)
{
      ll ret = 0;
      for (ll i=0 ; i<=k; i++){
            if (i%2) ret = amodb(ret+mod-amodb(combination(k,i)*pw(k-i,n)));
            else ret = amodb(ret+amodb(combination(k,i)*pw(k-i,n)));
      }

      //return ret; /// returns S(n,k)*k!
      return amodb(ret*pw(F[k],mod-2)); /// returns S(n,k) , only applicable for mod prime,used mod-inverse
}

void initial()
{
      memset(ncr,-1,sizeof ncr);
      F[0] = 1;
      for (int i=1 ; i<maxn ; i++)F[i] = amodb(F[i-1]*i);
}

int main()
{
      initial(); ///must call

      show(Stirling(1000,50));

      return 0;
}

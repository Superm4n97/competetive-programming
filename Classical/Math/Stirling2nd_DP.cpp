///it can find all Stirling Number in O(n*n) time
///check mod value
#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define mod 1000000007

using namespace std;

ll F[maxn], S[maxn][maxn];

ll amodb(ll a)
{
      return  a - a/mod*mod;
}

ll Stirling(ll n, ll k)
{
      if (S[n][k] != -1)return S[n][k];
      if (k==0)return S[n][k] = 0;
      if (k==n || k==1)return S[n][k] = 1;
      return S[n][k] = amodb(k*Stirling(n-1,k) + Stirling(n-1,k-1));
}

void initial()
{
      memset(S,-1,sizeof S);
      F[0] = 1;
      for (int i=1 ; i<maxn ; i++)F[i] = (F[i-1]*i)%mod;
}

int main()
{
      initial();///must call

      show(Stirling(1000,50));


      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005
#define mod 10056

using namespace std;

ll F[maxn], S[maxn][maxn] , ncr[maxn][maxn];

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

ll Stirling(ll n, ll k)
{
      if (S[n][k] != -1)return S[n][k];
      if (k==0)return S[n][k] = 0;
      if (k==n || k==1)return S[n][k] = 1;
      return S[n][k] = amodb(k*Stirling(n-1,k) + Stirling(n-1,k-1));
}

ll pw(ll a,ll p)
{
      if (p==0)return 1;
      ll temp = pw(a,p/2);
      temp = amodb(temp*temp);
      if (p%2)temp = amodb(temp*a);
      return temp;
}

ll Stirling_2nd(ll n, ll k)
{
      ll ret = 0;
      for (ll i=0 ; i<=k; i++){
            if (i%2){
                  ret = amodb(ret+mod-amodb(combination(k,i)*pw(k-i,n)));
            }
            else {
                  ret = amodb(ret+amodb(combination(k,i)*pw(k-i,n)));
            }
      }

      return ret;
}

int main()
{
      memset(S,-1,sizeof S);
      memset(ncr,-1,sizeof ncr);
      F[0] = 1;
      for (int i=1 ; i<maxn ; i++)F[i] = (F[i-1]*i)%mod;
      {
            //ll k = 2 , n = 2, ans1 = 0;
            ll k = 50 , n = 1000, ans1 = 0;
            for (ll i=0 ; i<=k; i++){
                  if (i%2){
                        ans1 = amodb(ans1+mod-amodb(combination(k,i)*pw(k-i,n)));
                  }
                  else {
                        ans1 = amodb(ans1+amodb(combination(k,i)*pw(k-i,n)));
                  }
            }
            show(ans1);
            ans1 = amodb(Stirling(n,k)*F[k]);
            show(ans1);
      }

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n,k ,ans = 0;
            scanf("%lld",&n);

            for (ll i=1 ; i<=n ; i++){
                  ans = amodb(ans+amodb(Stirling(n,i)*F[i]));
            }
            printf("Case %d: %lld\n",_t,ans);
      }


      return 0;
}

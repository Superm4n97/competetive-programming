#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define mod 1000000007

using namespace std;

ll n, s , A[30], IN[32];

ll amodb(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2);
      temp = amodb(temp*temp);
      if (p&1)temp = amodb(temp*a);
      return temp;
}

void init()
{
      IN[0] = 1;
      for (ll i=1 ; i<32 ; i++)IN[i] = amodb(i*IN[i-1]);
      IN[31] = bigmod(IN[31],mod-2);
      for (ll i=30 ; i>=0 ; i--)IN[i] = amodb(IN[i+1]*(i+1));
}

ll ncr(ll N, ll R)
{
      if (N<R)return 0;
      ll ret = 1;

      for (int i=0 ; i<R ; i++){
            ret = amodb(ret*amodb(N-i));
      }
      return amodb(ret*IN[R]);
}

int main()
{
      init();

      scanf("%I64d %I64d",&n,&s);

      for (int i=0; i<n ; i++)scanf("%I64d",&A[i]);

      ll lim = 1;
      for (int i=0 ; i<n ;i++)lim*=2;

      ll ans = ncr(s+n-1,n-1);

      for (int i=1 ; i<lim ; i++){
            ll a = i , cnt = 0 , temp = s;
            for (int j=0 ; j<n ; j++){
                  if (a&1){
                        cnt++;
                        temp-=(A[j]+1);
                  }
                  a/=2;
            }

            temp = ncr(temp+n-1 , n-1);
            if (cnt&1)ans = amodb(ans+mod-temp);
            else ans = amodb(ans+temp);
      }

      printf("%I64d\n",ans);

      return 0;
}

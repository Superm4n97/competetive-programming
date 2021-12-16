#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define mod 998244353

using namespace std;

ll F[maxn];

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a, p/2);
      temp = (temp*temp)%mod;
      if (p%2==1)temp = (temp*a)%mod;
      return temp;
}

ll modInverse(ll x)
{
      return bigmod(x,mod-2);
}

ll ncr(ll n, ll r)
{
//      show(n);
//      show(r);
//      show(F[n-r]);
//      show(F[r]);
      ll a = modInverse((F[n-r]*F[r])%mod);
//      show(a);
      return (F[n]*a)%mod;
}

int main()
{
      F[0] = 1;
      for (ll i=1 ; i<maxn ; i++)F[i] = (F[i-1]*i)%mod;

      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            scanf("%lld",&n);
            string s;
            cin >> s;
            ll zeros = 0 , ones = 0;
            char pre = s[0];
            if (pre == '0')zeros++;

            for (int i=1 ; i<n ; i++){
                  if (s[i]=='0'){
                        zeros++;
                        pre = '0';
                  }
                  else {
                        if (pre=='1'){
                              ones++;
                              pre = '0';
                        }
                        else {
                              pre = '1';
                        }
                  }
            }
            printf("%lld\n",ncr(zeros+ones,ones));
      }

      return 0;
}

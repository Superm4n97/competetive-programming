#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define mod 132021913

using namespace std;

vector<ll> D[maxn];
ll s[maxn] , g[maxn] , f[maxn];

void initialize()
{
      for (int i=1 ; i<maxn ; i++){
            for (int j=i ; j<maxn ; j+=i)D[j].push_back(i);
      }
}

ll amodb(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2);
      temp = amodb(temp*temp);

      if (p%2)temp = amodb(temp*a);
      return temp;
}

int main()
{

      initialize();

      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            ll n;
            scanf("%lld",&n);

            memset(s,0,sizeof s);
            memset(g,0,sizeof g);
            memset(f,0,sizeof f);

            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);

                  for (int j=0 ; j<D[a].size() ; j++){
                        ll d = D[a][j];
                        f[d] = amodb(f[d]+amodb(a*s[d]));
                        s[d] = amodb(s[d]+a);
                  }
            }

            ll ans = 0;

            for (ll i = maxn-3 ; i>=1 ; i--){


                  for (int j=i+i ; j<maxn ; j+=i){
                        f[i] = amodb(f[i]+mod-f[j]);
                  }
                  g[i] = amodb(f[i]*bigmod(i,mod-2));
                  ans = amodb(ans+g[i]);
            }

            printf("Case %d: %lld\n",_t,ans);
      }

      return 0;
}

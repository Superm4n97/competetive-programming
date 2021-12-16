#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005
#define mod 132021913

using namespace std;

ll x[maxn], s[maxn],cnt[maxn] , inv[maxn] , n;

ll amod(ll a)
{
      return a - a/mod*mod;
}

ll bigmod(ll a, ll p)
{
      if (p==0)return 1;
      ll temp = bigmod(a,p/2);
      temp = amod(temp*temp);
      if (p&1LL)temp = amod(temp*a);
      return temp;
}

void init()
{
      memset(x,0,sizeof x);
      memset(s,0,sizeof s);
      memset(cnt,0,sizeof cnt);
}

ll solve()
{
      ll ret = 0;
      for (ll i=maxn-2 ; i>0 ; i--){
            for (ll j=i ; j<maxn ; j+=i){
                  s[i]=amod(s[i]+cnt[j]*j);
            }
            x[i] = amod(s[i]*s[i]);
            for (ll j=i+i ; j<maxn ; j+=i){
                  x[i] = amod((x[i]-x[j])+mod);
            }
            ll temp = amod(x[i] - amod(cnt[i]*amod(i*i)) + mod);
            temp = amod(temp*inv[2]);
            temp = amod(temp*inv[i]);
            ret = amod(ret+temp);
      }
      return ret;
}

int main()
{
      for (ll i=1 ; i<maxn ; i++)inv[i] = bigmod(i,mod-2);
      int tc;
      scanf("%d",&tc);

      for (int _t = 1 ; _t<=tc ; _t++){
            init();
            scanf("%lld",&n);
            for (int i=0 ; i<n ; i++){
                  ll a;
                  scanf("%lld",&a);
                  cnt[a]++;
            }
            printf("Case %d: %lld\n",_t,solve());
      }

      return 0;
}

/*  a b c
1 3 2 6 8

(a+b+c)*(a+b+c)
a*a a*b b*a b*b
(a*b + b*c + a*c) / 2
a*b/3 + (b*c)/3 + (c*a)/3
2->

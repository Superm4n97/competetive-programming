#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 600005
#define md 998244353

using namespace std;

ll n;
vector < ll > v;
ll F[maxn];

ll pw(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a;

      ll temp = pw(a,p/2);
      temp = (temp*temp)%md;

      if (p%2) temp = (temp*a)%md;

      return temp;
}

int main()
{
      cin >> n;
      for (int i=0 ; i<2*n;  i++){
            ll a;
            cin >> a;

            v.push_back(a);
      }

      sort(v.begin(),v.end());

      ll x  = 0;

      for (int i=0 ,j = 2*n-1; i<n ; i++ , j--){
            x+=(v[j]-v[i]);
            x%=md;
      }

      F[0] = 1;
      for (ll i=1 ; i<maxn ; i++){
            F[i]=F[i-1]*i;
            F[i]%=md;
      }

      ll lw = (F[n]*F[n]) % md;


      lw = pw(lw,md-2);
//      show(lw);
//      show(F[2*n]);

      ll ans = (F[2*n]*lw)%md;
      ans = (ans*x)%md;
      cout << ans << "\n";

      return 0;
}

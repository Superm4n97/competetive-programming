#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,m;
vector<ll> phi , v;

void createphi(ll a)
{
      ll res = a , x = a;
      for (ll i=2 ; i*i<=x ;i++){
            if (x%i==0){
                  res = res*(i-1)/i;
                  while(x%i==0)x/=i;
            }
      }
      if (x>1)res = res*(x-1)/x;

      phi.push_back(res);
      if (res==1)return;
      createphi(res);
      return;
}

ll amodb(ll a, ll b)
{
      if (a<b)return a;
      ll temp = a/b;
      temp = a - temp*b;
      temp+=b;
      return temp;
}

ll bigmod(ll a, ll pw, ll mod)
{
      if (pw==0)return 1;
      ll x = bigmod(a,pw/2,mod);
      x = amodb(x*x,mod);
      if (pw%2)x = amodb(x*a,mod);
      return x;
}

ll rec(ll st ,ll ed, ll md)
{
      if (st==ed){
            //return v[st];
            return amodb(v[st],phi[md]);
      }
      if (phi[md]==1)return 1LL;
//            show(phi[md]);
//            show(amodb(v[st],phi[md]));

      return bigmod(v[st],rec(st+1,ed,md+1),phi[md]);
}

int main()
{
      cin >> n >> m;
      for (int i=0 ; i<n;  i++){
            ll a;
            cin >> a;
            v.push_back(a);
      }
      phi.push_back(m);
      createphi(m);

      ll q;
      cin >> q;
      while(q--){
            ll l, r;
            cin >> l >> r;

            cout << rec(l-1,r-1,0LL)%m << "\n";
      }

      return 0;
}

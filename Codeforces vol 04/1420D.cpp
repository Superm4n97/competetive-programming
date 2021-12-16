#include<bits/stdc++.h>
#define ll long long int
#define maxn 900005
#define show(x) cout << #x << " : " << x << endl
#define mod 998244353

using namespace std;

//map < ll,ll > start , finished , chk;
ll F[maxn] , n , k , ans = 0, start[maxn],finished[maxn];
vector < ll > vx, v , st , fn;

ll Normal(ll a)
{
      ll temp = a / mod;
      temp *= mod;

      a -= temp;

      if (a<0)a += mod;

      return a;
}

ll Summation(ll a, ll b)
{
      a += b;
      if (a >= mod)a -= mod;
      return a;
}

ll Substraction(ll a, ll b)
{
      a -= b;
      if(a<0)a += mod;
      return a;
}

ll Multiplication(ll a, ll b)
{
      a *= b;
      ll temp = a/mod;
      temp *= mod;

      return a - temp;
}

ll bigMod(ll a, ll p)
{
      if (p==0)return 1;
      if (p==1)return a % mod;

      ll temp = bigMod(a,p/2);

      temp = Multiplication(temp,temp);

      if (p%2)temp = Multiplication(temp,a);

      return temp;
}

ll modInverse(ll a)
{
      return bigMod(a,mod-2);
}


ll ncr(ll N, ll R)
{
      if (N<R)return 0;

      ll a = F[N] , b = Multiplication(F[N-R],F[R]);
      //show(a);
      //show(b);
      b = modInverse(b);

      return Multiplication(a,b);
}

int main()
{

      F[0] = 1;
      for (ll i=1 ; i<maxn-1 ; i++){
            F[i] = Multiplication(F[i-1],i);
      }

      //cin >> n >> k;

      scanf("%I64d %I64d",&n,&k);

      for (ll i=1 ; i<=n ; i++){
            ll l , r;
            //cin >> l >> r;
            scanf("%I64d %I64d",&l,&r);

            st.push_back(l);
            fn.push_back(r);
            vx.push_back(l);
      }
      sort(st.begin() , st.end());
      sort(fn.begin() , fn.end());



      //for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
      //cout << endl;

      ll pre = 0;

      for (ll i = 0 ; i<v.size() ; i++){
            ll new_start = start[v[i]];


            ll a = Substraction(ncr(new_start+pre,k),ncr(pre,k));
            ans=Summation(ans,a);

            /*
            show(v[i]);
            show(new_start);
            show(pre);
            show(a);
            cout << endl;
            */

            pre+=new_start;
            pre-=finished[v[i]];
      }

      cout << ans << endl;




      return 0;
}


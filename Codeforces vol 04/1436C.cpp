#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,x, pos , choto = 0, boro = 0 ,nCr[1005][1005];
ll mod = 1e9+7;

ll BinarySearch()
{
      ll lf = 0 , rg = n , cnt = 0;
      while(lf<rg){

            ll mid = (lf+rg)/2;
            cnt++;
            //show(mid);
            if (mid<=pos)lf = mid+1 , choto++;
            else rg = mid , boro++;
      }

      return cnt;
}

ll fact(ll a)
{
      if (a<=1)return 1;

      ll temp = fact(a-1)*a;
      temp%=mod;

      return temp;
}

ll combination(ll N, ll R)
{
      if (R>N)return 0;
      if (nCr[N][R] != -1)return nCr[N][R];
      if (N==R || R==0)return nCr[N][R] = 1;
      if (R==1)return nCr[N][R] = N;

      nCr[N][R] = (combination(N-1,R)+combination(N-1,R-1))%mod;
      return nCr[N][R];
}

int main()
{
      memset(nCr,-1,sizeof nCr);
      cin >> n >> x >> pos;


      ll temp = BinarySearch();
      choto--;


//      show(choto);
//      show(boro);
//      show(combination(x-1,choto));

      ll tut = (combination(x-1,choto) * combination(n-x,boro))%mod;
      tut = (tut * fact(choto))%mod;
      tut = (tut* fact(boro))%mod;


      ll ans = tut*fact(n-temp);
      ans%=mod;

      cout << ans << "\n";


      return 0;
}

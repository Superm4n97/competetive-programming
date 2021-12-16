#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(w) scanf("%lld",&w)
#define maxn 100005

using namespace std;

ll dv[maxn*10] , A[maxn] , mn = maxn*100 , n , cnt = 0;
vector<ll> divisor;

ll findDIV(ll a)
{
      for (int i=1 ; i*i<=a ; i++){
            if (a%i==0){
                  if (dv[i]==0){
                        dv[i] = 1;
                        divisor.push_back(i);
                  }
                  if (dv[a/i]==0){
                        dv[i] = 1;
                        divisor.push_back(a/i);
                  }
            }
      }
}

ll amodb(ll a, ll b)
{
      ll temp = a/b;
      return a - temp*b;
}

int main()
{
      scl(n);
      for (int i=1 ; i<=n ; i++){
            scl(A[i]);
            mn = min(mn,A[i]);
      }
      findDIV(mn-1);
      findDIV(mn);
      findDIV(mn+1);

      sort(divisor.rbegin(),divisor.rend());

      for (int j = 0 ; j<divisor.size() ; j++){

            ll d = divisor[j] , cnt = 0;
            bool sol = true;
            for (int i=1 ; i<=n ; i++){

                  ll md = amodb(A[i],d);

                  if (md>1 && md<d-1){
                        sol = false;
                        break;
                  }
                  if(amodb(A[i],d)!=0)cnt++;
            }

            if (sol){
                  printf("%lld %lld\n",d,cnt);
                  return 0;
            }
      }

      return 0;
}

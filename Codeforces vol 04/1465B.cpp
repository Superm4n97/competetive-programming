#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll amodb(ll a, ll b)
{
      return a - (a/b*b);
}

bool fair(ll n)
{
      ll a = n;
      while(a){
            ll temp = a%10;
            a/=10;
            if (temp>0){
                  if (n%temp)return false;
            }
      }
      return true;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n;
            scl(n);
            while(true){
                  if (fair(n)){
                        printf("%lld\n",n);
                        break;
                  }
                  n++;
            }
      }

      return 0;
}

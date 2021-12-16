#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 200005
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll n , x;
            cin >> n >> x;

            ll a = 0 , b = 0 , sum = 0;
            for (int i=0 ; i<n ; i++){
                  ll p;
                  cin >> p;
                  a+=((p+x-1)/x);
                  sum+=p;
            }
            b = (sum+x-1)/x;
            cout << b << " " << a << endl;
      }

      return 0;
}

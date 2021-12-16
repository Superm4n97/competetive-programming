#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define maxn 5005

using namespace std;

ll s[maxn];

int main()
{
      ll sum = 0;
      for (ll i = 1 ; sum+i < maxn ; i+=2){
            s[sum+i] = (i/2)+1;
            sum+=i;
      }
      sum = 0;
      for (int i=1 ; i<maxn-1; i++){
            if (s[i]!=0){
                  sum = 0;
            }
            else {
                  if (sum==0){
                        s[i] = s[i-1]+1;
                        sum++;
                  }
                  else s[i] = s[i-1];
            }
      }
      ll tc;
      cin >> tc;
      while(tc--){
            ll a;
            cin >> a;
            cout << s[a] << endl;
      }

      return 0;
}

#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%lld",&w)
#define show(x)         cout << #x << " : " << x << endl
#define inf             100000000000000017
#define maxn            1000006

using namespace std;


int main()
{
      ll tc;
      scl(tc);
      while(tc--){

            string s;
            cin >> s;

            sort(s.begin(),s.end());

            ll ans = 1 , cnt = 1;

            for (int i=1 ; i<s.size() ; i++){
                  if (s[i]== s[i-1])cnt++;
                  else cnt = 1;

                  if (cnt<=2)ans++;
            }
            printf("%lld\n",ans/2);
      }

      return 0;
}

/**

*/

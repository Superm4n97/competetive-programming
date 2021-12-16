#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%lld",&w)
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

ll n;
ll A[15+5];

bool rec(ll pos, ll rem, ll taken_index)
{
//      cout << pos << " : " << rem << endl;
      if (rem==0)return true;
      if (pos>n)return false;
      if (pos==taken_index)return rec(pos+1,rem,taken_index);

      return (rec(pos+1,rem-A[pos],taken_index)|rec(pos+1,rem, taken_index)||rec(pos+1,rem+A[pos], taken_index));
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(n);
            for (int i=1 ; i<=n ; i++){
                  scl(A[i]);
            }

            bool sol = false;

            for (int i=1 ; i<=n ; i++){
                  sol = (sol|rec(1,A[i],i));
            }
            if (sol)printf("YES\n");
            else printf("NO\n");
      }

      return 0;
}

/**

*/

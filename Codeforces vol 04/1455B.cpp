#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll perfect(ll n)
{
      ll b = 1, e = 1000006 ,  ans = 1000006 ;
      while(b<=e){

            ll mi = (b+e)/2;
            if (mi*(mi+1)/2>=n){
                  ans = min(ans,mi);
                  e = mi-1;
            }
            else b = mi+1;
      }
      return ans;
}

int main()
{
      ll tc;
      scanf("%I64d",&tc);

      while(tc--){

            ll n;
            cin >> n;
            ll pf = perfect(n);

            if (pf*(pf+1)/2==n+1)pf++;
            printf("%I64d\n",pf);

      }

      return 0;
}

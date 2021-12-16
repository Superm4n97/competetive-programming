#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){

            ll n,q;
            scl(n),scl(q);

            string s;
            cin >> s;

            ll A[n+5];
            A[0] = 0;
            for (int i=1 ; i<=n ; i++){
                  if (s[i-1]=='-')A[i]=A[i-1]-1;
                  else A[i] = A[i-1]+1;
            }

            ll lmx[n+5] , lmn[n+5] , rmx[n+5] , rmn[n+5];
            lmx[0] = lmn[0] = 0;
            for (int i=1 ; i<=n ; i++){
                  lmx[i] = max(lmx[i-1],A[i]);
                  lmn[i] = min(lmn[i-1],A[i]);
            }

//            A[n+1] = rmx[n+1] = rmn[n+1] = 0;
            A[n+1] = A[n];
            rmx[n+1] = rmx[n];
            rmn[n+1] = rmn[n];

            rmx[n] = rmn[n] = A[n];
            for (int i=n-1 ; i>=1 ; i--){
                  rmx[i] = max(rmx[i+1],A[i]);
                  rmn[i] = min(rmn[i+1],A[i]);
            }

            while(q--){
                  ll l,r;
                  scl(l),scl(r);

                  ll x1 = lmx[l-1] , y1 = lmn[l-1] , cur = A[l-1];
                  ll a = rmx[r] - A[r] , b = A[r] - rmn[r];
                  ll x2 = cur+a , y2 = cur-b;

//                  show(x1);
//                  show(y1);
//                  show(cur);
//                  show(a);
//                  show(b);
//                  show(x2);
//                  show(y2);

                  ll x = max(x1,x2) , y = min(y1,y2);

                  printf("%I64d\n",x-y+1);
            }
      }

      return 0;
}
/*
1
8 4
-+--+--+
1 8
2 8
2 5
1 1
*/

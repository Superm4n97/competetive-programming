#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x);
#define maxn 1000000

using namespace std;

ll p[maxn], w[]={11,111,1111,11111,111111,1111111,11111111,111111111} , n;

int main()
{
      ll lst = 0, cnt = 0;
      p[0] = 1;
      for (ll i=11 ; i<maxn ; i++){
            for (ll j=0 ; j<8 ; j++){
                  if (i-w[j]>=0 && p[i-w[j]]==1)p[i] = 1;
            }
            if (p[i]==0){
                  lst = i;
            }
            else cnt++;
      }

//      show(cnt);
//      show(lst);

      ll tc;
      scl(tc);
      while(tc--){
            cin >> n;
            if (n<maxn && p[n]==0)cout << "NO" << endl;
            else cout << "YES" << endl;
      }


      return 0;
}
/*
1
12345688
12343555
12334555
55555
99
11
110
121

999

110
121
1110
1010
2020
1021

11111
10000
 1000
  100
   10
    1

1111
11*10 = 110
11*100 = 1100

*/

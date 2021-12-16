#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;
string s;

void solve()
{
      for (int i=0  ; i<n ; i++){
            if (s[i]=='0'){
                  if (i+1 <= (n/2))cout << i+2 << " " << n << " " << i+1 << " " << n << endl;
                  else cout << "1 " << i+1 << " 1 " << i << endl;
                  return;
            }
      }
      cout << "1 " << n-1 << " 2 " << n << endl;
      return;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            cin >> n;
            cin >> s;
            solve();
      }
      return 0;
}
/*
*n/2 er ageh 0 thakle _0:n & _0+1:n
*n/2 length pore giye ekta 0 paile [1 : _0]  &  [1 : _0+1]
*sob 1 hole 1:n-1 & 2:n
*n jodi odd hoy then [n/2+1:n-1] & n/2+2:n
*(n even) n/2 jodi 1 hoy n/2:n-1 & n/2+1:n
*
###01111
11011

+-+-+-+-+-+-+-+-
+--++---++-
#####+-++--

+--++---+++---
++--++-++-++-+
12345678901234
+-+-+-+-+-+-+-+-+-
+--++---++-++-
++--++-++---++
12101212321012

12345678901234
+-+-+-+-+-+-+-+-+-
+--+--++-++-
++---++---++
*/

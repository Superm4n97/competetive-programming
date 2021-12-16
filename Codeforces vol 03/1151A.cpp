#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x<< endl

using namespace std;

string s;
ll ans = 10000000000013;

ll convertA(char ch)
{
      ll t1 = abs(ch-'A') , t2 = ch+26-'A', t3 = 'A'+26-ch;
      return min(t1,min(t2,t3));
}

ll convertC(char ch)
{
      ll t1 = abs(ch-'C') , t2 = ch+26-'C', t3 = 'C'+26-ch;
      return min(t1,min(t2,t3));
}

ll convertT(char ch)
{
      ll t1 = abs(ch-'T') , t2 = ch+26-'T', t3 = 'T'+26-ch;
      return min(t1,min(t2,t3));
}

ll convertG(char ch)
{
      ll t1 = abs(ch-'G') , t2 = ch+26-'G', t3 = 'G'+26-ch;
      return min(t1,min(t2,t3));
}

int main()
{
      ll n;
      cin >> n;

      cin >> s;

      for (int i=0 ; i<n-3 ; i++){
//            show(convertA(s[i]));
//            show(convertC(s[i+1]));
//            show(convertT(s[i+2]));
//            show(convertG(s[i+3]));
            ans = min(ans,convertA(s[i])+convertC(s[i+1])+convertT(s[i+2])+convertG(s[i+3]));
      }
      cout << ans << endl;


      return 0;
}

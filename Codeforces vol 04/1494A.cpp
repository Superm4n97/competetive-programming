#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;scl(tc);

      while(tc--){
            string s;
            cin >> s;

            ll a = 0 , b = 0 , c = 0;

            for (int i=0 ; i<s.size() ; i++){
                  if (s[i]=='A')a++;
                  else if (s[i]=='B')b++;
                  else c++;
            }

            if (a==b+c){
                  a = 1;
                  b = c = -1;
            }
            else if (b==a+c){
                  b = 1;
                  c = a = -1;
            }
            else if (c == a+b){
                  c = 1;
                  a = b = -1;
            }
            else {
                  cout << "NO" << endl;
                  continue;
            }

            ll pos = 0 , neg = 0 , cnt = 0;

            for (int i=0 ; i<s.size() ; i++){
                  if (s[i]=='A')cnt+=a;
                  else if (s[i]=='B')cnt+=b;
                  else cnt+=c;

                  if (cnt>0)pos = 1;
                  if (cnt<0)neg = 1;
            }

            if (cnt || (pos&&neg))cout << "NO" << endl;
            else cout << "YES" << endl;
      }


      return 0;
}

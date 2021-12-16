#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;scl(tc);

      while(tc--){
            ll x, y;
            scl(x) , scl(y);

            string s;
            cin >> s;

            ll l = 0 , r = 0 , u = 0 , d = 0;
            for (int i=0; i<s.size() ; i++){
                  if (s[i]=='U')u++;
                  else if (s[i]=='D')d++;
                  else if (s[i]=='L')l++;
                  else r++;
            }

            bool sol = true;

            if (x>0 && r<x)sol= false;
            if (x<0 && l<-x)sol = false;
            if (y>0 && u<y)sol = false;
            if (y<0 && d<-y)sol = false;

            cout << (sol?"YES":"NO") << endl;
      }

      return 0;
}

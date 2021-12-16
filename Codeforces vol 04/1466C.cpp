#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

bool valid(char ch)
{
      if (ch>='a' && ch<='z')return true;
      return false;
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){

            string s;
            cin >> s;
            ll n = s.size();

            ll cnt = 0;

            for (int i=0 ; i<n ; i++){
                  if (i+1<n && valid(s[i+1]) && s[i]==s[i+1]){
                        cnt++;
                        s[i+1]='*';
                  }
                  if (i>0 && i+1<n && valid(s[i-1]) && valid(s[i+1]) && s[i-1]==s[i+1]){
                        cnt++;
                        s[i+1]='#';
                  }
            }
            cout << cnt << "\n";
      }


      return 0;
}

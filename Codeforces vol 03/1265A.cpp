#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

char check1(char y)
{
      if (y == 'a')return 'b';
      else return 'a';
}

char check2(char x, char y)
{
      return 'a'+'b'+'c' - x - y;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s;
            cin >> s;
            ll n = s.size();
            s = s + '?';
            for (int i=0; i<n ; i++){
                  if (s[i]=='?'){

                        if (i==0){
                              if (s[1]=='?')s[0] = 'a';
                              else s[i] = check1(s[1]);
                        }
                        else if (i==n-1){
                              s[i] = check1(s[i-1]);
                        }
                        else {
                              if (s[i+1]=='?')s[i] = check1(s[i-1]);
                              else{
                                    if (s[i-1]==s[i+1])s[i] = check1(s[i-1]);
                                    else s[i] = check2(s[i+1],s[i-1]);
                              }
                        }
                  }
            }

            bool sol = true;

            for (int i=1 ; i<n ; i++){
                  if (s[i]==s[i-1])sol = false;
            }

            if (!sol)cout << -1 << endl;
            else {
                  for (int i=0 ; i<n ; i++)cout << s[i];
                  cout << endl;
            }
      }


      return 0;
}

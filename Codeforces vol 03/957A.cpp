#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n;

bool check(ll a)
{
      if (a>=0 && a<n)return true;
      else return false;
}

int main()
{
      cin >> n;
      string s;
      cin >> s;

      bool sol = true;

      for (int i=1 ; i<n ; i++){
            if (s[i]==s[i-1] && s[i]!='?')sol = false;
      }

      if (!sol)cout << "No" << endl;
      else {
            for (int i=0 ; i<n ; i++){
                  if (s[i]=='?' && (i==0 || i==n-1))sol = false;
                  else if (s[i]=='?'){
                        if (i>0 && i<n-1){
                              if (s[i-1]==s[i+1] || (s[i-1]=='?' || s[i+1]=='?'))sol = false;
                        }
                  }
            }

            if (!sol)cout << "Yes" << endl;
            else cout << "No" << endl;
      }


      return 0;
}

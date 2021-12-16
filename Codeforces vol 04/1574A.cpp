#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            string s;
            for (int i=0 ; i<2*n ; i++){
                  if (i%2)s.push_back(')');
                  else s.push_back('(');
            }
            cout << s << endl;
            for (int i=1 ; i<2*n-1 ; i+=2){
                  swap(s[i],s[i+1]);
                  cout << s << endl;
                  swap(s[i],s[i+1]);
            }
      }


      return 0;
}

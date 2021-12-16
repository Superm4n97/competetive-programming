#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            string s;
            cin >> s;

            sort(s.rbegin() , s.rend());

            if (s[0]=='0'){
                  cout << "red" << endl;
            }
            else {
                  ll n = s.size();

                  if (s[n-1]!='0')cout << "cyan" << endl;
                  else {
                        ll even=0 , zero = 0 , sum = 0;

                        for (int i=0 ; i<n-1 ; i++){
                              ll temp = s[i] - '0';

                              sum+=temp;
                              if (temp%2==0)even++;
                        }

                        if (even>0 && sum%3==0)cout << "red" << endl;
                        else cout << "cyan" << endl;
                  }
            }
      }


      return 0;
}

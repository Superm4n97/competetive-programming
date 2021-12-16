#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll n,mp[30] , ans = 0;

int main()
{
      cin >> n;

      while(n--){
            string s;
            cin >> s;

            ll id = s[0] - 'a';

            mp[id]++;
      }

      for (int i=0 ; i<26 ;i++){
            if (mp[i]>2){
                  ll temp = mp[i]/2;
                  if(mp[i]%2==0){
                         ll tut = temp*(temp-1);
                        ans+=tut;
                  }
                  else {
                        ll tut = temp*(temp-1)/2 , tut2 = temp*(temp+1)/2;
                        ans+=tut+tut2;
                  }
            }
      }
      cout << ans << endl;

      return 0;
}

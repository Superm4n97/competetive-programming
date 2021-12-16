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
            string s1,s2;
            cin >> s1 >> s2;

            ll ans = 0 , buffer = -1;

            for (int i=0 ; i<n ; i++){
                  if (s1[i]!=s2[i]){
                        ans+=2;
                        if (buffer==0)ans++;
                        buffer = -1;
                  }
                  else if (s1[i]=='0'){
                        if (buffer==1){
                              ans+=2;
                              buffer = -1;
                        }
                        else if (buffer==0){
                              ans++;
                        }
                        else buffer = 0;
                  }
                  else {
                        if (buffer==0){
                              ans+=2;
                              buffer = -1;
                        }
                        else buffer = 1;
                  }
            }
            if (buffer==0)ans++;

            cout << ans << endl;
      }

      return 0;
}

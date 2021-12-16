#include<bits/stdc++.h>

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      for (int _t=1 ; _t<=tc ; _t++){
            int n;
            cin >> n;

            int ans = 0;
            map <int,int> mp;

            for (int i=0 ; i<n ; i++){
                  int a;
                  cin >> a;
                  if(mp[a]==0){
                        ans+=(a+1);
                        mp[a] = a;
                  }
                  else mp[a]--;
            }
            cout << ans << "\n";
      }

      return 0;
}

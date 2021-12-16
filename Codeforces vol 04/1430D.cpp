#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){
            ll n;
            cin >> n;
            string s;
            cin >> s;

            ll alter[n+5] , same[n+5];
            memset(alter,0,sizeof alter);
            memset(same,0,sizeof same);

            alter[0] = 1;
            same[0] = 0;

            for (int i=1 ; i<n ; i++){
                  if (s[i]==s[i-1]){
                        alter[i] = alter[i-1];
                        same[i] = same[i-1]+1;
                        if (same[i]>alter[i])same[i] = alter[i];
                  }
                  else {
                        same[i] = same[i-1];
                        alter[i] = alter[i-1]+1;
                  }
            }

            cout << (alter[n-1]+same[n-1]+1)/2 << endl;
      }

      return 0;
}

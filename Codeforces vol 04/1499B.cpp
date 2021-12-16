#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);
      while(tc--){
            string s;
            cin >> s;
            bool temp = true;
            ll cnt = 0;
            for (int i=1 ; i<s.size() ; i++){
                  if (s[i]=='1' && s[i-1]=='1' && cnt == 0)cnt = 1;
                  if (s[i]=='0' && s[i-1]=='0' && cnt == 1)cnt = 2;
            }
            cout << (cnt==2?"NO":"YES") << endl;
      }

      return 0;
}

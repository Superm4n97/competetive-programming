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

            sort(s.begin(),s.end());
            cout << s << endl;
      }

      return 0;
}

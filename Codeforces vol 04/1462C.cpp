#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            if (n>=46){
                  cout << -1 << endl;
                  continue;
            }
            vector <ll> v;
            ll sum = 0;
            for (int i=9 ; i>0 ; i--){
                  if (n-i>=0){
                        v.push_back(i);
                        n-=i;
                  }
            }

            sort(v.begin(),v.end());

            for (int i=0 ; i<v.size() ; i++)cout << v[i];
            cout << endl;
      }

      return 0;
}

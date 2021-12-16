#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n, m;
      cin >> n >> m;
      string s;
      cin >> s;

      ll csum[n+5];
      memset(csum,0,sizeof csum);

      for (int i=0 ; i<n ; i++){
            csum[i+1] = 1 + (ll) s[i] - 'a';
            csum[i+1]+=csum[i];
//            show(csum[i+1]);
      }

      while(m--){
            ll a,b;
            cin >> a >> b;
            cout << csum[b]-csum[a-1] << endl;
      }


      return 0;
}

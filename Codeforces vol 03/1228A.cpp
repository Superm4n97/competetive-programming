#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

bool fun(ll a)
{
      ll mp[15];
      memset(mp,0,sizeof mp);

      while(a){
            ll dig = a%10;
            a/=10;
            mp[dig]++;
            if (mp[dig]>1)return false;
      }

      return true;
}

int main()
{
      ll l,r;
      cin >> l >> r;

      for (int i = l ; i<=r ; i++){
            if (fun(i)){
                  cout << i << endl;
                  return 0;
            }
      }

      cout << -1 << endl;

      return 0;
}

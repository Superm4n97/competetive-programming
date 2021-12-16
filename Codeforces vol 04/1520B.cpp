#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll len(ll n)
{
      ll ret = 0;
      while(n){
            ret++;
            n/=10;
      }
      return ret;
}
ll findMinDigit(ll n)
{
      ll ret = 10, lst , m = n;
      while(n){
            ll d = n%10;
            n/=10;
            lst = d;
      }

      ret = lst;

      for (int i=1 ; i<len(m) ; i++){
            lst = lst*10 + ret;
      }
//      show(lst);
      if (lst<=m)return ret;
      return ret-1;
}

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            ll n;
            cin >> n;
            ll sz = len(n), mn = findMinDigit(n), ans = 0;
            for (int i=1 ; i<sz ; i++){
                  ans+=9;
            }
            ans+=mn;
            cout << ans << endl;
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006
#define mod 1000000007

using namespace std;

ll n , q , pw[maxn] , csum[maxn];


int main()
{
      pw[0] = 1;
      for (int i=1 ; i<maxn-2 ; i++){
            pw[i] = pw[i-1]*2;
            pw[i]%=mod;
      }

      cin >> n >> q;
      string s;
      cin >> s;

      for (int i=0 ; i<n ; i++){
            csum[i+1] = s[i]-'0';
            csum[i+1]+=csum[i];
      }

      while(q--){
            ll l,r;
            cin >> l >> r;

            ll len = r-l+1 , one = csum[r]-csum[l-1];
            ll zero = len-one;

            ll temp = (pw[one]-1+mod)%mod;
            temp = temp*pw[zero];
            temp%=mod;

            cout << temp << endl;
      }



      return 0;
}

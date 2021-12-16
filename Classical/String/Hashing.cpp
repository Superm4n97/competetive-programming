#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "<< x << endl

using namespace std;

ll p_pw[1000006] , hash_value[1000006] , p = 139;
ll mod = 1000000009;

string ans;

void Hash(string s)
{
      ll m = ans.size() , n = s.size();

      ll hv = 0 , match = 0;

      for (ll i=1 ; i<=min(m,n) ; i++){
            hv = (hv+(s[i-1]*p_pw[i])%mod)%mod;

            ll temp1 = (hash_value[m] - hash_value[m-i] + mod)%mod;
            ll temp2 = (hv*p_pw[m-i])%mod;

            //show(temp1);
            //show(temp2);

            if (temp1==temp2)match = i;
      }

      //show(match);

      for (int i = match+1 ; i <= s.size() ; i++){
            ans+=s[i-1];
            m++;

            hash_value[m] = (hash_value[m-1]+(s[i-1]*p_pw[m])%mod)%mod;
      }
}

int main()
{
      p_pw[0] = 1;
      for (ll i=1 ; i<1000006 ; i++){
            p_pw[i] = p_pw[i-1]*p;
            p_pw[i] %= mod;
      }

      int n;
      cin >> n >> ans;

      for (int i=1 ; i<=ans.size() ; i++){
            hash_value[i] = (hash_value[i-1]+(ans[i-1]*p_pw[i])%mod)%mod;
      }

      for (int i=1 ; i<n; i++){
            string s;
            cin >> s;
            Hash(s);
      }

      cout << ans << endl;


      return 0;
}

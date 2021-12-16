#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      vector < ll > fac , v;

      for (int i=2 ; i<n ; i++){
            while(n%i==0){
                  fac.push_back(i);
                  n/=i;
            }
      }
      if (n>1)fac.push_back(n);

      map < ll ,ll > mp;

      ll mul = 0 , mx = 0;

      for (int i=0 ; i<fac.size() ; i++){
            mp[fac[i]]++;
            mx = max(mx,mp[fac[i]]);
      }

      ll ans = 0;

      for (ll pw = 1 , j = 0 ;; pw*=2, j++){
            if (pw==mx){
                  ans = j;
                  break;
            }
            if (pw>mx){
                  mx = pw;
                  ans = j;
                  break;
            }
      }


      ll temp = 1;

      for (int i=0 ; i<fac.size() ; i++){
            if (mp[fac[i]]<=mx && mp[fac[i]]>0){
                  if (mp[fac[i]]<mx)mul = 1;

                  temp*=fac[i];
                  mp[fac[i]] = 0;
            }
      }


      for (int i=0 ; i<v.size() ; i++)temp*=v[i];

      cout << temp << " " << ans+mul << endl;


      return 0;
}

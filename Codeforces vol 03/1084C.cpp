#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007

using namespace std;

int main()
{
      string s;
      cin>> s;

      ll cnt = 0;

      vector < ll > v;

      for (int i=0; i<s.size();i++){
            if(s[i]=='a')cnt++;
            if(s[i]=='b'){
                  if(cnt){
                        v.push_back(cnt);
                        cnt = 0;
                  }
            }
      }
      if(cnt)v.push_back(cnt);

      if (v.empty()){
            cout << "0" << endl;
            return 0;
      }

      ll ans = 1;

      for (int i=0; i<v.size();i++){
            ans*=(v[i]+1);
            ans%=mod;
      }

      ans = (ans+mod-1)%mod;

      cout << ans << endl;

      return 0;
}

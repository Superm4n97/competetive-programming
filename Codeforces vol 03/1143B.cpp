#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;

ll nines(ll n)
{
      if (n==0)return 0;
      ll temp = 1;

      for (int i=0 ; i<n ; i++)temp*=9;

      return temp;
}

ll rec(ll pos, ll choto)
{
      if (pos==s.size())return 1;

      ll a = s[pos] - '0';

      if (choto==1){
            return rec(pos+1,choto)*9;
      }
      else {
            if (a==0)return 0;
            else {
                  return max(rec(pos+1,0)*a , rec(pos+1,1)*(a-1));
            }
      }
}

int main()
{
      cin >> s;
      ll ans = nines(s.size()-1);
      ans = max(ans,rec(0,0));

      cout << ans << endl;


      return 0;
}

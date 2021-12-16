#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 2000000000000000018
using namespace std;

vector<string>dic;

string makeString(ll x)
{
      string s;
      while(x){
            ll temp = x%10;
            s.push_back(('0'+temp));
            x/=10;
      }
      reverse(s.begin(),s.end());
      return s;
}

void make()
{
      ll temp = 1;
      while(temp<inf){
//            show(temp);
            dic.push_back(makeString(temp));
            temp*=2LL;
      }
}
//s = pow of 2
ll compare(string s, string t)
{
      ll i = 0 , j = 0, match = 0;
      while(i<s.size() && j<t.size()){
            if (s[i]==t[j]){
                  match++;
                  i++,j++;
            }
            else {
                  j++;
            }
      }
      return s.size()+t.size()-2*match;
}

int main()
{
      make();
//      for (int i=0 ; i<dic.size() ; i++)cout << dic[i] << endl;

      ll tc;
      scanf("%lld",&tc);


      while(tc--){
            ll k, ans = inf;
            scanf("%lld",&k);
            string s = makeString(k);
            for (int i=0 ; i<dic.size() ; i++){
                  ans = min(ans,compare(dic[i],s));
            }
            printf("%lld\n",ans);
      }

      return 0;
}


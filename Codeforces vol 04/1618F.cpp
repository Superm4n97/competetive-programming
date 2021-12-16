#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;


string createString(ll a)
{
      string ret;
      while(a){
            if (a%2)ret.push_back('1');
            else ret.push_back('0');
            a/=2;
      }
      reverse(ret.begin(),ret.end());

      return ret;
}

string normal(string s)
{
      string ret;
      bool st = false;
      for (int i=s.size()-1 ; i>=0 ; i--){
            if (s[i]=='0' && st == false)continue;
            else {
                  st = true;
                  ret.push_back(s[i]);
            }
      }
      reverse(ret.begin(),ret.end());
      return ret;
}

string rev(string s)
{
      reverse(s.begin(),s.end());
      return s;
}

bool isMatching(string a, string b)
{
      ll n = a.size() , m = b.size();
      for (int i=0 ; i<m ; i++){
            if (i+n > m || b[i]=='0')break;

            bool matched = true;
            for (int j=0 ; j<n; j++){
                  if (a[j] != b[i+j]){
                        matched = false;
                        break;
                  }
            }

            if (matched){
                  for (int j=i+n ; j<m ; j++){
                        if (b[j]=='0'){
                              matched = false;
                              break;
                        }
                  }
                  if (matched)return true;
            }
      }
      return false;
}

int main()
{
      string x,y;
      ll a,b;
      cin >> a >> b;

      if (a==b){
            cout << "YES" << endl;
            return 0;
      }

      x = createString(a);
      y = createString(b);

      vector<string>v;

      string cpy1 = x , cpy2 = x;
      cpy1 = normal(cpy1);
      cpy2.push_back('1');

      v.push_back(cpy1);
      v.push_back(rev(cpy1));
      v.push_back(cpy2);
      v.push_back(rev(cpy2));

      bool ans = false;;

//      show(y);
      for (int i=0 ; i<4 ; i++){
//            show(v[i]);
            ans = (ans|isMatching(v[i],y));
//            show(ans);
      }

      cout << (ans?"YES":"NO") << endl;

      return 0;
}

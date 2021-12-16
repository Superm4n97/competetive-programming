#include<bits/stdc++.h>
#define ll long long int
#define maxn 2000006
#define inf 1000000000012
#define show(x) cout << #x << " : " << x << endl
#define mod 998244353

using namespace std;

map<string,string> pre,suf;
map<string,ll> com_inside;

ll assignment(string a, string b)
{
//      mp[a] = b;
      string pfx,sfx;
      ll sz = b.size() , cnt = 0;
      for (int i=0 ; i<3 && i<b.size() ; i++)pfx.push_back(b[i]);
      for (int i=0 ; i<3 && i<b.size() ; i++)sfx.push_back(b[sz-1-i]);
      for (int i=3 ; i<sz ; i++){
            if (b[i]=='a' && b[i-1]=='h' && b[i-2]=='a' && b[i-3]=='h')cnt++;
      }
      pre[a] = pfx;
      reverse(sfx.begin(),sfx.end());
      suf[a] = sfx;
//      show(suf[a]);
      com_inside[a] = cnt;
      return com_inside[a];
}

ll findSuffPreff(string s, string p)
{
      ll sz_s = s.size() , sz_p = p.size() , cnt = 0;
      if (sz_s>=1 && sz_p>=3 && s[sz_s-1]=='h' && p[0]=='a' && p[1]=='h' && p[2]=='a')cnt++;
      if (sz_s>=2 && sz_p>=2 && s[sz_s-2]=='h' && s[sz_s-1]=='a' && p[0]=='h' && p[1]=='a')cnt++;
      if (sz_s>=3 && sz_p>=1 && s[sz_s-3]=='h' && s[sz_s-2]=='a' && s[sz_s-1]=='h' && p[0]=='a')cnt++;
      return cnt;
}

ll addition(string c, string a, string b)
{
      com_inside[c] = com_inside[a]+com_inside[b];
      com_inside[c]+=findSuffPreff(suf[a],pre[b]);

      string pf = pre[a] , pf2 = pre[b];
      string new_pre = pf;
      ll id = 0;
      while(new_pre.size()<3 && id<pf2.size()){
            new_pre.push_back(pf2[id]);
            id++;
      }

      string sf = suf[b] , sf2 = suf[a];
      string new_suf = sf;
      id = 0;
      while(new_suf.size()<3 && id<sf2.size()){
            new_suf = sf2[(sf2.size()-1-id)] + new_suf;
//            new_suf.push_back(sf2[(sf2.size()-1-id)]);
            id++;
      }
      pre[c] = new_pre;
      suf[c] = new_suf;

//      show(com_inside[c]);
//      show(pre[c]);
//      show(suf[c]);

      return com_inside[c];
}

ll dist(string s)
{
      s.push_back(' ');

      string _new;
      vector<string>v;
      for (int i=0 ; i<s.size() ; i++){
            if (s[i]==' '){
                  v.push_back(_new);
                  _new.clear();
            }
            else _new.push_back(s[i]);
      }
      if (v.size()<=4)return assignment(v[0],v[2]);
      else return addition(v[0],v[2],v[4]);
}

void clean()
{
      pre.clear();
      suf.clear();
      com_inside.clear();
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){
            clean();
            ll n , x;
            cin >> n;

            getchar();
            for (int i=0 ; i<n ; i++){
                  string s;
                  getline(cin,s);
                  x = dist(s);
            }
            cout << x << endl;
      }

      return 0;
}

/*
1
6
a := h
b := a
a = a + b
b = a + a
b = b + b
b = b + b
//hahahahahahahaha

1
1
a := abcdef
*/

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << endl

using namespace std;

ll n;
string s,t;

vector <ll> G[5] ;
vector < string > v;

void fun()
{
      v.push_back("abc");
      v.push_back("acb");
      v.push_back("bac");
      v.push_back("bca");
      v.push_back("cab");
      v.push_back("cba");
}

char two(char ch)
{
      if (ch=='a')return 'b';
      if (ch=='b')return 'a';
      if (ch=='c')return 'a';
}
char three(char ch1 , char ch2)
{
      return 'a'+'b'+'c' - ch1-ch2;
}

string solve()
{
      for (int i=0 ; i<6 ; i++){
            string st = v[i];
            if (st[0]==s[0] && st[1]==s[1])continue;
            if (st[0]==t[0] && st[1]==t[1])continue;

            if (st[1]==s[0] && st[2]==s[1])continue;
            if (st[1]==t[0] && st[2]==t[1])continue;

            if (st[2]==s[0] && st[0]==s[1])continue;
            if (st[2]==t[0] && st[0]==t[1])continue;

            return st;
      }
}

int main()
{
      cin >> n;
      cin >> s >> t;

      fun();

      cout << "YES" << endl;

      if (s[0]==s[1] || t[0]==t[1]){
            string st = solve();
            for (int i=0 ; i<n ; i++)cout << st;
            cout << endl;
      }
      else if (s[0]==t[0]){
            //show("2");
            char c1 = two(s[0]);
            for (int i=0 ; i<n ; i++)cout << c1;

            char c2 = three(s[0],c1);
            for (int i=0 ; i<n ; i++)cout << c2 ;
            for (int i=0 ; i<n ; i++)cout << s[0];
            cout << endl;
      }
      else if(s[0]==t[1] && s[1]==t[0]){
            char c1 = two(s[0]);
            for (int i=0 ; i<n ; i++)cout << s[0];

            char c2 = three(s[0],s[1]);
            for (int i=0 ; i<n ; i++)cout << c2 ;
            for (int i=0 ; i<n ; i++)cout << s[1];
            cout << endl;
      }

      else if(s[1]==t[1]){
            for (int i=0 ; i<n ; i++)cout << s[1];
            char c1 = two(s[1]);
            for (int i=0 ; i<n ; i++)cout << c1;

            char c2 = three(s[1],c1);
            for (int i=0 ; i<n ; i++)cout << c2 ;
            cout << endl;
      }

      else {

            //show("3");

            string st = solve();

            for (int i=0 ; i<n ; i++)cout << st;
            cout << endl;
      }



      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

map < string , string > mp;
string s1,s2;

int main()
{
      cin >> s1 >> s2;
      ll n;
      cin >> n;

      cout << s1 << " " << s2 << endl;

      for (int i=0 ; i<n ; i++){
            string s,t;
            cin >> s >> t;
            //mp[s] = t;

            if (s1==s)s1 = t;
            if (s2==s)s2 = t;

            cout << s1 << " " << s2 << endl;
      }


      /*while(true)
      {
            string s = mp[s1];
            if (s.empty())break;

            s1 = s;
            cout << s1 << " " << s2 << endl;
      }
      while(true){

            string s = mp[s2];
            if (s.empty())break;

            s2 = s;
            cout << s1 << " " << s2 << endl;
      }*/


      return 0;
}

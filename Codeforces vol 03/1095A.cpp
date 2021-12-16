#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      string s,t;
      ll n;
      cin >> n;
      cin >> s;

      ll id = 0;

      for (int i = 0 ;; i++){
            id+=i;
            if (id>=s.size())break;

            t.push_back(s[id]);
      }

      cout << t << endl;


      return 0;
}

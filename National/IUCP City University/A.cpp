#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)

using namespace std;

int main()
{
      string s;
      cin  >> s;
      set <char> st;

      for (int i=0 ; i<s.size() ; i++)st.insert(s[i]);

      if (st.size()==s.size())cout << "YES\n";
      else cout << "NO\n";

      return 0;
}

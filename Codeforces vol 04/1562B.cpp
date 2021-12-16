#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string s;
ll n;

bool findOne()
{
      for (int i=0 ; i<s.size(); i++){
            if (s[i]=='1' || s[i]=='4' || s[i]=='6' || s[i]=='8' || s[i]=='9'){
                  cout << 1 << endl << s[i] << endl;
                  return true;
            }
      }
      return false;
}

void findTwo()
{
      for (int i=1 ; i<s.size() ; i++){
            if (s[i]=='5' || s[i]=='2'){
                  cout << 2<< endl << s[i-1] << s[i] << endl;
                  return;
            }
      }

      ll cnt[13];
      memset(cnt,0,sizeof cnt);

      for (int i=0 ; i<s.size() ; i++){
            ll temp = s[i] - '0';
            cnt[temp]++;

            if (cnt[temp]==2){
                  cout << 2 << endl << temp << temp << endl;
                  return;
            }
      }

      if (s[0]=='2')cout << 2 << endl << 27 << endl;
      else cout << 2 << endl << 57 << endl;

      return;
}

int main()
{
      ll tc;
      cin >> tc;
      while(tc--){
            cin >> n;
            cin >> s;
            if (!findOne())findTwo();
      }

      return 0;
}
/*
if n has digits,
1 4 6 8 9 delete all except that number
2 5 not in the first or a digit has double occurrence
3 7

237 - 27
273 - 27
537 - 57
573 - 57

 101
 101
----
  101
00000
10100
------
11001

*/

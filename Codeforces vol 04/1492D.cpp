#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int a,b,k;
string s,t;

int main()
{
      cin >> a >> b >> k;
      for (int i=0;i<b;i++)s.push_back('1');
      for (int i=0;i<a;i++)s.push_back('0');

      t = s;

      if (a==0 || b==1 || k==0){
            if (k==0)cout << "Yes\n" << s << "\n" << t << "\n";
            else cout << "No\n";
      }
      else {
            swap(s[a+b-1],s[2]);
            swap(t[a+b-1],t[2]);
            swap(t[1],t[2]);
//            swap(s[1],s[2]);
            k--;

//      show(s);
//      show(t);

            int i = 2;
            while(k && i<a+b-1){
                  swap(s[i],s[i+1]);
                  swap(t[i],t[i+1]);
                  k--,i++;
            }
            if (k)cout << "No\n";
            else cout << "Yes\n" << s << "\n" << t << "\n";
      }

      return 0;
}

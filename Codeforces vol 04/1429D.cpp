#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int a,b,k;
string s,t;

int main()
{
      cin >> a >> b >> k;

      for (int i=0 ; i<b ; i++)s.push_back('1');
      for (int i=0 ; i<a ; i++)s.push_back('0');
      t = s;

      if (a==0 || b==1){
            if (k==0){
                  cout << "Yes\n";
                  cout << s << "\n" << t<< "\n";
            }
            else cout << "No\n";
      }
      else {
            int i = b;
            while(k && i<a+b){
                  swap(t[i],t[i-1]);
                  i++;
                  k--;
            }

            if (k)cout << "No\n";
            else {
                  cout << "Yes\n";
                  cout << s << "\n"<< t << "\n";
            }
      }

      return 0;
}

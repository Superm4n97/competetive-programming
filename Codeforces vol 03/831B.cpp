#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

string t1,t2,s;

int main()
{
      cin >> t1;
      cin >> t2;
      cin >> s;

      for (int i=0 ; i<s.size() ; i++){

            char temp = s[i];
            if (s[i]>='A' && s[i]<='Z')temp+=32;

            if (temp>='a' && temp<='z'){
                  ll id ;
                  for (int i=0 ; i<26 ; i++){
                        if (t1[i]==temp){

                              id = i;
                              break;
                        }
                  }

                  char tut = t2[id];
                  if (temp!=s[i])tut-=32;

                  cout << tut;
            }
            else {
                  cout << s[i];
            }
      }

      cout << endl;


      return 0;
}

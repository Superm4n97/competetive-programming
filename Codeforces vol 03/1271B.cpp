#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n;
      cin >> n;

      string s;
      cin >> s;

      vector < ll > ans;
      ll b = 0 , w = 0;

      for (int i=0 ; i<n; i++){
            if (s[i]=='B')b++;
            else w++;
      }

      if (b%2 && w%2){
            cout << -1 << endl;
      }
      else {
            if (b%2==0){
                  for (int i=0 ; i<n ; i++){
                        if (s[i]=='B' && s[i+1]=='B'){
                              ans.push_back(i);
                              s[i] = 'W';
                              s[i+1] = 'W';
                        }
                        if (s[i]=='B'){
                              ans.push_back(i);
                              swap(s[i],s[i+1]);
                        }
                  }
            }
            else {
                  for (int i=n-1 ; i>=0 ; i--){
                        if (s[i]=='W'){
                              if (s[i-1]=='W'){
                                    ans.push_back(i-1);
                                    s[i]='B';
                                    s[i-1] = 'B';
                              }
                              else {
                                    ans.push_back(i-1);
                                    swap(s[i],s[i-1]);
                              }
                        }
                  }
            }


                 cout << ans.size() << endl;
                 for (int i=0 ; i<ans.size() ; i++){
                        cout << ans[i]+1 << " ";
                 }
                 cout << endl;
      }


      return 0;
}

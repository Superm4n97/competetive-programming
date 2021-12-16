#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s;
            cin >> s;
            ll n = s.size();
            vector < ll > v , ans;

            for (int i=0 ; i<n-2 ; i++){

                  if (s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')v.push_back(i+1);
                  if (s[i]=='t' && s[i+1]=='w' && s[i+2]=='o')v.push_back(i+1);
            }

            v.push_back(100000000007);
            for (int i=0 ; i<v.size()-1 ; i++){
                  if (v[i+1]-v[i]==2){
                        ans.push_back(v[i]+2);
                        i++;
                  }
                  else{
                        ans.push_back(v[i]+1);
                  }
            }

            cout << ans.size() << endl;
            for (int i=0;i<ans.size() ; i++)cout << ans[i] << " ";
            cout << endl;
      }


      return 0;
}

#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            string s,s2;
            cin >> s >> s2;

            ll n = s.size();

            ll A[n+5], id = n-1;
            A[n-1] = n-1;

            char mx = s[n-1];

            for (int i = n-2 ; i>=0 ; i--){
                  if (s[i]>mx){
                        A[i] = id;
                  }
                  else if (s[i]<mx){
                        mx = s[i];
                        A[i] = i;
                        id = i;
                  }
                  else {
                        A[i] = i;
                  }
            }
            for (int i=0 ; i<n-1 ; i++){
                  if (A[i]!=i){
                        swap(s[i],s[A[i]]);
                        break;
                  }
            }

            //cout << s << endl;

            if (s<s2)cout << s << endl;
            else cout << "---" << endl;
      }

      return 0;
}

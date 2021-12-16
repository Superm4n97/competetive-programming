#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

void Z_function(string s , ll Z[])
{
      //takes a string s & saves z value in Z[]
      //aba$ababaaaabbc Z[] = 001030301112000
      ll N = s.size();
      Z[0] = 0;

      for (int i=1, L = 0 , R = 0 ; i<N ; i++){
            if (i>R){
                  L = R = i;
                  while(R<N && s[R]==s[R-L])R++;
                  R--;
                  Z[i] = R-L+1;
            }
            else {
                  if (i+Z[i-L]-1 < R)Z[i] = Z[i-L];
                  else {
                        L = i;
                        while(R<N && s[R]==s[R-L])R++;
                        R--;
                        Z[i] = R-L+1;
                  }
            }
      }
}

int main()
{
      ll Z[65];

      Z_function("aba$ababaaaabbc",Z);


      vector <ll> v;
      vector<pair<ll,ll> > ans;

      cout << "aba$ababaaaabbc" << endl;
      for (int i=0 ; i<15 ; i++){
            cout << Z[i] ;
      }

      return 0;
}

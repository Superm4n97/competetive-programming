#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      scanf("%d",&tc);

      while(tc--){

            ll n;
            cin >> n;

            if (n<5){
                  if (n==3)cout << "1 0 0" << endl;
                  else cout << "-1" << endl;
            }
            else {
                  ll t = 0 , s = 0 , f = 0;
                  while(n>7){
                        n-=3;
                        t++;
                  }

                  if (n==5){
                        f++;
                        n = 0;
                  }
                  if (n==7){
                        s++;
                        n=0;
                  }
                  while(n){
                        t++;
                        n-=3;
                  }

                  cout << t << " " << f<<  " " << s << endl;
            }
      }

      return 0;
}

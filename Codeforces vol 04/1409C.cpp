#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            ll n,x,y;
            cin >> n >> x >> y;

            ll diff = y-x;

                  //show(diff);

            for (int interval = 1 ; interval<=50 ; interval++){
                  if (diff%interval == 0 && (diff/interval)+1 <= n){

                        //show(interval);

                        ll prints = n;

                        for (int i=y ; i>0 ; i-=interval){
                              cout << i << " ";
                              prints--;

                              if (prints==0)break;
                        }

                        while(prints--){

                              y+=interval;
                              cout << y << " ";
                        }

                        cout << "\n";

                        break;
                  }
            }
      }

      return 0;
}
/**

**/

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int main()
{
      int tc;
      cin >> tc;
      while(tc--){
            ll a,b;
            cin >> a >> b;

            if (a%b==0)cout << "NO" << endl;
            else {
                  cout << "YES" << endl;
                  cout << a*b << " ";
                  for (int i=0 ; i<24 ; i++){
                        if (b%prime[i]!=0){
                              cout << a*prime[i] << " " << a*prime[i]*prime[i] << endl;
                              break;
                        }
                  }
            }
      }

      return 0;
}

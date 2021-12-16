#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

int main()
{
      ll tc;
      scl(tc);
      while(tc--){

            ll w,h,n;
            cin >> w >> h >> n;
            ll temp = 1;
            while(w%2==0){
                  w/=2;
                  temp*=2;
            }
            while(h%2==0){
                  h/=2;
                  temp*=2;
            }

            if (temp>=n)cout << "YES" << endl;
            else cout << "NO" << endl;
      }

      return 0;
}

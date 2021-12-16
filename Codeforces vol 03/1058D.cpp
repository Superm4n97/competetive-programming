#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll ans;

bool solve(ll m, ll k)
{
      ll b = 1 , e = m;

      while(b<=e){

            ll mid = (b+e)/2;

            if (k*mid==2*m){
                  ans = mid;
                  return true;
            }

            if (k*mid>2*m)e = mid-1;
            else b = mid+1;
      }

      return false;
}

int main()
{
      ll n,m,k;
      cin >> n >> m >> k;

      if (solve(m,k)){
            cout << "YES" << endl;
            cout << "0 0" << endl;
            cout << n << " 0" << endl;
            cout << n << " "<< ans << endl;
      }
      else if (solve(n,k)){
            cout << "YES" << endl;
            cout << "0 0" << endl;
            cout << "0 " << m << endl;
            cout << ans<< " " << m << endl;
      }
      else cout << "NO" << endl;


      return 0;
}


/**

.5*h*w = m*n/k
h*w*k = 2*n*m;


**/

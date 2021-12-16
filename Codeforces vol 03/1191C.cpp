#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n,m,k;
      cin >> n >> m >> k;

      queue < ll > q;
      for (int i=0 ; i<m ; i++){
            ll a;
            cin >> a;

            q.push(a);
      }

      ll lim = k , ans = 0;

      while(!q.empty())
      {
            ll cnt = 0;
            while(q.front() <= lim){
                  cnt++;
                  q.pop();

                  if (q.empty())break;
            }

            if (cnt){
                  ans++;
                  lim+=cnt;
            }
            else if (!q.empty()){

                  ll temp = (q.front() - lim + (k-1)) / k;
                  lim += temp*k;
            }
      }

      cout << ans << endl;

}

/**
10 - 5 = 5+(k-1) / k = temp
6 - 5 = 1+(k-1) / k = temp

temp = (q.front() - lim + (k-1)) / k
lim+=temp*k

temp = 2;
lim = 5+2*5

3 5 7 8 - 3
3 5 6 7 - 2
**/

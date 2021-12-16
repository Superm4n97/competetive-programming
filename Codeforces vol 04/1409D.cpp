#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf             1000000000000000018

using namespace std;

ll sum[20] , A[20] , n , m;

ll convert(string s)
{
      ll ret = 0;
      for (int i=0;i<s.size() ; i++){
            A[i+1] = s[i]-'0';

            sum[i+1] = sum[i] + A[i+1];
            ret+=A[i+1];
      }

      return ret;
}

ll calculateRem(ll x)
{
      if (x>n)return 0;

      ll ret = 0 , off = 0 , pre = 1;
      for (int i=n ; i>=x ; i--){

            ll temp = A[i];
            if (off){

                  temp++;
                  off = 0;
            }

            if (temp>0){
                  ret += (10 - temp) * pre;
                  off = 1;
            }

            pre*=10;
      }

      return ret;
}

ll solve()
{
      ll ret = inf;

      for (int i=1 ; i<=n ; i++){

            if (A[i]<9){

                  ll temp = sum[i-1] + A[i]+1;
                  ll moves = calculateRem(i+1);

                  if (temp<=m)ret = min(ret,moves);
            }
      }

      return ret;
}

int main()
{
      int tc;
      cin >> tc;
      while(tc--){

            string s;
            cin >> s >> m;
            n = s.size();

            ll initialSum = convert(s);

            //show(initialSum);

            if (initialSum<=m){
                  cout <<0 << endl;
                  continue;
            }


            ll ans1 = calculateRem(1) , ans2 = solve();

            //show(calculateRem(3));
            //show(ans1);

            cout << min(ans1,ans2) << endl;
      }

      return 0;
}
/**

**/

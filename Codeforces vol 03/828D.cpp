#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      ll n, k;
      cin >> n >> k;

      ll rem = n-k-1;
      ll dis = (rem) / k;
      ll extra = rem%k;

      vector < pair < ll,ll > > ans;

      //show(dis);
      //show(extra);

      ll cnt = 2 + dis*2;
      if (extra==1)cnt++;
      else if (extra>1)cnt+=2;

      if (k==n-1){
            for (int i=2 ; i<=n ; i++){
                  ans.push_back({1,i});
            }
      }
      else {
            ll pre = k+2;

            for (int i=2 ; i<=k+1 ; i++){
                  ll temp = pre , element = dis;
                  if (extra){
                        element++;
                        extra--;
                  }

                  ll lastNode = i;

                  for (int j = pre ; j<pre+element ; j++){
                        ans.push_back({lastNode,j});
                        lastNode = j;
                  }
                  ans.push_back({lastNode,1});

                  pre = pre+element;
            }
      }

      cout << cnt << endl;
      for (int i=0 ; i<ans.size() ; i++){
            cout << ans[i].first << " " << ans[i].second << endl;
      }


      return 0;
}
/**

8 3
8 - 4 = 4;
4+(3-1) / 3 = 2

5-8

**/

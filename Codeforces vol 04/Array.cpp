#include<bits/stdc++.h>

using namespace std;

int dp[1000][1000] , A[1000], n, k;

int rec(int index, int cur_space)
{

}

int main()
{
      cout << "Numbers of items n: ";
      cin >> n;

      cout << "Weights: ";

      vector<int> v;
      int ans = 0 , sum = 0;

      for (int i=1 ; i<=n ; i++){
            cin >> A[i];
            v.push_back(A[i]);
            sum+=A[i];
      }

      cout << "Bin capacity c: ";
      cin >> k;

      sort(v.rbegin(),v.rend());

      while(sum){
            ans++;
            int cur = 0;
            for (int i=0 ; i<n ; i++){
                  if (v[i]+cur <= k){
                        cur+=v[i];
                        sum-=v[i];
                        v[i] = 0;
                  }
            }
      }
      printf("We need %d bin to accommodate all items.\n",ans);


      return 0;
}

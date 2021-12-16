#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : "  << x << endl
#define maxn 1000006
#define log _log

using namespace std;

ll n, A[maxn] , cnt[maxn] , mp[maxn] , log = 0;
vector < ll > ans;
bool solution = true;

int main()
{
      cin >> n;

      for (int i=1 ; i<=n;i++){

            cin >> A[i];

            if (A[i] > 0){

                  log++;
                  mp[A[i]]++;
                  if (mp[A[i]]>1)solution = false;

                  if (cnt[A[i]]<ans.size())cnt[A[i]] = ans.size();

                  if (cnt[A[i]]>ans.size())solution = false;
                  else {
                        cnt[A[i]]++;
                  }
            }
            else {
                  A[i]*=-1;
                  if (mp[A[i]] != 1)solution = false;
                  else {
                        log--;
                        mp[A[i]]--;

                        //show(log);

                        if (log==0){
                              ans.push_back(i);
                        }
                  }
            }


      }

      if (log>0)solution = false;

      if (!solution)cout << -1 << endl;
      else {
            //show(ans.size());
            cout << ans.size() << endl;
            cout << ans[0] << " ";

            for (int i=1 ;i<ans.size() ;i++){
                  cout << ans[i]-ans[i-1] << " ";
            }
            cout << endl;
      }

      return 0;
}

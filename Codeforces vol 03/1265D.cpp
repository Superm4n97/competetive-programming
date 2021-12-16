#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

vector < ll > ans[6];

void solve(ll x , vector < ll > cnt , ll id)
{
      if (cnt[x]==0)return;

      cnt[x]--;
      ans[id].push_back(x);

      while(true){

            if (x==0){
                  if (cnt[x+1]){
                        x++;
                        cnt[x]--;
                        ans[id].push_back(x);
                  }
                  else {
                        break;
                  }
            }
            else if (x==3){
                  if (cnt[x-1]){
                        x--;
                        cnt[x]--;
                        ans[id].push_back(x);
                  }
                  else break;
            }
            else {
                  if (cnt[x-1]==0 && cnt[x+1]==0)break;
                  if (cnt[x-1]==0){
                        x++;
                        cnt[x]--;
                        ans[id].push_back(x);
                  }
                  else if (cnt[x+1]==0){
                        x--;
                        cnt[x]--;
                        ans[id].push_back(x);
                  }
                  else {
                        x--;
                        cnt[x]--;
                        ans[id].push_back(x);
                  }
            }
      }
}

int main()
{
      vector < ll > cnt(6);
      cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];

      ll n = cnt[0]+cnt[1]+cnt[2]+cnt[3];

      solve(0,cnt,0);
      solve(1,cnt,1);
      solve(2,cnt,2);
      solve(3,cnt,3);

      if (ans[0].size()==n){
            cout << "YES" << endl;
            for (int i=0 ; i<n ; i++)cout << ans[0][i] << " ";
            cout << endl;
      }
      else if (ans[1].size()==n){
            cout << "YES" << endl;
            for (int i=0 ; i<n ; i++)cout << ans[1][i] << " ";
            cout << endl;
      }
      else if (ans[2].size()==n){
            cout << "YES" << endl;
            for (int i=0 ; i<n ; i++)cout << ans[2][i] << " ";
            cout << endl;
      }
      else if(ans[3].size()==n){
            cout << "YES" << endl;
            for (int i=0 ; i<n ; i++)cout << ans[3][i] << " ";
            cout << endl;
      }
      else {
            cout << "NO" << endl;
      }


      return 0;
}


#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            ll n;
            cin >> n;

            ll A[n+5], fre[n+5];
            memset(fre,0,sizeof fre);
            for (int i=0;i<n; i++){
                  cin >> A[i];
                  fre[A[i]]++;
            }

            ll mex = 0;
            vector<ll> ans;
            queue<ll>fix;
            priority_queue<ll> pq;

            for (int i=0 ; i<n ; i++){
                  if (A[i]!=i)fix.push(i);
            }

            for (ll i=n ; i>=0 ;i--){
                  if (fre[i]==0){
                        pq.push(-i);
                  }
            }

            while(!fix.empty()){
                  if (A[fix.front()] == fix.front()){
                        fix.pop();
                        continue;
                  }

                  ll unfixID = fix.front();

//                  show(pq.size());
//                  show(unfixID);
//                  show(-pq.top());
//                  show(n);

                  if (-pq.top()==n){
                        pq.pop();
                        ll x = A[unfixID];
                        A[unfixID] = n;
                        fre[n]++;
                        ans.push_back(unfixID);
//                        show(x);
                        fre[x]--;
                        pq.push(-x);
                  }
                  else {
                        ll mex = -pq.top();
                        pq.pop();

//                        show(mex);

                        ll x = A[mex];
//                        show(x);
                        fre[x]--;
//                        show(fre[x]);
                        if (fre[x]==0){
                              pq.push(-x);
                        }
                        A[mex] = mex;
                        fre[mex]++;
                        ans.push_back(mex);
                  }
            }

            cout << ans.size() << endl;
            for (int i=0 ; i<ans.size() ; i++)cout << ans[i]+1 << " ";
            cout << endl;
      }

      return 0;
}

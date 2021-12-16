#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll n, finish[maxn] , A[maxn];
priority_queue < pair < ll , ll > > stock;
stack < ll > st;
vector < pair < ll,ll > > ans;
bool sol = true;

int main()
{
      cin >> n;

      ll id = 1;

      for (ll i=1 ; i<=n ; i++)st.push(i);

      for (ll i=1 ; i<=n*2 ; i++){

            char ch;
            cin >> ch;

            if (ch=='+'){
                  while(!st.empty()){

                        ll a = st.top();
                        st.pop();
                        if(finish[a] != 0)continue;

                        finish[a] = 1;
                        stock.push({-a,i});
                        id++;
                        break;
                  }
            }
            else {
                  ll a;
                  cin >> a;

                  if (stock.empty()){
                        sol = false;
                        //break;
                        continue;
                  }

                  if (-stock.top().first<a){
                        sol = false;
                        continue;
                        //break;
                  }

                  if (-stock.top().first==a){
                        finish[a] = 2;
                        ans.push_back({-stock.top().first,stock.top().second});
                        stock.pop();
                  }
                  else {
                        ll x = -stock.top().first , y = stock.top().second;
                        stock.pop();

                        ans.push_back({a,y});
                        finish[a] = 2;
                        st.push(x);
                        finish[x] = 0;
                  }
            }
      }

      if (!sol){
            cout << "NO\n" ;
            return 0;
      }

      memset(A,-1,sizeof A);
      for (int i=0 ; i<ans.size() ; i++){
            A[ans[i].second] = ans[i].first;
      }

      for (int i=1 ; i<=2*n ; i++){
//            show(i);
//            show(A[i]);
//            cout << endl;
            if (A[i]>-1 && A[i-1]>-1 && A[i]>A[i-1]){
                  sol = false;
//                  show("there");
            }
      }

      if (!sol){
            cout << "NO\n";
            return 0;
      }

      cout << "YES" << "\n";
      for (int i=1 ; i<=2*n ; i++)
            if (A[i]!=-1)cout << A[i] << " ";
      cout << "\n";

      return 0;
}

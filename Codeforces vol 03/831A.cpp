#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1005


using namespace std;

ll A[maxn] , mx = -1;

int main()
{
      ll n;
      cin >> n;

      for (int i=1; i<=n ; i++){
            cin >> A[i];
            mx = max(mx,A[i]);
      }

      if (n<=2){
            cout << "YES" << endl;
            return 0;
      }

      ll rgt = 0;
      bool sol = true;

      for (int i=n-1 ;i>=1 ; i--){

            if (rgt==1 && A[i]>A[i+1])sol = false;
            if (A[i]<A[i+1])rgt = 1;
      }

      if (!sol){
            cout << "NO" << endl;
            return 0;
      }

      set < ll > st;
      ll val;

      for (int i=2 ; i<=n ;i++){
            if (A[i]==A[i-1]){
                  st.insert(A[i]);
                  val = A[i];
            }
      }

      if (st.empty())cout << "YES" << endl;
      else if (st.size()==1 && val==mx)cout << "YES" << endl;
      else cout << "NO" << endl;

      return 0;
}

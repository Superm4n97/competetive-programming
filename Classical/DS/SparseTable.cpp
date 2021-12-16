#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 1000006

using namespace std;

/*buildPrePower() is called only once, it helps to make the in O(1).
find max/min value in a range. build O(n long n) , query O(1)
call buildPrePower() then build array A[] and then call buildSPtable()*/
ll SP[maxn][25] , PrePower[maxn] , A[maxn] , N , BIT, pw[30];
void buildPrePower()
{
      ll temp = 1;
      for (int i=0 ; i<=19 ; i++){
            if (temp<maxn)PrePower[temp] = i;
            temp *=2;
      }
      for (int i=3 ; i<maxn ; i++){
            if (PrePower[i]==0)PrePower[i] = PrePower[i-1];
      }
}
void BuildSpTable()
{
      BIT = PrePower[N]+1;
      ///initialize SP
      for (int j= 0 ; j<=BIT ; j++){
            for (int i=0 ; i<=N ; i++)SP[i][j] = -1;
      }
      for (int i=1; i<=N ; i++)SP[i][0] = A[i];
      for (int j = 1 ; j<=BIT ; j++){
            for (int i=1 ; i<=N ; i++){
                  SP[i][j] = max(SP[i][j-1],SP[max(0LL,i-pw[j-1])][j-1]);//for max sparse table
                  //SP[i][j] = min(SP[i][j-1],SP[max(0LL,i-pw[j-1])][j-1]);//for min sparse table
            }
      }
}
ll QuarySP(ll l, ll r)
{
      ll id1 = r, findbit = PrePower[(r-l+1)] ;
      ll id2 = l + (1<<findbit)-1;
      return max(SP[id1][findbit],SP[id2][findbit]);//for max sparse table
      //return min(SP[id1][findbit],SP[id2][findbit]);//for min sparse table
}

int main()
{
      buildPrePower();//called only once
      cin >> N;
      for (int i=1 ; i<=N; i++)cin >> A[i];

      BuildSpTable();

      cout << "Quary: " << endl;
      while(true){
            ll a, b;
            cin >> a >> b;
            cout << QuarySP(a,b) << endl;
      }

      return 0;
}

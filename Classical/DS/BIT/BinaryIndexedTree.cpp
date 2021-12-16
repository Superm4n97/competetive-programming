
#include<bits/stdc++.h>
#define ll long long int
#define maxn 400005
#define show(x) cout << #x << " : " << x << endl

using namespace std;

/**Prefix sum build O(NlogN) , query O(logN) , add O(logN)**/
ll N,A[maxn] , BIT[maxn];
void AddElement(ll index, ll value)
{
      while(index<=N){
            BIT[index]+=value;
            index += (index&(-index));
      }
}
ll PrefixSum(ll index)
{
      ll ret = 0;
      while(index>0){
            ret+=BIT[index];
            index-=(index&(-index));
      }
      return ret;
}
int main()
{
      scanf("%lld",&N);

      for (int i=1 ; i<=N ; i++){
            scanf("%lld",&A[i]);
            AddElement(i,A[i]);
      }

      while(true){
            ll id;
            cin >> id;
            cout << PrefixSum(id) << endl;
      }



      return 0;
}

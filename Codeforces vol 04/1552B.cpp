#include <bits/stdc++.h>
#define ll              long long int
#define scl(w)          scanf("%I64d",&w)
#define show(x)         cout << #x << " : " << x << endl

using namespace std;

struct node
{
      ll arr[7];
};

bool compare(node x, node y)
{
      ll cnt = 0;
      for (int i=0 ; i<5 ; i++){
            if (x.arr[i]<y.arr[i])cnt++;
      }
      if (cnt>2)return true;
      return false;
}

bool check(vector<node>v)
{
      bool ret = true;

      for (int i=1 ; i<v.size() ; i++){
            ret = (ret&compare(v[0],v[i]));
      }
      return ret;
}

int main()
{
      ll tc;
      cin >> tc;

      while(tc--){
            ll n;
            cin >> n;
            vector<node> v;
            node nd;
            for (int i=0 ; i<n ; i++){
                  for (int j=0 ; j<5 ; j++){
                        cin >> nd.arr[j];
                  }
                  nd.arr[5] = i+1;
                  v.push_back(nd);
            }

            sort(v.begin(),v.end(),compare);

            if (check(v))cout << v[0].arr[5] << endl;
            else cout << -1 << endl;
      }

      return 0;
}

/**

*/

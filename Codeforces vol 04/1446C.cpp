#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll mx = 0;

ll rec(vector<ll> v, ll bit)
{

      if (bit==0LL)return v.size();

      vector<ll> v_new[2];
      ll x = (1LL<<bit) , n = v.size();
      for (int i=0 ; i<n ; i++){
            ll id = (v[i]&x);
            if (id != 0)id = 1;

            v_new[id].push_back(v[i]);
      }

      ll t1 = 0, t2 = 0;
      if (!v_new[0].empty())t2 = 1;
      if (!v_new[1].empty())t1 = 1;

      if (!v_new[0].empty())t1+=rec(v_new[0],bit-1);
      if (!v_new[1].empty())t2+=rec(v_new[1],bit-1);

//      if (bit<=3){
//            show(bit);
//            for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
//            cout << endl;
//            show(t1);
//            show(t2);
//            cout << endl;
//      }

      return max(t1,t2);
}

int main()
{
      ll n;
      scanf("%lld",&n);

      vector<ll>v;

      for (int i=0 ; i<n ; i++){
            ll a;
            scanf("%lld",&a);
            v.push_back(a);
      }

      printf("%lld\n",n-rec(v,31));

      return 0;
}

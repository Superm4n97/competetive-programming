#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 300005

using namespace std;

ll bit[maxn][3] , P[60] , A[maxn];

void rec(vector <ll> v, ll mask)
{
      if (v.size()==1 || mask<0)return;

      ll x = P[mask] , n = v.size();

      vector <ll> v_0 , v_1;
      ll one = 0 , zero = 0 , csum = 0 , ret = 0;

      for (int i=n-1 ; i>=0 ; i--){

            if (x&v[i]){

                  ret += csum;
                  one++;
                  v_1.push_back(v[i]);
            }
            else {
                  csum++;
                  zero++;
                  v_0.push_back(v[i]);
            }
      }

      if (!v.empty())reverse(v_0.begin(),v_0.end());
      if (!v.empty())reverse(v_1.begin(),v_1.end());

      if (v_0.empty()){
            rec(v_1 , mask-1);
            return;
      }

      if (v_1.empty()){
            rec(v_0 , mask-1);
            return;
      }

      ll ret_alter = (zero*one) - ret;

      bit[mask][0] += ret;
      bit[mask][1] += ret_alter;
//
//      if (mask==2){
//            show(mask);
//            for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
//            cout << endl;
//            show(ret);
//            show(ret_alter);
//            cout << endl;
//      }
//
//      if (mask==0){
//            show(mask);
//            for (int i=0 ; i<v.size() ; i++)cout << v[i] << " ";
//            cout << endl;
//            show(ret);
//            show(ret_alter);
//            cout << endl;
//      }

      rec(v_0,mask-1);
      rec(v_1,mask-1);

      return;
}

int main()
{
      ll n;
      cin >> n;
      vector<ll> v;

      for (int i=0 ; i<n ; i++){

            ll a;
            cin >> a;
            v.push_back(a);
      }

      P[0] = 1;
      for (ll i=1 ; i<36 ; i++)P[i] = P[i-1]*2;

      rec(v,33);

      ll ans = 0 , inversion = 0;

//      show(bit[1][0]);
//      show(bit[1][1]);

      for (ll i = 0 ; i<34 ; i++){
            if (bit[i][0]<=bit[i][1]){
                  inversion+=bit[i][0];
            }
            else {
                  inversion+=bit[i][1];
                  ans+=P[i];
            }
      }

      cout << inversion << " "<< ans<< "\n";

      return 0;
}

/**
9
10 7 9 10 7 5 5 3 5
6 11 5 6 11 9 9 15 9 ->12(10)
4 9 7 4 9 11 11 13 11 ->14(4)
->1
 4
0111
0111
0101
0101
0101

0011


1010
1001
1010
**/

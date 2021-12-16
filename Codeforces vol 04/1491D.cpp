#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

ll a, b;
vector<ll> va,vb;

ll BIT_ON(ll x)
{
      ll ret = 0;
      while(x){
            if (x%2==1)ret++;
            x/=2;
      }
      return ret;
}

void makeArrayA(ll x)
{
      va.clear();
      while(x){
            if (x%2==1)va.push_back(1);
            else va.push_back(0);
            x/=2;
      }
}
void makeArrayB(ll x)
{
      vb.clear();
      while(x){
            if (x%2==1)vb.push_back(1);
            else vb.push_back(0);
            x/=2;
      }
}

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            scl(a),scl(b);

            if (a>b){
                  printf("NO\n");
                  continue;
            }

            makeArrayA(a);
            makeArrayB(b);

            ll cnt_a = BIT_ON(a) , cnt_b = BIT_ON(b);
            ll dif = cnt_a - cnt_b;

            if(dif<0){
                  printf("NO\n");
                  continue;
            }

            cnt_a = cnt_b = 0;
            bool sol = true;

            for (int i=0 ; i<va.size() ; i++){
                  if (va[i]==1)cnt_a++;
                  if (vb[i]==1)cnt_b++;
                  if (cnt_b>cnt_a)sol = false;
            }

            if (!sol)printf("NO\n");
            else printf("YES\n");
      }

      return 0;
}

/**
68421
10110
11001

1
22 25

0110
1001

1
6 9

**/

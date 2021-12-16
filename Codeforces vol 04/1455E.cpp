#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

ll point[5][3] , P[7][5] , A[4][3];

void init()
{
      P[0][0] = P[1][0] = P[2][1] = P[3][2] = P[4][1] = P[5][2] = 1;
      P[0][1] = P[1][2] = P[2][0] = P[3][0] = P[4][2] = P[5][1] = 2;
      P[0][2] = P[1][1] = P[2][2] = P[3][1] = P[4][0] = P[5][0] = 3;
}
///P[0] = 0,1,2

ll findDis(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll id)
{
      ll ret = abs(point[P[id][0]][0]-x1);
      ret += abs(point[P[id][0]][1]-y1);

      ret += abs(point[P[id][1]][0]-x2);
      ret += abs(point[P[id][1]][1]-y2);

      ret += abs(point[P[id][2]][0]-x3);
      ret += abs(point[P[id][2]][1]-y3);

      return ret;
}

ll calculation2(ll len, ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
      ll ret = findDis(x1, y1, x2, y2, x3, y3, 0LL);
      for (int i=1 ; i<6 ; i++)ret = min(ret,findDis(x1, y1, x2, y2, x3, y3, i));
      return ret;
}

ll calculation(ll len)
{
      ll t1 = calculation2(len,point[0][0]+len,point[0][1],point[0][0],point[0][1]+len,point[0][0]+len,point[0][1]+len);
      ll t2 = calculation2(len,point[0][0]+len,point[0][1],point[0][0],point[0][1]-len,point[0][0]+len,point[0][1]-len);
      ll t3 = calculation2(len,point[0][0]-len,point[0][1],point[0][0],point[0][1]+len,point[0][0]-len,point[0][1]+len);
      ll t4 = calculation2(len,point[0][0]-len,point[0][1],point[0][0],point[0][1]-len,point[0][0]-len,point[0][1]-len);
      return min(min(t1,t2),min(t3,t4));
}

int main()
{
      init();

      int tc;
      cin >> tc;

      while(tc--){

            for (int i=0 ; i<4 ; i++){
                  cin >> point[i][0] >> point[i][1];
            }

            ll b = 0, e = 1000000009, ans = 10000000090000009;
            while(b<=e){

                  ll mid1 = b+(e-b)/3 , mid2 = e - (e-b)/3;
                  ll res1 = calculation(mid1) , res2 = calculation(mid2);

                  ans = min(ans,min(res1,res2));

                  if (res1>res2)b = mid1+1;
                  else e = mid2-1;
            }

            cout << ans << endl;
      }

      return 0;
}

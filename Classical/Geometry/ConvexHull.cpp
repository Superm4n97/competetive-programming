#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll N;
vector <pair < ll,ll > > points;
stack < pair < ll,ll > > st;

ll Direction(pair<ll,ll>p1, pair<ll,ll>p2, pair<ll,ll>p3)
{
      /*clockwise(-1), counter clockwise(1), degenerating(0)*/

      ll ret = (p1.first *p2.second + p2.first*p3.second + p3.first*p1.second) - (p2.first*p1.second + p3.first*p2.second + p1.first*p3.second);
      if (ret<0)ret = -1;
      if (ret>0)ret = 1;

      return ret;
}

void ConvexHull()
{
      sort(points.begin(),points.end());

      for (int i=0 ; i<points.size() ; i++){
            if (st.empty()){

                  st.push(points[i]);
                  continue;
            }

            pair <ll,ll> p = points[i];

            bool dontPush = false;

            while (st.size()>1){

                  pair <ll,ll> p2,p3;
                  p2 = st.top();
                  st.pop();
                  p3 = st.top();

                  if (p2==p || p3==p){
                        st.push(p2);
                        dontPush = true;
                        break;
                  }

                  ll dir = Direction(p3,p2,p);

                  if (dir<0){/*if three points are linear they are not counted*/
                        st.push(p2);
                        break;
                  }
            }
            if (!dontPush) st.push(p);
      }

      for (int i=points.size()-1 ; i>=0 ; i--){
            if (st.empty()){

                  st.push(points[i]);
                  continue;
            }

            pair <ll,ll> p = points[i];

            bool dontPush = false;

            while (st.size()>1){

                  pair <ll,ll> p2,p3;
                  p2 = st.top();
                  st.pop();
                  p3 = st.top();

                  if (p2==p || p3==p){
                        st.push(p2);
                        dontPush = true;
                        break;
                  }

                  ll dir = Direction(p3,p2,p);

                  if (dir<0){/*if three points are linear they are not counted*/
                        st.push(p2);
                        break;
                  }
            }

            if (!dontPush)st.push(p);
      }

      st.pop();
}

int main()
{
      scanf("%lld",&N);
      for (int i=1 ; i<=N; i++){
            ll x,y;
            cin >> x >> y;
            points.push_back({x,y});
      }

      ConvexHull();


      while(!st.empty()){
            cout << st.top().first << " " << st.top().second << endl;
            st.pop();
      }




      return 0;
}

/**
6
0 5
2 5
5 0
5 3
5 5
5 10


5
5 10
5 5
5 3
5 0
10 5


13
5 10
10 10
8 8
7 8
5 7
7 5
15 5
10 5
0 5
10 0
5 0
1 4
13 3


5
1 1
2 2
3 3
4 4
5 5

x1 y1
x2 y2
x3 y3
x1 y1

(x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3)
**/

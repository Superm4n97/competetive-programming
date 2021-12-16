#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

ll N;
vector <pair < ll,ll > > points , hullPoints;
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

double findDistence(pair<ll,ll>p1, pair<ll,ll>p2)
{
      double a = (double) p1.first;
      double b = (double) p1.second;
      double c = (double) p2.first;
      double d = (double) p2.second;

      return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

double findAngle(pair<ll,ll> p1, pair<ll,ll> p2, pair<ll,ll>p3)
{
      double a = findDistence(p2,p3) , b = findDistence(p1,p2), c = findDistence(p1,p3);

      double red = acos((b*b + c*c - a*a) / (2*b*c));

      /*cout << "P1 : " << p1.first << " " << p1.second << endl;
      cout << "P2 : " << p2.first << " " << p2.second << endl;
      cout << "P3 : " << p3.first << " " << p3.second << endl;
      show(a);
      show(b);
      show(c);
      show(red);
      */
      return red;
}

int main()
{
      ll tc;
      cin >> tc;

      for (int _t = 1 ; _t<=tc ; _t++){

            points.clear();
            hullPoints.clear();
            while(!st.empty())st.pop();

            scanf("%lld",&N);
            for (int i=1 ; i<=N; i++){
                  ll x,y;
                  cin >> x >> y;
                  points.push_back({x,y});
            }

            ConvexHull();

            double ans = 360.0;


            while(!st.empty()){
                  hullPoints.push_back(st.top());
                  st.pop();
            }

            if (hullPoints.size()<=2)cout << "Case " << _t << ": "<< 0 << endl;
            else {
                  hullPoints.push_back(hullPoints[0]);
                  hullPoints.push_back(hullPoints[1]);

                  for (int i=1 ; i<hullPoints.size()-1 ; i++){
                        ans = min(ans,findAngle(hullPoints[i] , hullPoints[i+1],hullPoints[i-1]));
                  }

                  for (int i=1 ; i<hullPoints.size()-1 ; i++){
                        ans = min(ans,findAngle(hullPoints[i] , hullPoints[i+1],hullPoints[i-1]));
                  }

                  ans = ans*180.0/acos(-1);
                  printf("Case %d: %.15lf\n",_t,ans);
            }
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

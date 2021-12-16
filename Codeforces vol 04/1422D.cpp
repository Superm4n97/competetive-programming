#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

map <pair<ll,ll> ,ll> mp , check;
vector <pair<ll,ll> > vx,vy;
pair <ll,ll> links[maxn];
ll n,m,dis[maxn],disY[maxn] , sx,sy,fx,fy;

int main()
{
      scanf("%I64d %I64d %I64d %I64d %I64d %I64d",&m,&n,&sx,&sy,&fx,&fy);
      for (int i=0 ; i<n; i++){

            ll x,y;
            scanf("%I64d %I64d",&x,&y);

            if (check[{x,y}]==0){
                  vx.push_back({x,y});
                  vy.push_back({y,x});
                  check[{x,y}] = 1;
            }
      }

      if (check[{sx,sy}]==0){
            vx.push_back({sx,sy});
            vy.push_back({sy,sx});
      }

      m = vx.size();

      for (int i=0 ; i<maxn ; i++)dis[i] = disY[i] = 100000000000014;

      sort(vx.begin(),vx.end());
      sort(vy.begin(),vy.end());

      for (ll i=0 ; i<vx.size() ; i++){
            mp[{vx[i].first,vx[i].second}] = i;
            links[i].first = i;
      }
      for (int i=0 ; i<vy.size() ; i++)links[mp[{vy[i].second,vy[i].first}]].second = i;

      ll startId = mp[{sx,sy}] , finishId = mp[{fx,fy}];

      priority_queue<pair<ll,ll> > pq;
      dis[startId] = 0;
      pq.push({0,startId});

//      show(startId);


      while(!pq.empty()){

            ll id = pq.top().second , dts = -pq.top().first;
            pq.pop();

            if(dis[id]!= dts)continue;

            ll ff = links[id].first , ss = links[id].second , x = vx[id].first , y = vx[id].second;

//            show(id);
//            show(x);
//            show(y);
//            show(dts);

            {
                  if (ff>0){
                        ll a = vx[ff-1].first , b = vx[ff-1].second;
                        ll d = abs(x-a);


                        if (dis[id]+d < dis[mp[{a,b}]]){
//                              ll temp = mp[{a,b}];
//                              show(temp);
//                              if (temp==0){
//                                    show("1");
//                              }
                              dis[mp[{a,b}]] = dis[id]+d;
                              pq.push({-dis[mp[{a,b}]] ,mp[{a,b}]});
                        }
                  }
                  if (ff<m-1){
                        ll a = vx[ff+1].first , b = vx[ff+1].second;
                        ll d = abs(x-a);


                        if (dis[id]+d < dis[mp[{a,b}]]){
//                        ll temp = mp[{a,b}];
//                        show(temp);
//                        if (temp==0){
//                                    show("2");
//                                    show(a);show(b);
//                              }

                              dis[mp[{a,b}]] = dis[id]+d;
                              pq.push({-dis[mp[{a,b}]] ,mp[{a,b}]});
                        }
                  }
            }

            {
                  if (ss>0){
                        ll a = vy[ss-1].second , b = vy[ss-1].first;
                        ll d = abs(y-b);


                        if (dis[id]+d < dis[mp[{a,b}]]){
//                        ll temp = mp[{a,b}];
//                        show(temp);
//                        if (temp==0){
//                                    show("3");
//                              }
                              dis[mp[{a,b}]] = dis[id]+d;
                              pq.push({-dis[mp[{a,b}]] ,mp[{a,b}]});
                        }
                  }
                  if (ss<m-1){
                        ll a = vy[ss+1].second , b = vy[ss+1].first;
                        ll d = abs(y-b);

                        if (dis[id]+d < dis[mp[{a,b}]]){
//                        ll temp = mp[{a,b}];
//                        show(temp);
//                        if (temp==0){
//                                    show("4");
//                                    show(a);show(b);
//                              }
                              dis[mp[{a,b}]] = dis[id]+d;
                              pq.push({-dis[mp[{a,b}]] ,mp[{a,b}]});
                        }
                  }
            }
//            cout << endl;
      }

//      for (int i=0 ; i<vx.size() ; i++){
//            cout << "i:" << i << "  x:" << vx[i].first << "  y:" << vx[i].second << "  dis:" << dis[i] << endl;
//      }

      ll ans = 100000000000014;

      for (ll i = 0 ; i<vx.size() ; i++){
            ll d = dis[i]+abs(vx[i].first-fx)+abs(vx[i].second-fy);
            ans = min(ans,d);
      }

      printf("%I64d\n",ans);


      return 0;
}

#include <bits/stdc++.h>
#define pb              push_back
#define ll              long long int
#define scd(a)          scanf("%d",&a)
#define mp(a,b)         make_pair(a,b)
#define scl(w)          scanf("%I64d",&w)
#define scdd(a,b)       scanf("%d %d",&a,&b)
#define srt(a)          sort(a.begin(),a.end())
#define rsrt(a)         sort(a.rbegin(),a.rend())
#define scll(a,b)       scanf("%I64d %I64d",&a,&b)
///4direction ->        int del_x[]={-1,0,1,0},del_y[]={0,1,0,-1};
#define input(v,n)      for (int i=0;i<n;i++){int a;cin >> a;v.push_back(a);}
#define inputll(v,n)    for (ll i=0;i<n;i++){ll a;cin >> a;v.push_back(a);}
#define vii             vector < int >
#define vll             vector < ll >
#define pii             pair < int , int >
#define pll             pair < ll , ll >
#define show(x)         cout << #x << " : " << x << endl
#define mk              make_pair
#define inf             10000000000000016

#define maxn            1000006

using namespace std;

ll n,m,k , sum = 0, cntA = 0 , cntB = 0 , cntTotal = 0 , check[maxn];
ll AA[maxn] , BB[maxn] , TT[maxn];
stack < ll > stA , stB;
vector < pair < pair < ll , ll > , pair < ll, ll > > > v , special , u;

int main()
{
      cin >> n >> m >> k;
      for (int i=1 ; i<=n;i++){

            ll t,a,b;
            cin >> t >> a >> b;

            if (a==0 && b==0)special.pb({{t,i},{a,b}});
            else v.pb({{t,i},{a,b}});
      }
      srt(v);
      srt(special);

      for (int i=0 ; i<v.size() ; i++){

            ll t = v[i].first.first , id = v[i].first.second , a = v[i].second.first , b = v[i].second.second;

            if (cntTotal>=m && a==1 && b==0 && cntA>=k)continue;
            if (cntTotal>=m && b==1 && a==0 && cntB>=k)continue;

            ll headA  = -1 , headB = -1;

            if (!stA.empty())headA = stA.top();
            if (!stB.empty())headB = stB.top();

            if (cntTotal<m){
                  sum+=t;
                  if (a==1 && b==0){
                        cntA++;
                        cntTotal++;
                        stA.push(id);
                  }
                  else if (b==1 && a==0){
                        cntB++;
                        cntTotal++;
                        stB.push(id);
                  }
                  else if (a==1 && b==1){
                        cntA++;
                        cntB++;
                        cntTotal++;
                  }
                  else {
                        cntTotal++;
                  }

                  check[id] = 1;

                  if (cntA>=k && cntB>=k && cntTotal>=m)break;
            }
            else {
                  if (cntA>=k){
                        stA.pop();

                        sum+=t;
                        sum-=v[headA].first.first;

                        check[v[headA].first.second] = 0;
                        check[id] = 1;

                        cntB++;
                        if (a==0)cntA--;
                  }
                  else if(cntB>=k){
                        stB.pop();

                        sum+=t;
                        sum-=v[headB].first.first;

                        check[v[headB].first.second] = 0;
                        check[id] = 1;

                        cntA++;
                        if (b==0)cntB--;
                  }

                  if (cntA>=k && cntB>=k)break;
            }
      }

      for (int i=1 ; i<=n;i++){
            if (check[i]==1)u.pb({{TT[i],i},{AA[i],BB[i]}});
      }
      rsrt(u);

      for (int i=0 ; i<u.size() ; i++){

            ll t = u[i].first.first , id = u[i].first.second;
            ll a = u[i].second.first , b = u[i].second.second;

            if (cntTotal<m){
                  cntTotal++;
                  sum+=t;
            }
            else {
                  if (cntA>k && cntB>k){
                        ll headA = headB = -1;

                        if (!stA.empty())headA
                  }
                  else if (cntA>k){

                  }
                  else if (cntB>k){

                  }
            }
      }

      if (cntTotal>=m && cntA>=k && cntB>=k)cout << sum << endl;
      else cout << -1 << endl;



      return 0;
}

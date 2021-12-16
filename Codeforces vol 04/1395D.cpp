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
///4direction ->        int dx[]={-1,0,1,0},dy[]={0,1,0,-1};
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

ll n,d,m , sum = 0 , ans = 0;

priority_queue < ll > A , B , E , D;

int main()
{
      cin >> n >> d >> m;

      for (int i=1 ; i<=n ; i++){

            ll a;
            cin >> a;

            if (a<=m){

                  A.push(-a);
                  sum+=a;
            }
            else {
                  B.push(a);
            }
      }

      if (!B.empty()){
            sum+=B.top();
            B.pop();
      }
      ans = sum;

      if (!B.empty()){

            ll temp = B.size() / (d+1) , rem = B.size()%(d+1);

            if (temp>0){
                  for (int i=0 ; i<temp ; i++){
                        sum+=B.top();
                        B.pop();
                  }
            }

            for (int i=0 ; i<rem ; i++){
                  D.push(B.top());
                  B.pop();
            }

            while(!B.empty()){
                  E.push(B.top());
                  B.pop();
            }
      }

      ans = max(ans,sum);

      //show(E.size());
      //show(A.size());

      //show(ans);

      while(true){

            if (A.size()>=d && !D.empty()){
                  sum+=D.top();
                  D.pop();

                  for (int i=0 ; i<d ; i++){
                        sum+=A.top();
                        A.pop();

                  }

                  ans = max(ans,sum);
            }
            else break;
      }

      while(true){

            if (A.size()>=d+1 && !E.empty()){

                  for (int i=0 ; i<=d ; i++){

                        ll a = A.top()*-1;
                        A.pop();

                        sum-=a;
                  }

                  sum+=E.top();

                  //show(E.top());

                  E.pop();

                  //show(sum);

                  ans = max(ans,sum);
            }
            else {

                  while(!A.empty()){
                        D.push(A.top()*-1);
                        sum+=A.top();

                        A.pop();
                  }

                  break;
            }
      }

      ll temp = D.size()/(d+1);

      if(temp){
            sum+=D.top();
            D.pop();

            ans = max(ans,sum);
      }

      cout << ans << endl;


      return 0;
}

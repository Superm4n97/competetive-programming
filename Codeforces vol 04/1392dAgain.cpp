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

ll n;

ll findL(ll a)
{
      if (a==0)return n-1;
      else return a-1;
}

ll findR(ll a)
{
      if (a==n-1)return 0;
      return a+1;
}

int main()
{
      int tc;
      cin >> tc;

      while(tc--){

            cin >> n;

            ll A[n+5];
            memset(A,0,sizeof A);

            string s;
            cin >> s;

            for (int i=0 ; i<n ; i++){
                  if (s[i]==s[findL(i)] && s[i]==s[findR(i)])A[i]++;
            }

            priority_queue < pair <ll,ll> > pq;

            for (int i=0 ; i<n ; i++){
                  if (A[i] != 0)pq.push({A[i],i});
            }

            ll ans = 0;

            while(!pq.empty()){

                  ll a = pq.top().first , i = pq.top().second;
                  pq.pop();

                  if(A[i]!=a){
                        if (A[i]!=0)pq.push({A[i],i});
                  }
                  else {
                        ans++;
                        A[i] = 0;
                        A[findL(i)] = 0;
                        A[findR(i)] = 0;
                  }
            }

            cout << ans << endl;
      }


      return 0;
}

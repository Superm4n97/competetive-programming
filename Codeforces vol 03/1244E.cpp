#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%I64d",&x)

using namespace std;

map < ll, ll> mp;
priority_queue <ll> A,B;
ll n , k;

int main()
{
      scl(n);
      scl(k);

      for (int i=1; i<=n ; i++){
            ll a;
            scl(a);
            mp[a]++;
            if (mp[a]==1){
                  A.push(a);
                  B.push(-a);
            }
      }

      ll mx,mn;

      while(true){
            ll a = A.top() , b = B.top()*-1;
            if (a<=b){
                  //show(a);
                  //show(b);
                  mx = mn = a;
                  break;
            }

/*
            show(a);
            show(b);
            show(mp[a]);
            show(mp[b]);

*/
            if (mp[a]>mp[b]){
                  ll cnt = mp[b];
                  if(cnt>k){
                        mx = a;
                        mn = b;
                        break;
                  }

                  B.pop();
                  ll sc = B.top()*-1;

                  if ((sc-b)*cnt<=k){
                        k-=(sc-b)*cnt;
                        mp[sc] += cnt;
                  }
                  else {
                        ll temp = k / cnt;
                        k-=temp*cnt;
                        b+=temp;
                        mp[b] = cnt;
                        B.push(-b);
                  }
            }
            else {
                  ll cnt = mp[a];
                  if (cnt>k){
                        mx = a;
                        mn = b;
                        break;
                  }
                  A.pop();
                  ll sc = A.top();

                  if ((a-sc)*cnt<=k){
                        k-=(a-sc)*cnt;
                        mp[sc]+=cnt;
                  }
                  else {
                        ll temp = k/cnt;
                        k-=temp*cnt;
                        a-=temp;
                        mp[a] = cnt;
                        A.push(a);
                  }
            }

            //cout << endl;
      }

//      show(mx);
//      show(mn);

      cout << mx-mn << endl;


      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define scl(x) scanf("%lld",&x)
#define inf 100000000000000017

using namespace std;

int main()
{
      ll tc;
      scl(tc);

      while(tc--){
            ll W,H,x1,x2,y1,y2,w,h;
            cin >> W >> H;
            cin >> x1 >> y1 >> x2 >> y2;
            cin >> w >> h;

            ll l = x1 , d = y1 , r = W - x2 , u = H-y2, ans = inf;
            ll tw = x2-x1 , th = y2-y1;
            if (l>=w || r>=w || u>=h || d>=h)ans = 0;

            if (tw+w<=W){
                  ans = min(ans,min(abs(w-l),abs(w-r)));
            }
            if (th+h<=H){
                  ans = min(ans,min(abs(h-u),abs(h-d)));
            }
            if (ans==inf)cout << -1 << endl;
            else cout << ans << endl;
      }

      return 0;
}

#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 100005

using namespace std;

int A[maxn] , n , id , type = 0 , ans;

int query(ll l, ll r)
{
      if (l<=0 || r>n || l==r)return 0;

      cout << "? " << l << " "<< r << endl;
      fflush(stdout);

      int i;
      cin >> i;

      return i;
}

int main()
{
      cin >> n;

      cout << "? 1 " <<n<< endl;
      fflush(stdout);
      cin >> id;

      if (query(id,n)==id)type = 1;

      if (type==0){
            ans = 0;
            int b = 1, e = id-1;
            while(b<=e){
                  int mid = (b+e)/2;
                  int ret = query(mid,id);
                  if (ret == id){
                        ans = max(ans,mid);
                        b = mid+1;
                  }
                  else e = mid-1;
            }
      }
      else {
            ans = n+1;
            int b = id+1,e = n;
            while(b<=e){
                  int mid = (b+e)/2;
                  int ret = query(id,mid);
                  if (ret==id){
                        ans = min(ans,mid);
                        e = mid-1;
                  }
                  else b = mid+1;
            }
      }

      cout << "! " << ans << endl;
      fflush(stdout);


      return 0;
}

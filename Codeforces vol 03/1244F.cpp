#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define maxn 800005
#define left _left
#define right _right

using namespace std;

ll n,k , terminal[maxn] , initialColor[maxn] , finalColor[maxn] , distence[maxn];
string s;

char alterChar(char ch)
{
      return 'W'+'B' - ch;
}

char findColor(ll a)
{
      if (a==1)return 'W';
      return 'B';
}

ll checkIndex(ll a)
{
      if (a<=0)return a+n;
      if (a>n)return a-n;
      return a;
}

int main()
{
      memset(distence,-1,sizeof distence);

      cin >> n >> k;
      cin >> s;

      for (int i=0 ; i<n ; i++){
            if (s[i]=='W')initialColor[i+1] = 1;
            else initialColor[i+1] = 0;
      }
      for (int i=n+1 ; i<=2*n ; i++)initialColor[i] = initialColor[i-n];

      bool inf = true;

      for (int i=1 ; i<=n ; i++){

            ll left = checkIndex(i-1) , right = checkIndex(i+1);
            if (initialColor[i]==initialColor[left] || initialColor[i] == initialColor[right]){
                  terminal[i] = terminal[i+n] = 1;
                  finalColor[i] = finalColor[i+n] = initialColor[i];
                  distence[i] = distence[i+n] = 0;
                  inf = false;
            }
      }

      if (inf){

            bool alter = false;
            if(k%2)alter = true;
            for (int i=0 ; i<n ; i++){
                  if (alter)cout << alterChar(s[i]);
                  else cout << s[i];
            }
            cout << endl;

            return 0;
      }

      ll currentColor = -1 , dis = -1;

      for (int i=1 ; i<=2*n ; i++){
            if (terminal[i]==1){
                  currentColor = finalColor[i];
                  dis = 0;
                  continue;
            }

            dis++;

            if (currentColor!=-1){
                  finalColor[i] = currentColor;
                  distence[i] = dis;
            }
      }

      currentColor = dis = -1;

      for (int i = 2*n ; i>=1 ; i--){
            if (terminal[i]==1){
                  currentColor = finalColor[i];
                  dis = 0;
                  continue;
            }

            dis++;

            if (currentColor!=-1){
                  if (distence[i]==-1){
                        finalColor[i] = currentColor;
                        distence[i] = dis;
                  }
                  else {
                        if (dis<distence[i]){
                              finalColor[i] = currentColor;
                              distence[i] = dis;
                        }
                  }
            }
      }

      for (int i=1 ; i<=n ; i++){

            if(distence[i]>distence[i+n]){
                  distence[i] = distence[i+n];
                  finalColor[i] = finalColor[i+n];
            }
      }

      for (int i=1 ; i<=n ; i++){
            if (k>=distence[i]){
                  cout << findColor(finalColor[i]);
            }
            else {
                  ll temp = k%2;

                  if (temp==0)cout << findColor(initialColor[i]);
                  else cout << alterChar(findColor(initialColor[i]));
            }
      }
      cout << endl;



      return 0;
}

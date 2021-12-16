#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl

using namespace std;

int Absent[55][10004];
int n,m;

bool findPreviouslyAbsent(vector < ll > area , vector <ll > v , ll pos)
{
      if (pos==v.size())return true;
      if (area.empty())return false;
      vector < ll > nw;

      for (int i=0 ; i<area.size() ; i++){
            if (Absent[area[i]][v[pos]] == 1)nw.push_back(area[i]);
      }
      return findPreviouslyAbsent(nw,v,pos+1);
}

int main()
{
      bool solution = true;
      scanf("%d%d",&m,&n);
      for (int i=1 ;i<=m ; i++){
            vector < ll >NW,v;
            int a;
            scanf("%d",&a);

            for (int j = 0;  j<a ; j++){
                  int b;
                  scanf("%d",&b);
                  v.push_back(b);
            }

            for (int j= 1 ; j<=m ; j++){
                  NW.push_back(j);
            }

            if (findPreviouslyAbsent(NW,v,0)){
                  solution = false;
                  cout << "impossible" << endl;
                  return 0;
            }

            for (int j = 0 ; j<=n ; j++)Absent[i][j] = 1;

            for (int j = 0;j<v.size() ; j++){
                  Absent[i][v[j]] = 0;
            }
      }

      cout << (solution?"possible":"impossible") << endl;

      return 0;
}

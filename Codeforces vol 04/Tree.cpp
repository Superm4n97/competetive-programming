#include<bits/stdc++.h>

using namespace std;

vector < int > T[100];
int n;

void PreOrder(int u, int parent)
{
      cout << u << " ";
      for (int i=0 ; i<T[u].size() ; i++){
            int v = T[u][i];

            if (v!=parent){
                  PreOrder(v,u);
            }
      }
}

void PostOrder(int u , int parent)
{
      for (int i=0 ; i<T[u].size() ; i++){
            int v = T[u][i];

            if (v!=parent){
                  PostOrder(v,u);
            }
      }
      cout << u << " ";
}

int main()
{
      cout << "Nodes: ";
      cin  >> n;

      for (int i=1 ; i<=n-1 ; i++){

            int a,b;
            cin >>a >> b;

            T[a].push_back(b);
            T[b].push_back(a);
      }


      cout << "Pre-order: ";
      PreOrder(1,1);
      cout << endl;

      cout << "Post-order: ";
      PostOrder(1,1);
      cout << endl;



      return 0;
}

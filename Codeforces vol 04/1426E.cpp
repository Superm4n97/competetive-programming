#include<bits/stdc++.h>
#define ll long long int
#define show(x) cout << #x << " : " << x << endl
#define inf 100000000000000017

using namespace std;

ll n;

ll findMax(ll A[])
{
      ll ret = 0;
      ret+=min(A[0],A[4]);
      ret+=min(A[1],A[5]);
      ret+=min(A[2],A[3]);

      return ret;
}

ll findMin(ll per[] , ll A[])
{
      ll ret = 0;

      for (int i=0 ; i<6 ; i++){
            ll temp;

            if (per[i]==1){
                  temp = min(A[0],A[3]);
                  A[0]-=temp;
                  A[3]-=temp;
            }
            else if (per[i]==2){
                  temp = min(A[0],A[5]);
                  A[0]-=temp;
                  A[5]-=temp;
            }
            else if (per[i]==3){
                  temp = min(A[1],A[4]);
                  A[1]-=temp;
                  A[4]-=temp;
            }
            else if (per[i]==4){
                  temp = min(A[1],A[3]);
                  A[1]-=temp;
                  A[3]-=temp;
            }
            else if (per[i]==5){
                  temp = min(A[2],A[5]);
                  A[2]-=temp;
                  A[5]-=temp;
            }
            else if (per[i]==6){
                  temp = min(A[2],A[4]);
                  A[2]-=temp;
                  A[4]-=temp;
            }

            ret+=temp;
      }

      return n-ret;
}

int main()
{
      cin >> n;

      ll A[10] , P[] = {1,2,3,4,5,6} , copy_A[10];

      for (int i=0 ; i<6 ; i++){
            cin >> A[i];
            copy_A[i] = A[i];
      }

      ll mn = findMin(P,copy_A) , mx = 0;

      while(next_permutation(P,P+6)){
            for (int i=0 ; i<6 ; i++)copy_A[i] = A[i];
            mn = min(mn,findMin(P,copy_A));
      }

      mx = findMax(A);

      cout << mn << " " << mx << endl;


      return 0;
}

/**

Ar As Ap
Bs Bp Br

0  1  2  3  4  5
Ar As Ap Br Bs Bp

Ar Br 1
Ar Bp 2
As Bs 3
As Br 4
Ap Bp 5
Ap Bs 6

**/

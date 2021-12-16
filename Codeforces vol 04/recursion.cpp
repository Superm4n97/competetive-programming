#include<bits/stdc++.h>

using namespace std;

void F(int a)
{
      if (a==5)return;

      F(a+1);

      cout << a << endl;
}

int main()
{
      F(1);


      return 0;
}

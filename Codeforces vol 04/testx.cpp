#include<bits/stdc++.h>

using namespace std;

string fahem_s[100],fahem_s_new[100];
int fahem_n = 0,fahem_n_new = 1;

int main()
{
      cout << "Enter the number of string" << endl;
      cin >> fahem_n;
      cout << "Enter strings:" << endl;
      for (int i=0 ; i<fahem_n ; i++){
            cin >> fahem_s[i];
      }

      for (int i=0 ; i<fahem_n ; i++){
            for (int j=i+1 ; j<fahem_n ; j++){
                  if (fahem_s[j]<fahem_s[i])swap(fahem_s[i],fahem_s[j]);
            }
      }

      fahem_s_new[0] = fahem_s[0];
      for (int i=1 ; i<fahem_n ; i++){
            if (fahem_s[i]!=fahem_s[i-1]){
                  fahem_s_new[fahem_n_new] = fahem_s[i];
                  fahem_n_new++;
            }
      }

      cout << "Sorted fahem_array without duplicate is : " << endl;
      for (int i=0 ; i<fahem_n_new ; i++)cout << fahem_s_new[i] << " ";
      cout << endl;


      return 0;
}

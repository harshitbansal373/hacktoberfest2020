//this program returns the max sub-array sum in an array in O(n) time.

#include <iostream>

using namespace std;

int main()
{   
    int sizeofarray,a[100];
    cin >> sizeofarray;
  for (int i = 0; i < sizeofarray; ++i)
   {
      cin >> a[i];
   }
   
  int best=0,sum=0;
  for(int k=0;k<sizeofarray;k++)
  {
      sum=max(a[k],sum+a[k]);
      best=max(best,sum);
      
  }
  cout<<"Max. sub array sum is:"<<best;

    return 0;
}

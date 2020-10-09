#include <iostream>
using namespace std;

int kadane(int arr[], int n)
{
    int max_so_far = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = maxi + arr[i];
        maxi = max(maxi, 0);
        max_so_far = max(max_so_far, maxi);
    }

    return max_so_far;
}

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The sum of contiguous sub-array with the largest sum is " << kadane(arr, n);

    return 0;
}
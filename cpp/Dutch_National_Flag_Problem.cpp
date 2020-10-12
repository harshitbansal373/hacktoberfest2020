#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_Colors(int arr[], int n)

{
    int low = 0;
    int current = 0;
    int high = n - 1;

    while (current <= high)
    {
        if (arr[current] == 0)
        {
            swap(&arr[low], &arr[current]);
            low++;
            current++;
        }
        else if (arr[current] == 1)
        {
            current++;
        }
        else if (arr[current] == 2)
        {
            swap(&arr[high], &arr[current]);
            high--;
        }
    }
}

int main()
{
    //Denote Red->0, White->1, Blue->2
    int arr[] = {0, 1, 2, 1, 1, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    sort_Colors(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
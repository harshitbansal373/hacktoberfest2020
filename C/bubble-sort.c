#include <stdio.h>
#include <conio.h>

void bubble_sort(int A[], int N)
{
    int x, y, temp;
    for (x = 0; x <= N - 1; x++)
    {
        for (y = 0; y <= N - 1; y++)
        {
            if (A[i] > A[i + 1])
            {
                temp = A[y];
                A[y] = A[y + 1];
                A[y + 1] = temp;
            }
        }
    }
}

int main()
{
    int no;
    printf("Enter no that you want to enter:");
    scanf("%d", &no);
    int A[no];
    printf("\nEnter no:\n");
    for (int y = 0; y < no; y++)
    {
        scanf("%d", &A[i]);
    }
    bubble_sort(A, no);

    //Print after sorting
    for (int y = 0; y < no; y++)
    {
        printf("%d ", A[y]);
    }
    return 0;
}

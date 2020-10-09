#include <stdio.h>

int main()
{
    int n, sum, prev;
    printf("size:");
    scanf("%d", &n);
    int a = 0, m = n * n - 1;
    while (m)
    {
        a++;
        m /= 10;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum = i + j;
            prev = (sum <= n - 1 ? (sum * (sum + 1)) / 2 : n * n - ((2 * n - sum - 1) * (2 * n - sum)) / 2);
            (sum & 1) ? printf("%*d ", a, prev + ((i <= n - 1 - j) ? i : n - 1 - j)) : printf("%*d ", a, prev + ((j <= n - 1 - i) ? j : n - 1 - i));
        }
        printf("\n");
    }
    return 0;
}

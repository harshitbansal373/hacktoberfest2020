#include <stdio.h>
#include <string.h>
int main()
{
    int N;
    int sorted = 0;
    printf("how many string(s) do you wish to sort?\n");
    scanf("%d", &N);
    char str[N][100];
    char s[100];
    printf("input each string on a newline\n");
    for (int a = 0; a < N; a++)
    {
        scanf("%s[^\n]", str[a]);
    }
    while (sorted == 0)
    {
        sorted = 1;
        for (int i = 0; i < N - 1; i++)
        {
            if (strcmp(str[i], str[i + 1]) > 0)
            {
                sorted = 0;
                strcpy(s, str[i]);
                strcpy(str[i], str[i + 1]);
                strcpy(str[i + 1], s);
            }
        }
    }
    printf("\nsorted order is\n");
    for (int a = 0; a < N; a++)
    {
        printf("%s\n", str[a]);
    }
}

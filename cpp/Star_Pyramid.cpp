#include(stdio.h)

int main()
{
    int space, rows=5;

    for(int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for(space = 1; space <= rows-i; ++space)
        {
            printf(' ');
        }

        while(k != 2*i-1)
        {
            printf('*');
            ++k;
        }
        printf('\n');
    }    
    return 0;
}
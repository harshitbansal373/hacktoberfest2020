#include<bits/stdc++.h>
char *removespace(char *str)
{
    int i=0,j=0;
    while(str[i])
    {
        if(str[i]!='')
            str[j++] = str[i];
        i++;
    }
        str[j]='\0';
        return str;
}
int main()
{
    char str[] = "github code 2020  ";
    cout<<removespace(str)<<endl;
    return 0;
}

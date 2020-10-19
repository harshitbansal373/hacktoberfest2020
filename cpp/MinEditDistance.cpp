 /* minimum edit distance-Toconvert string s2 to s1 using
            minimum number of operations(edit,add or delete) */

#include<bits/stdc++.h>
using namespace std;

class minedit
{
    string s1,s2;
    public:
    minedit(string ,string);
    int mineditdistance();
    void operations(int **,int,int);
};
minedit::minedit(string a,string b)
{
    this->s1=a;
    this->s2=b;
}
int min3(int a,int b,int c)
{
    if(a<=b&&a<=c)
        return a;
    if(b<=a&&b<=c)
        return b;
    return c;
}
void minedit::operations(int **T,int i,int j)
{
    if(i==0||j==0)
        return;
    if(s1[j-1]==s2[i-1])
        operations(T,i-1,j-1);
    else if(T[i][j]==T[i-1][j-1]+1)
    {
        operations(T,i-1,j-1);
        printf("%c has to be converted to %c\n",s1[j-1],s2[i-1]);
    }
    else if(T[i][j]==T[i][j-1]+1)
    {
        operations(T,i,j-1);
        printf("%c has to be deleted\n",s1[j-1]);
    }
    else if(T[i][j]==T[i-1][j]+1)
    {
        operations(T,i-1,j);
        printf("%c has to be added\n",s2[i-1]);
    }
}
//to convert s1 to s2
int minedit::mineditdistance()
{
    int l1=s1.length();
    int l2=s2.length();
    int **T=(int **)malloc((l2+1)*sizeof(int *));
    for(int i=0;i<l2+1;i++)
        T[i]=(int *)malloc((l1+1)*sizeof(int));
    for(int i=0;i<l2+1;i++)
        T[i][0]=i;
    for(int i=0;i<l1+1;i++)
        T[0][i]=i;
    for(int i=1;i<l2+1;i++)
    {
        for(int j=1;j<l1+1;j++)
        {
            if(s2[j-1]==s1[i-1])
                T[i][j]=T[i-1][j-1];
            else
                T[i][j]=min3(T[i-1][j-1],T[i-1][j],T[i][j-1])+1;
        }
    }
    cout<<"Minimum number of operations to convert "<<s1<<" to "<<s2<<" is "<<T[l2][l1]<<endl;
    /* for(int i=0;i<l2+1;i++)
    {
        for(int j=0;j<l1+1;j++)
            printf("%d\t",T[i][j]);
        printf("\n");
    }*/
    cout<<"The following opeartions occur on "<<s1<<endl;
    operations(T,l2,l1);


}
int main()
{
    printf("Enter two strings\n");
    string s1,s2;
    cin>>s1;
    cin>>s2;
    minedit M(s1,s2);
    M.mineditdistance();
    return 0;
}

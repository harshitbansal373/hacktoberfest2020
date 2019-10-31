#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rev_string2(char *a,int k)
{
	if(k == 0)return 0;
	printf("%c",a[k-1]);
	rev_string(a,--k);
}
int main()
{
	char *strng = (char *)malloc(11*sizeof(char));
	scanf("%[^\n]s",strng);
	rev_string(strng , strlen(strng));
	printf("\n");
	return 0;
}

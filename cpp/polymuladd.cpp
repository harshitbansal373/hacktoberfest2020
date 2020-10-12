#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct term{

int coeff;
int expo;
};

typedef struct  poly{
int no_of_terms;
term t[10];
};

poly * accept(poly* p){

	printf("Enter the number of terms in the polynomial\n");
	scanf("%d",&(p->no_of_terms));
	printf("Start entering the polynomial \n");
	for (int i=0;i<(p->no_of_terms);i++)
	{
		scanf("%d%d",&(p->t[i].coeff),&(p->t[i].expo));
	}
	return p;

}

void display(poly * p){
	for (int i=0;i<(p->no_of_terms);i++)
	{
		printf("%dx^%d  ",(p->t[i].coeff),(p->t[i].expo));

	}
    printf("\n");
}

poly * add (poly * p1 ,poly *p2)
{
    int i=0, j=0, k=0;
	poly *p3;
	p3 = (poly*)malloc(sizeof(poly));

	while(i<(p1->no_of_terms) && j<(p2->no_of_terms))
	{
		if(p1->t[i].expo==p2->t[j].expo)
		{
			p3->t[k].expo=p1->t[i].expo;
			p3->t[k].coeff=p1->t[i].coeff + p2->t[j].coeff;
			i++;
			j++;
			k++;
		}
		else if(p1->t[i].expo > p2->t[j].expo)
		{
			p3->t[k].expo=p1->t[i].expo;
			p3->t[k].coeff=p1->t[i].coeff;
			i++;
			k++;
		}
		else if(p1->t[i].expo <p2->t[j].expo)
		{
			p3->t[k].expo=p2->t[i].expo;
			p3->t[k].coeff=p2->t[i].coeff;
			j++;
			k++;
		}

	}


	while(i<(p1->no_of_terms))

	{
		p3->t[k].expo=p1->t[i].expo;
		p3->t[k].coeff=p1->t[i].coeff;
		i++;
		k++;
	}

	while(j<(p2->no_of_terms))

	{
		p3->t[k].expo=p2->t[j].expo;
		p3->t[k].coeff=p2->t[j].coeff;
		j++;
		k++;
	}
    //printf("k=%d\n",k);
	p3->no_of_terms=k;
	//k=0;

	return p3;

}


poly *multiply(poly * p1, poly *p2 )
{
    poly * p3;
    poly * p4;
    poly * p5;
    p3=(poly*)malloc(sizeof(poly));
    p4=(poly*)malloc(sizeof(poly));
    p5=(poly*)malloc(sizeof(poly));
    p3->no_of_terms = 0;
    p4->no_of_terms = 0;
    p5->no_of_terms = 0;
    for(int i=0;i<(p1->no_of_terms);i++)
    {
        int k=0;
        for(int j=0;j<(p2->no_of_terms);j++)
        {
            p3->t[k].coeff=p1->t[i].coeff*p2->t[j].coeff;
            p3->t[k].expo=p1->t[i].expo + p2->t[j].expo;
            k++;
        }
        p3->no_of_terms=k;

        p4=add(p3,p4);
    }
    return p4;

}

float evaluate(poly*p,float x)
{
    float value=0;
    for (int i=0;i<p->no_of_terms;i++)
    {
        value=value+(float(p->t[i].coeff)*pow(x,float(p->t[i].expo)));
    }
    return value;
}
int main()
{

poly *p1;
poly *AddResult;
poly *MulResult;
p1 = (poly*)malloc(sizeof(poly));
poly *p2;
p2 = (poly*)malloc(sizeof(poly));

printf("Enter the first polynomial\n");
accept(p1);
printf("Enter the second polynomial\n");
accept(p2);

display(p1);
display(p2);

AddResult=add(p1,p2);
display(AddResult);
MulResult=multiply(p1,p2);
display(MulResult);
float ans=evaluate(p1,2);
printf("%f\n",ans);


}










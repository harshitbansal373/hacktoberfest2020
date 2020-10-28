#include<stdio.h>
#include<limits.h>

int main()
{
	int n,i,j,m,min=INT_MAX,c=0,k,count=0,z=0,r;
	float av_wt=0;
	float av_tat=0;
	float av_rt=0;
	
	printf("Enter number of processes\n");
	scanf("%d",&n);
	
	int a[n],b[n],ct[n],bt[n],tat[n],wt[n],ac[n],btc[n],p[20*n],rt[n];
	    
	printf("Enter arrival time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ac[i]=a[i];
		b[i]=i;
		rt[i]=INT_MAX;
		if(min>a[i])
			min=a[i];
	}
	
	
	printf("Enter burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
		btc[i]=bt[i];
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				m=a[i];
				a[i]=a[j];
				a[j]=m;
				
				m=b[i];
				b[i]=b[j];
				b[j]=m;
			}
		}
	}
	
	printf("Order:\n");
	
	if(min!=0)
	{
		printf("|idle for %d sec| ",min);
		c=min;
	}
	
	for(i=0;i<INT_MAX;)
	{
		min=INT_MAX;
		for(j=0;j<n;j++)
		{
			//r_min=INT_MAX;
			if(ac[b[j]]<=i)
			{	
				if(min>bt[b[j]])
				{
					min=bt[b[j]];
					k=b[j];
					
					r=i;
					
				}
			
			}
		}
		if(min!=INT_MAX)
		{
			p[z]=k;
			if(rt[k]>r)
			{
				rt[k]=r;
				//printf("RT of P%d:%d\n",k+1,r);
			}
		//	printf("%d bt %d at %d\n ",p[z]+1,bt[p[z]],ac[p[z]]);
			
			if(ct[p[z-1]]<ac[p[z]])
			{
				c=ac[p[z]]-ct[p[z-1]]+c;
			//	printf("idle for %d sec\n as ac is %d and ct is %d and c is %d\n",ac[p[z]]-ct[p[z-1]],ac[p[z]],ct[p[z-1]],c);
				printf("|idle for %d sec| ",ac[p[z]]-ct[p[z-1]]);		
			}
			
			printf("P%d ",p[z]+1);
			z++;
			i++;
			ct[k]=c+1;
			c=ct[k];
			bt[k]--;
			if(bt[k]==0)
			{
				count++;
				bt[k]=INT_MAX;
			}
			if(count==n)
			{
				break;
			}
				
		}
		else
			i++;
	}
	
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-ac[i];
		wt[i]=tat[i]-btc[i];
		rt[i]=rt[i]-ac[i];			
	}
	
	
	printf("\n");
		
	printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\tResponse Time\n");
	
	/*
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,ac[i],btc[i],ct[i],tat[i],wt[i]);
	}
	*/
	
	
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t%d\n",i+1,ac[i],btc[i],ct[i],tat[i],wt[i],rt[i]);
	}
	
		for(i=0;i<n;i++)
		{
			av_tat=tat[i]+av_tat;
			av_wt=wt[i]+av_wt;
			av_rt=rt[i]+av_rt;
		}
		printf(" avg tat : %f \n avg wt : %f \n avg rt : %f\n",(av_tat/n),(av_wt/n),(av_rt/n));
	
}

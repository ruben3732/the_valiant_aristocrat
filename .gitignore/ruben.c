#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
int main()

{
 int tu,pid[10],pr[10],need[10],wt[10],tat[10],i,j,n,n1,pos,temp;
 int bt[10],flag[10],ttat=0,twt=0;
 float awt,atat;

 printf("\t\t ROUND ROBIN SCHEDULING"); 
printf("Enter the number of Processors \n");
 
scanf("%d",&n);

 n1=n;
 
printf("\n Enter the Time unit \n");
 
scanf("%d",&tu);
 need[i]=bt[i];
 for(i=1;i<=n;i++)

 {
   
printf("\n Enter the Burst Time for the process");
   
scanf("%d",&bt[i]);
printf("\n Enter Priority:");
scanf("%d",&pr[i]); 
  pid[i]=i+1;
  
 }
for(i=0;i<n;i++)
{
	pos=i;
	for(j=i+1;j<n;j++)
	{
		if(pr[j]<pr[pos])
		pos=j;
	}
	 temp=pr[i];
	 pr[i]=pr[pos];
	 pr[pos]=temp;
	 
	 temp=bt[i];
	 bt[i]=bt[pos];
	 bt[pos]=temp;
	 
	 temp=pid[i];
	 pid[i]=pid[pos];
	 pid[pos]=temp;
}


 for(i=1;i<=n;i++)
 
{
  flag[i]=1;

  wt[i]=0;
 }
 
while(n!=0)

 {
   for(i=1;i<=n;i++)
   
{
     if(need[i]>=tu)
     
{
       for(j=1;j<=n;j++)
       
{
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  
wt[j]+=tu;
       }
      



       
need[i]-=tu;
      
 if(need[i]==0)
      
 {
	 flag[i]=0;
	 n--;
       }
     }
     
else
    
 {
       for(j=1;j<=n;j++)
      
 {
	  if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
	  
wt[j]+=need[i];
       }
       
need[i]=0;
       
n--;
       
flag[i]=0;
  
 }
 }
}

for(i=1;i<=n1;i++)

{
  tat[i]=wt[i]+bt[i];
  
twt=(twt+wt[i])/n1;
  
ttat=(ttat+tat[i])/n1;
}



printf("\n\n ROUND ROBIN SCHEDULING ALGORITHM \n\n");

printf("\n\n Process \t PID  \t BT \t WT \t TAT \t Priority \n ");

for(i=1;i<=n1;i++)
{
 
 printf("\n %5d \t %5d \t\t %5d \t\t %5d \t\t %5d \t\t %5d \n", i,pid[i],bt[i],wt[i],tat[i],pr[i]);
}



printf("\n The average Waiting Time=4.2f",twt);
printf("\n The average Turn around Time=4.2f",ttat);
getch();
}         


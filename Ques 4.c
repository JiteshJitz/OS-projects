//Non preemptive shortest job next with priority
#include<stdio.h> 
int n,i,j,total_time=0;
float avgtat=0,avgwt=0;
struct process
{
	int at,st,ct,tat,wt,priority;
	char pname[20],tempc[20];
	float ntat;

}temp;
void display(struct process a[]);
void finding(struct process a[]);

 int main()
{   
    int time;
	printf("Enter the no of process: \n");
	scanf("%d",&n);
	struct process  aa[n];
	for(i=0;i<n;i++)
	{
		printf("Enter the name of Process name,Arrival_time,Burst_time:      \n");
		scanf("%s",&aa[i].pname);
		scanf("%d%d",&aa[i].at,&aa[i].st);
	}
			int f;
			//assign priority
		for(f=0;f<n;f++)
		{
			if(time>=aa[f].at && aa[f].st!=(-1)) 
			{
			aa[f].priority=1+((time-aa[f].at)/aa[f].st);
}}
//Sorting according to the priority
	for(i=0;i<n;i++)
	{
		for(j=i;j>=1;j--)
		{
			if(aa[j].at<aa[j-1].at)
			{
			temp=aa[j-1];
			aa[j-1]=aa[j];
			aa[j]=temp;
			}
		}
	}
total_time+=aa[0].at+aa[0].st;
for(i=1;i<n;i++)
{
if(aa[i].at>total_time)
total_time=aa[i].at;
total_time+=aa[i].st;
}
printf("%d\n",total_time);
finding(aa);
return 0;
}
void display(struct process a[])
{
for(i=0;i<n;i++)
{
a[i].tat=a[i].ct-a[i].at;
a[i].wt=a[i].tat-a[i].st;
a[i].ntat=(float)a[i].tat/a[i].st;
}
for(i=0;i<n;i++)
{
avgtat+=a[i].tat;
avgwt+=a[i].wt;
}
avgtat=avgtat/n;
avgwt=avgwt/n;
printf("Process name\tArrival_Time\tBurst_Time\tCompletion_Time\tTurnaround_Time\tWaiting_Time\t\n");
for(i=0;i<n;i++)
{
printf("%s\t\t%d\t\t%d\t\t\t%d\t\t%d\t%d\n",a[i].pname,a[i].at,a[i].st,a[i].ct,a[i].tat,a[i].wt);
}
printf("Average turnaround time=%f\nAverage waiting time=%f\n",avgtat,avgwt);
}

void finding(struct process  a[])
{   

    //To find the process which  has longer priority
	int c_st=0,x, time=0,c;
	
	while(time<total_time)
	{
	c=0;
	j=0;
	for(i=0;i<n;i++)
	{	if(a[i].at<=time)
		{
			j=i+1;
		}
	}
	if(j>0)
	{
		int x=0,min_st=a[0].st;
		for(i=1;i<j;i++)
		{
			if(min_st>a[i].st)
			{
				x=i;
				min_st=a[i].st;
			}
		}
		time+=a[x].st;
		a[x].ct=time;
		a[x].st+=1000;
	}
	else
		time++;
	}
	for(i=0;i<n;i++){a[i].st-=1000;}
display(a);
}

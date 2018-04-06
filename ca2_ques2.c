//Round_Robin Question 5
#include<stdio.h>
struct round_robin
{
	
	int arrival_time,brust_time,waiting_time,turn_time,response_time, pro_name;
	int complete;
}s[15];
int number;
int queue[10];
int front= -1;
int rear=-1;
int enqueue(int a);
int dequeue();
int InQueue(int a);
void sortarrival();

//main
int main()
{
	
    int i,j,m=1,tm=0,sum=0,time_quan;
    float avgwt=0,avgbt=0;
     printf("Enter number of process:  ");
     scanf("%d",&number);
    for(i=0;i<number;i++,m++)
    {
    	s[i].pro_name=m;
         printf("\n Process %d\n",m);
         printf("\n Arrival Time of the process :");
         scanf("%d",&s[i].arrival_time);
         printf(" \n Burst Time of the process :");
         scanf("%d",&s[i].brust_time);
         s[i].response_time=s[i].brust_time;
         s[i].complete=0;
         sum=sum+s[i].brust_time;
	}
	//
	  printf("\nEnter the time quantum fort the process: ");
    scanf("%d",&time_quan);
    sortarrival();
    enqueue(0);         
    printf("Process execution order: ");
    for(tm=s[0].arrival_time;tm<sum;)      
    {   
        i=dequeue();
        if(s[i].response_time<=time_quan)
        {                         
                              
             tm=tm+s[i].response_time;
             s[i].response_time=0;
             s[i].complete=1;         
             printf(" %d   ",s[i].pro_name);
             s[i].waiting_time=tm-s[i].arrival_time-s[i].brust_time;
             s[i].turn_time=tm-s[i].arrival_time;      
            for(j=0;j<number;j++)    
            {
                if(s[j].arrival_time<=tm && s[j].complete!=1&& InQueue(j)!=1)
                {
                    enqueue(j);
                }
            }
        }
        else              
        {
            tm=tm+time_quan;
            s[i].response_time-=time_quan;
            printf(" %d  ",s[i].pro_name);
            for(j=0;j<number;j++)                             
            {
                if(s[j].arrival_time<=tm && s[j].complete!=1&&i!=j&& InQueue(j)!=1)
                {
                    enqueue(j);
                }
            }
            enqueue(i);  
        }
    }
//display
     printf("\nName \tArrival Time \tBurst Time \tResponse Time \tTurnAround Time");
    for(i=0;i<number;i++)
    {
        avgwt+=s[i].waiting_time;
        avgbt+=s[i].turn_time;
        printf("\n%d \t\t%d \t\t%d \t\t%d \t\t%d",s[i].pro_name,s[i].arrival_time,s[i].brust_time,s[i].waiting_time,s[i].turn_time);
    }
    printf("\nAverage waiting time:%f\n",avgwt/number);
     printf("\nAverage  tat  time:%f\n",avgbt/number);
    
}

int enqueue(int a)
{
	if(rear==15)
	printf("Overflow");
	rear=rear +1;
	queue[rear]=a;
	if(front==-1)
	front=0;
}
int dequeue()
{
    if(front==-1)
        printf("underflow");
    int t=queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return t;
}
int InQueue(int a)
{
    int k;
    for(k=front;k<=rear;k++)
    {
        if(queue[k]==a)
        return 1;
    }
    return 0;
}
void sortarrival()
{
    struct round_robin temp;
    int i,j;
    for(i=0;i<number-1;i++)
    {
        for(j=i+1;j<number;j++)
        {
            if(s[i].arrival_time>s[j].arrival_time)
            {
                temp=s[i];
          	    s[i]=s[j];
                s[j]=temp;
            }
        }
    }
}


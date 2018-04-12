/*Ques. 3. Consider a scheduler which schedules the job by considering the arrival time of the
processes where arrival time if given as 0 is discarded or displayed as error. The scheduler
implements the shortest job first scheduling policy, but checks the queue of the processes after
the every process terminates and time taken for checking and arranging the process according to
the shortest job is 2 time unit. Compute the waiting time, turnaround time and average waiting
time and turnaround time of the processes. Also compute the total time taken by the processor to
compute all the jobs.
The inputs for the number of requirements, arrival time and burst time should be provided by the
user.
Consider the following units for reference.
Process Arrival time Burst Time
1 0 6
2 3 2
3 5 1
4 9 7
5 10 5
6 12 3
7 14 4
8 16 5
9 17 7
10 19 2
Develop a scheduler which submits the processes to the processor in the defined scenario, and
compute the scheduler performance by providing the waiting time for process, turnaround time
for process and average waiting time and turnaround time.
*/

#include<stdio.h>

main()
{
	int timer=0,i=0,bt=0,q=0;
	int process[4]={1,2,3,4};
	int arrival[4]={0,3,5,9};
	int burst_time[4]={6,2,1,7};
	int burst[4]={6,2,1,7};
	int process_arrived[4]={0};
	int complete[4]={0};
	int n=0;
	while(1)
	{
		int p,q;
		for(p=0;p<n;p++)
		{
			for(q=0;q<n-1-p;q++)
			{
				if(burst[q]>burst[q+1] )
				{
					int t2=process_arrived[q];
					process_arrived[q]=process_arrived[q+1];
					process_arrived[q+1]=t2;
				}
			}
		}
		printf("%d ff %d ff %d ff %d",process_arrived[0],process_arrived[1],process_arrived[2],process_arrived[3]);
		if(process_arrived[0]!=0)
		{
		int y=process_arrived[0];
		bt=burst[y-1];
		do
		{
			//printf("timer : %d",timer);
			int x;
			for(x=0;x<4;x++)
			{
				if(timer==arrival[x] && timer !=0)
				{
							
					process_arrived[n++]=x+1;
					printf("process %d arrived\n",x+1);
				}	
			}
			bt=bt-1;
			timer=timer+1;
			if(bt==0)
			{
				printf("process %d completed\n",y );
				complete[y-1]=timer;
				i=i+1;
				timer=timer+2;
				burst[y-1]=20;
				//priority[0]=0;
				for(x=0;x<n;x++)
				{
					if(process_arrived[x]!=0)
					{
						process_arrived[x]=x+1+q;
					}
				}
				break;
			}
		}while(1);
		}
		else
		{
			int x;
			for(x=0;x<4;x++)
			{
				if(timer==arrival[x] && timer !=0)
				{
							
					process_arrived[n++]=x+1;
					printf("process %d arrived\n",x+1);
				}	
				else if(timer==arrival[x] && timer ==0)
				{
					arrival[x]=0;
					burst_time[x]=0;
					complete[x]=0;
					printf("process discarded\n");
					q=q+1;
				}
			}
			timer=timer+1;
		}
		if(i==4)
			break;

	}
	int turnaround_time[4]={0};
	int waiting_time[4]={0};
	for(i=0;i<4;i++)
	{
		turnaround_time[i]=complete[i]-arrival[i];
		waiting_time[i]=turnaround_time[i]-burst_time[i];
	}
	printf("process\tarrival_time\tburst_time\tturnaround_time\twaiting_time\n");
	for(i=0;i<4;i++)
	{
		printf("1\t%d\t\t%d\t\t%d\t\t%d\n",arrival[i],burst_time[i],turnaround_time[i],waiting_time[i]);
	}
	printf("average waiting time is %f .",(waiting_time[0]+waiting_time[1]+waiting_time[2]+waiting_time[3])/4.0);
	printf("average turnaround time is %f .",(turnaround_time[0]+turnaround_time[1]+turnaround_time[2]+turnaround_time[3])/4.0);
}


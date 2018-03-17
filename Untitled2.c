/*Consider a scheduling approach which is non pre-emptive similar to shortest job next in
nature. The priority of each job is dependent on its estimated run time, and also the amount of
time it has spent waiting. Jobs gain higher priority the longer they wait, which prevents indefinite
postponement. The jobs that have spent a long time waiting compete against those estimated to
have short run times. The priority can be computed as :
Priority = 1+ Waiting time / Estimated run time
Using the data given below compute the waiting time and turnaround time for each process and
average waiting time and average turnaround time.
Process 	Arrival time 	Burst time
P1 			0 				20
P2 			5 				36
P3 			13 				19
P4 			17 				42
*/

#include<stdio.h>

main()
{
	int i=0,bt=0,timer=0;;
int process[4]={1,2,3,4};
	int arrival[4]={0,5,13,17};
	int burst_time[4]={20,36,19,42};
	int burst[4]={20,36,19,42};
	int process_arrived[4]={1};
	double priority[4]={0};
	int complete[4]={0};
	while(1)
	{
		int p,q;
		for(p=0;p<4;p++)
		{
			for(q=0;q<4-1-p;q++)
			{
				if(priority[q]<priority[q+1] )
				{
					double t1=priority[q];
					priority[q]=priority[q+1];
					priority[q+1]=t1;
				}
			}
		}
		bt=burst[i];
		do
		{
			//printf("timer : %d",timer);
			int x;
			for(x=0;x<4;x++)
			{
				if(timer==arrival[x])
				{		
					process_arrived[x]=x+1;
					printf("process %d arrived\n",x);
				}	
			}
			bt=bt-1;
			timer=timer+1;
			if(bt==0)
			{
				printf("process %d completed\n",i);
				i=i+1;
				break;
			}
		}while(1);
		if(i==4)
			break;
	}
}

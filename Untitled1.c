/*
Consider a scheduler which schedules the job by considering the arrival time of the
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
#include<stdbool.h>
struct Processes
{
	int p_id;
	int b_time,ar_time;
};
int main()
{
	int no_of_processes;
	printf("\n How many processes you want to enter into the CPU ? \n");
	scanf("%d",&no_of_processes);
	struct Processes process[no_of_processes];
	int i=0;
	while(i<no_of_processes)
	{
		//system("cls");
		printf("\nEnter the process ID : ");
		scanf("%d",&process[i].p_id);
		printf("\nEnter the arrival time : ");
		scanf("%d",process[i].ar_time);
	}
}


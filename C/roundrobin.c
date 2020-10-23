#include <stdio.h>

int i, n, quantum; /* give a time quantum */

void read(int b[]) {
    for (i = 0; i < n; ++i) {
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &b[i]);
    }
}

void findWaitingtime(int b[], int wt[]) {
    int b_rem[20];
    for (i = 0; i < n; ++i) {
        b_rem[i] = b[i];                        /* Create a copy of the burst time array */
    }
    int time = 0;                               /* initialize time as 0 */

    while (1)
    {
        /* Traverse */

        int flag = 0;

        for (i = 0; i < n; ++i) {

            if (b_rem[i] > 0) {                 /* continue only if burst time is greater than 0 */
                flag = 1;                       /* there is a pending process */
                if (b_rem[i] > quantum) {
                    time += quantum;            /* shows how much time a process has been processed */
                    b_rem[i] -= quantum;        /* Decrease the burst_time of current process by quantum */
                }
                else {                          /* If burst time is smaller than or equal to quantum. Last cycle for this process  */
                    time += b_rem[i];           /* shows how much time a process has been processed */
                    wt[i] = time - b[i];        /* Waiting time is current time minus time used by this process  */
                    b_rem[i] = 0;               /* fully executed, so remaining burst time=0 */
                }
            }
        }
        if (flag == 0) {                        /* there is no pending process */
            break;
        }
    }
}

void findTurnAroundtime(int tat[], int b[], int wt[]) {
    for (i = 0; i < n; ++i) {
        tat[i] = b[i] + wt[i];
    }
}

void display(int b[], int wt[], int tat[]) {
    int wtSum = 0, tatSum = 0;
    printf("Process\tBurstTime WaitingTime  TurnAroundTime\n");
    for (i = 0; i < n; ++i) {
        wtSum += wt[i];
        tatSum += tat[i];
        printf("%d\t%d\t\t%d\t%d\n", i, b[i], wt[i], tat[i]);
    }
    printf("average waiting time: %f", (float)wtSum / n);
    printf("\naverage turnaround time: %f", (float)tatSum / n);
    printf("\n");
}

void calcTime(int b[], int wt[], int tat[]) {
    findWaitingtime(b, wt);
    findTurnAroundtime(tat, b, wt);
    display(b, wt, tat);
}

void main()
{
    int b[20], tat[20], wt[20];
    printf("Number of Processes:");
    scanf("%d", &n);
    read(b);
    printf("Enter time quantum:");
    scanf("%d", &quantum);
    calcTime(b, wt, tat);
}

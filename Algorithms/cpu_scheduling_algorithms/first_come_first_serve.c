#include <stdio.h>
#include <stdlib.h>

struct process
{
    int id;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnAroundTime;
    int waitingTime;
    int responseTime;
    int flag;
};

void showConclusions(struct process *ptr, int len);
void acceptProcessesData(struct process *ptr, int len);
void printPreTable(struct process *ptr, int len);
void printPostTable(struct process *ptr, int len);
void executeProcesses(struct process *processes, int numberOfProcesses);

int main(int argc, char const *argv[])
{

    // Accept number of processes from user.
    int numberOfProcesses;
    printf("\nPlease Enter number of processes: ");
    scanf("%d", &numberOfProcesses);

    // Dynamic allocation of memory for all processes using malloc().
    struct process *processes = (struct process *)malloc(sizeof(struct process) * numberOfProcesses);

    // Accept required data for each process.
    acceptProcessesData(processes, numberOfProcesses);

    // Display data of each process.
    printPreTable(processes, numberOfProcesses);

    // Execute process and apply algorithm
    executeProcesses(processes, numberOfProcesses);

    // Display the data after algorithm processing.
    printPostTable(processes, numberOfProcesses);

    // Display average turn around time and average waiting time
    showConclusions(processes, numberOfProcesses);

    // free-up memory;
    free(processes);
    return 0;
}

void showConclusions(struct process *ptr, int len)
{
    int tatSum = 0, waitingTimeSum = 0, scheduleLength, responseTimeSum = 0;
    float throughput, avgTAT, avgWT, avgRT;
    int highestCT = 0;
    int lowestAT = 32767;

    for (int i = 0; i < len; i++)
    {
        if (highestCT < (ptr + i)->completionTime)
        {
            highestCT = (ptr + i)->completionTime;
        }
        if (lowestAT > (ptr + i)->arrivalTime)
        {
            lowestAT = (ptr + i)->arrivalTime;
        }
        tatSum += (ptr + i)->turnAroundTime;
        waitingTimeSum += (ptr + i)->waitingTime;
        responseTimeSum += (ptr + i)->responseTime;
    }

    avgTAT = (float)tatSum / len;
    avgWT = (float)waitingTimeSum / len;
    avgRT = (float)responseTimeSum / len;
    scheduleLength = highestCT - lowestAT;
    throughput = (float)len / scheduleLength;

    printf("\n\nAverage turn around time = %.2f", avgTAT);
    printf("\n\nAverage waiting time = %.2f", avgWT);
    printf("\n\nAverage response time = %.2f", avgRT);
    printf("\n\nSchedule length = %d", scheduleLength);
    printf("\n\nThroughput = %.2f\n\n", throughput);
}

void acceptProcessesData(struct process *ptr, int len)
{
    for (int i = 0; i < len; i++)
    {
        (ptr + i)->id = i + 1;
        (ptr + i)->flag = 1;
        printf("\n\nEnter arrival time for process number %d: ", (ptr + i)->id);
        scanf("%d", &(ptr + i)->arrivalTime);
        printf("\nEnter burst time for process number %d: ", (ptr + i)->id);
        scanf("%d", &(ptr + i)->burstTime);
    }
}

void printPreTable(struct process *ptr, int len)
{
    printf("\n\nProcesses before execution\n");
    printf("\n\n|-----------------------------------------------|");
    // Display data of each process
    printf("\n|\tPid\t|\tAT\t|\tBT\t|");
    printf("\n|-----------------------------------------------|");
    for (int i = 0; i < len; i++)
    {
        printf("\n|\t%d\t|\t%d\t|\t%d\t|", (ptr + i)->id, (ptr + i)->arrivalTime, (ptr + i)->burstTime);
    }
    printf("\n|-----------------------------------------------|\n");
}
void printPostTable(struct process *ptr, int len)
{
    printf("\n\nProcesses after execution\n");
    printf("\n\n|---------------------------------------------------------------------------------------------------------------|");
    // Display data of each process
    printf("\n|\tPid\t|\tAT\t|\tBT\t|\tCT\t|\tTAT\t|\tWT\t|\tRT\t|");
    printf("\n|---------------------------------------------------------------------------------------------------------------|");
    for (int i = 0; i < len; i++)
    {
        printf("\n|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|", (ptr + i)->id, (ptr + i)->arrivalTime, (ptr + i)->burstTime, (ptr + i)->completionTime, (ptr + i)->turnAroundTime, (ptr + i)->waitingTime, (ptr + i)->responseTime);
    }
    printf("\n|---------------------------------------------------------------------------------------------------------------|\n");
}

void executeProcesses(struct process *processes, int numberOfProcesses)
{
    int completeCounter = 0;
    int loopFlag = 1;
    int presentTime = 0;
    // Real algorithm logic
    while (loopFlag)
    {
        // PTincrement stand for "Present time increment". By default it is "1" but if a process is scheduled then,
        // PTincrement's value is changed to be equal to "burst time" of the process.
        // After each iteration "PTincrement" is added to "presentTime".
        int PTincrement = 1;
        int minATIndex = 0;

        // Here in this loop, we are making sure that the "minATIndex" is assigned properly.
        for (int i = 0; i < numberOfProcesses; i += 1)
        {
            if ((processes + i)->flag == 1)
            {
                minATIndex = i;
                break;
            }
        }

        // Iterate, check if the condition is satisfied and assign.
        for (int i = numberOfProcesses - 1; i >= 0; i -= 1)
        {
            int AT = (processes + i)->arrivalTime;
            int minAT = (processes + minATIndex)->arrivalTime;

            // making sure that the process is available. (using flag value)
            if (AT <= minAT && (processes + i)->flag == 1)
            {
                minATIndex = i;
            }
        }

        // check if the process with minimum burst time is arrived or not and assign flag accordingly.
        if ((processes + minATIndex)->arrivalTime <= presentTime)
        {
            PTincrement = (processes + minATIndex)->burstTime;
            (processes + minATIndex)->completionTime = presentTime + PTincrement;

            int turnAroundTime = (processes + minATIndex)->completionTime - (processes + minATIndex)->arrivalTime;
            int waitingTime = turnAroundTime - PTincrement;

            (processes + minATIndex)->turnAroundTime = turnAroundTime;
            (processes + minATIndex)->waitingTime = waitingTime;
            (processes + minATIndex)->responseTime = waitingTime;
            (processes + minATIndex)->flag = 0;

            completeCounter += 1;
        }

        // Incrementing present time.
        presentTime += PTincrement;

        // Incrementing counter which has count of executed processes.
        if (completeCounter == numberOfProcesses)
            loopFlag = 0;
    }
}

/*
(base) abhishek@Abhisheks-MacBook-Pro os-udemy % gcc fcfs.c
(base) abhishek@Abhisheks-MacBook-Pro os-udemy % ./a.out   

Please Enter number of processes: 6


Enter arrival time for process number 1: 0

Enter burst time for process number 1: 3


Enter arrival time for process number 2: 1

Enter burst time for process number 2: 2


Enter arrival time for process number 3: 2

Enter burst time for process number 3: 1


Enter arrival time for process number 4: 3

Enter burst time for process number 4: 4


Enter arrival time for process number 5: 4

Enter burst time for process number 5: 5


Enter arrival time for process number 6: 5

Enter burst time for process number 6: 2


Processes before execution


|-----------------------------------------------|
|       Pid     |       AT      |       BT      |
|-----------------------------------------------|
|       1       |       0       |       3       |
|       2       |       1       |       2       |
|       3       |       2       |       1       |
|       4       |       3       |       4       |
|       5       |       4       |       5       |
|       6       |       5       |       2       |
|-----------------------------------------------|


Processes after execution


|---------------------------------------------------------------------------------------------------------------|
|       Pid     |       AT      |       BT      |       CT      |       TAT     |       WT      |       RT      |
|---------------------------------------------------------------------------------------------------------------|
|       1       |       0       |       3       |       3       |       3       |       0       |       0       |
|       2       |       1       |       2       |       5       |       4       |       2       |       2       |
|       3       |       2       |       1       |       6       |       4       |       3       |       3       |
|       4       |       3       |       4       |       10      |       7       |       3       |       3       |
|       5       |       4       |       5       |       15      |       11      |       6       |       6       |
|       6       |       5       |       2       |       17      |       12      |       10      |       10      |
|---------------------------------------------------------------------------------------------------------------|


Average turn around time = 6.83

Average waiting time = 4.00

Average response time = 4.00

Shedule length = 17

Throughput = 0.35

(base) abhishek@Abhisheks-MacBook-Pro os-udemy %   
*/

/*
6
0
3
1
2
2
1
3
4
4
5
5
2
*/

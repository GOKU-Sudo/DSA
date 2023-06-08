//Name-PURSHOTAM SINGH
//Roll-RK21MRA20
//Reg-12114465
//Sec-K21MR

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_PROCESSES 10      // Maximum number of processes
#define QUANTUM_TIME 5        // Quantum time in n seconds
#define MAX_CPU_BURST_TIME 50 // Maximum CPU burst time for a process
#define SIMULATION_TIME 100   // Total simulation time in time units

// Process structure
typedef struct Process
{
      int arrival_time;    // Arrival time of the process
      int cpu_burst_time;  // CPU burst time of the process
      int remaining_time;  // Remaining CPU burst time of the process
      int waiting_time;    // Waiting time of the process
      int turnaround_time; // Turnaround time of the process
} Process;

// Function to generate random arrival time for a process
int generate_arrival_time()
{
      return rand() % (SIMULATION_TIME + 1); // Random arrival time between 0 and SIMULATION_TIME
}

// Function to generate random CPU burst time for a process
int generate_cpu_burst_time()
{
      return rand() % (MAX_CPU_BURST_TIME + 1); // Random CPU burst time between 0 and MAX_CPU_BURST_TIME
}

int main()
{
      srand(time(0)); // Seed the random number generator with current time

      int num_processes;                // Number of processes
      Process processes[MAX_PROCESSES]; // Array of processes
      int time = 0;                     // Current time
      int quantum_time = QUANTUM_TIME;  // Quantum time

      printf("Enter the number of processes (1 -to- %d): ", MAX_PROCESSES);
      scanf("%d", &num_processes);

      if(num_processes>10){
            printf("Please enter in range 1-10");
            return 0;
      }

      // Generate processes with random arrival times and CPU burst times
      for (int i = 0; i < num_processes; i++)
      {
            processes[i].arrival_time = generate_arrival_time();
            processes[i].cpu_burst_time = generate_cpu_burst_time();
            processes[i].remaining_time = processes[i].cpu_burst_time;
            processes[i].waiting_time = 0;
            processes[i].turnaround_time = 0;
      }

      // Round Robin scheduling
      while (time < SIMULATION_TIME)
      {
            bool all_processes_completed = true; // Flag to check if all processes are completed

            for (int i = 0; i < num_processes; i++)
            {
                  if (processes[i].remaining_time > 0)
                  {
                        all_processes_completed = false;

                        // Execute the process for quantum time or remaining time, whichever is smaller
                        int execution_time = quantum_time < processes[i].remaining_time ? quantum_time : processes[i].remaining_time;
                        time += execution_time;
                        processes[i].remaining_time -= execution_time;

                        // Update waiting time for other processes
                        for (int j = 0; j < num_processes; j++)
                        {
                              if (j != i && processes[j].arrival_time <= time && processes[j].remaining_time > 0)
                              {
                                    processes[j].waiting_time += execution_time;
                              }
                        }
                  }
            }

            // If all processes are completed, exit the loop
            if (all_processes_completed)
            {
                  break;
            }
      }

      // Calculate average waiting time and turnaround time for each process
      int total_waiting_time = 0;
      int total_turnaround_time = 0;
      printf("\nProcess\tArrival Time\tCPU Burst Time\tWaiting Time\tTurnaround Time\n");
      for (int i = 0; i < num_processes; i++)
      {
            processes[i].turnaround_time = processes[i].waiting_time + processes[i].cpu_burst_time;
            total_waiting_time += processes[i].waiting_time;
            total_turnaround_time += processes[i].turnaround_time;
            printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, processes[i].arrival_time, processes[i].cpu_burst_time,
                   processes[i].waiting_time, processes[i].turnaround_time);
      }
      // Calculate average waiting time and turnaround time
      float avg_waiting_time = (float)total_waiting_time / num_processes;
      float avg_turnaround_time = (float)total_turnaround_time / num_processes;

      printf("\nAverage Waiting Time: %.2f time units\n", avg_waiting_time);
      printf("Average Turnaround Time: %.2f time units\n", avg_turnaround_time);

      return 0;
}

/*
   Round Robin CPU Algorithm generally focuses on Time Sharing technique.
   The period of time for which a process or job is allowed to run in a pre-emptive method is called time quantum.
   Each process or job present in the ready queue is assigned the CPU for that time quantum, if the execution of
   the process is completed during that time then the process will end else the process will go back to the waiting table and wait for its next turn to complete the execution.

   Explanation of above RR Scheduling:-

   -> Maximum number of processes that cane be entered by a user is set to 10 so as to make it simple.
   -> Quantum time is 5, Maximum cpu burst time is set to 50 so as no process take loner time to execute.
   -> Simulation time is 100.(given in question).

   @PROCESS STRUCTURE
   A structure named process is created which contains the properties of process created.
   arrival time, cpu burst time, remaining time, waiting time and turnaround time.
   Whenever the process is created, these properties are inherited by the process.

   @GENERATE ARRIVAL TIME
   generate_arrival_time() function creates random arrival time for process using rand() inbuilt function.
   Then after they arrive at ready queue.

   @GENERATE CPU BURST TIME
   generate_cpu_burst_time() function creates random cpu burst time for process using rand() inbuilt function.
   
   @MAIN FUNCTION
   Main function contains the variables like number of processes, array for storing processses,time and quantum time.
   User is asked to create the number processes. A loop runs over the number of processes entered by user and randomly generated
   arrival time and cpu burst time are assigned to the process by their respective functions.

   Further down Round Robin Scheduling is implemented using the while loop.
   A boolean is created to check that all the processes are created and completed successfully.
   Again a for loop is used over the number of processes to use the algorithm of Round Robin Scheduling.

   After that we calculate the waiting time and turnaround time for each process. We display the waiting and turnaround time of
   each process in tabular form.
   Following the individual waiting and turnaround time, we calculate and display the average waiting and turnaround time.
   
   @COMPARISON WITH SCHEDULING ALGORITHMS
   FCFS(First Come First Service) is the simplest scheduling alorithm which is no-preemptive. It is easy to implement.
   But it has a drawback, since it follow First Come First Service, it can cause short processes to wait very long in the
   ready queue. It has large waiting for processes as well as average waiting time is long too.

   SJF(Shortest Job First) is a improvement of FCFS. It is of two type non-preemptive and preemptive. In non-preemptive the process
   holds the resources till it reaches waiting state or terminated.
   SJF is probably optimal, providing the shortest average waiting time. Implementing SJF scheduling is difficult, however, because 
   predicting the length of the next CPU burst is difficult. Furthermore, processes that have long running times may starve under SJF,
   if there are too many short ones.

   RR(Round Robin) Scheduling offers fairness solution, providing better average response time. That typically comes at the cost of a
   higher average turnaround time though. At one extreme, if the time quantum is extremely large, the
   RR policy is the same as the FCFS policy. In contrast, if the time quantum is extremely small (say, 1 millisecond), the RR approach
   can result in a large number of context switches.


*/

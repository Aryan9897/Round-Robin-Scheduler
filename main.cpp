#include <iostream>
#include "process.h"
#include "scheduler.h"
using namespace std;

int main() {
    int numProcesses;
    double quantumTime;
    double contextSwitchTime;
    
    //Ask the user for information
    cout << "Enter number of processes: ";
    cin >> numProcesses;

    cout << "Enter quantum time: ";
    cin >> quantumTime;

    cout << "Enter context switch time: ";
    cin >> contextSwitchTime;

    //Create a roundRobinScheduler object
    Scheduler roundRobinScheduler(quantumTime, contextSwitchTime);

    //Run for the number of processes entered above
    for (int i = 0; i < numProcesses; i++)
    {
        int processID;
        double arrivalTime;
        double burstTime;

        cout << "Enter process ID, arrival time, and burst time for process " << i + 1 << ": ";
        cin >> processID >> arrivalTime >> burstTime;

        Process* process = new Process(processID, arrivalTime, burstTime);
        roundRobinScheduler.newProcess(process);
    }

    roundRobinScheduler.roundRobin();
    roundRobinScheduler.finalResult();

    return 0;
}
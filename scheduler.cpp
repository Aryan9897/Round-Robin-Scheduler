#include <iostream>
#include <iomanip>
#include <algorithm>
#include "scheduler.h"
#include "process.h"

using namespace std;

//Constructor initialization
Scheduler::Scheduler(double qTime, double cSwitch) {
    quantumTime = qTime;
    contextSwitchTime = cSwitch;

    currentTime = 0;
}

//Destructors to free up memory after the program is complete
Scheduler::~Scheduler() {
    for (int i = 0; i < processList.size(); i++) 
    {
        delete processList[i];
    }
    
    processList.clear();
}

//Function initializations
bool Scheduler::isInQueue(Process* process) {
    queue<Process*> temp = processQueue;
    while (!temp.empty())
    {
        if (temp.front() == process)
        {
            return true;
        }

        temp.pop();
    }

    return false;
}

bool Scheduler::isPending() {
    for (int i = 0; i < processList.size(); i++)
    {
        if (processList[i]->getRemainingTime() > 0)
        {
            return true;
        }
    }

    return false;
}

bool Scheduler::compareByArrival(Process* a, Process* b) {
    return a->getArrivalTime() < b->getArrivalTime();
}

void Scheduler::newProcess(Process* newProc) {
    processList.push_back(newProc);
}

void Scheduler::roundRobin() {
    //Sort the list first so that the processes are sorted in arrival time
    sort(processList.begin(), processList.end(), Scheduler::compareByArrival);

    //Keep running the scheduler until the queue is empty or nothing is pending
    while (!processQueue.empty() || isPending())
    {
        for (int i = 0; i < processList.size(); i++)
        {
            if (processList[i]->getArrivalTime() <= currentTime && processList[i]->getRemainingTime() > 0 && !isInQueue(processList[i]))
            {
                processQueue.push(processList[i]);
            }
        }

        if (!processQueue.empty())
        {
            Process* currProcess = processQueue.front();

            //Set waiting time to the first value of time it is processed at
            if (!currProcess->getFlagVal())
            {
                currProcess->setWaitingTime(currentTime - currProcess->getArrivalTime());
                currProcess->setFlagVal(true);
            }

            //Reduce the burst time by the quantum time. Also check if any new processes have been added to the list before pushing the process back into the queue
            if (currProcess->getRemainingTime() > quantumTime)
            {
                currProcess->setRemainingTime(currProcess->getRemainingTime() - quantumTime);
                currentTime += quantumTime;

                for (int i = 0; i < processList.size(); i++)
                {
                    if (processList[i]->getArrivalTime() <= currentTime && processList[i]->getRemainingTime() > 0 && !isInQueue(processList[i]))
                    {
                        processQueue.push(processList[i]);
                    }
                }

                processQueue.push(currProcess);
            }

            //If process is complete, set its time to 0 so that it doesn't get added in the queue again
            else
            {
                currentTime += currProcess->getRemainingTime();
                currProcess->setCompletionTime(currentTime);
                currProcess->setRemainingTime(0);
            }

            processQueue.pop();
            currentTime += contextSwitchTime;
        }

        else
        {
            currentTime++;
        }
    }

    //Set the turn around times
    for (int i = 0; i < processList.size(); i++)
    {
        processList[i]->setTurnAroundTime(processList[i]->getCompletionTime() - processList[i]->getArrivalTime());
    }
}

//Function to display the final outcome
void Scheduler::finalResult() {
    cout << endl;
    cout << left << setw(15) << "Process ID"
    << setw(15) << "Arrival Time"
    << setw(15) << "Burst Time"
    << setw(20) << "Completion Time"
    << setw(20) << "Turnaround Time"
    << setw(20) << "Waiting Time" << endl;

    cout << string(100, '-') << endl;

    double totalTurnAroundTime = 0;
    double totalWaitingTime = 0;

    for (int i = 0; i < processList.size(); i++)
    {
        cout << left << setw(15) << processList[i]->getProcessID()
        << setw(15) << processList[i]->getArrivalTime()
        << setw(15) << processList[i]->getBurstTime()
        << setw(20) << processList[i]->getCompletionTime()
        << setw(20) << processList[i]->getTurnAroundTime()
        << setw(20) << processList[i]->getWaitingTime() << endl;

        totalTurnAroundTime += processList[i]->getTurnAroundTime();
        totalWaitingTime += processList[i]->getWaitingTime();
    }

    cout << string(100, '-') << endl << endl;
    cout << "Average Turnaround Time: " << totalTurnAroundTime / processList.size() << endl;

    cout << "Average Waiting Time: " << totalWaitingTime / processList.size() << endl << endl;
}
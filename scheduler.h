#include <iostream>
#include <vector>
#include <queue>
#include "process.h"
using namespace std;

#pragma once

class Scheduler {
private:
    queue<Process*> processQueue;
    vector<Process*> processList;
    double quantumTime;
    double contextSwitchTime;
    double currentTime;

    bool isInQueue(Process* process);
    bool isPending();

public:
    //Constructor
    Scheduler(double qTime, double cSwitch);
    ~Scheduler();

    static bool compareByArrival(Process* a, Process* b);
    void newProcess(Process* newProc);
    void roundRobin();
    void finalResult();
};
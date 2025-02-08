#include <iostream>
using namespace std;

#pragma once

class Process {
private:
    int processID;
    double arrivalTime;
    double burstTime;
    double remainingTime;
    double completionTime;
    double turnAroundTime;
    double waitingTime;
    bool flagVal;

public:
    //Constructor
    Process(int id, double arrival, double burst);

    //Getter functions for all variables
    int getProcessID() const;
    double getArrivalTime() const;
    double getBurstTime() const;
    double getRemainingTime() const;
    double getCompletionTime() const;
    double getTurnAroundTime() const;
    double getWaitingTime() const;
    bool getFlagVal() const;
    
    //Setter functions for all variables
    void setRemainingTime(double time);
    void setCompletionTime(double time);
    void setTurnAroundTime(double time);
    void setWaitingTime(double time);
    void setFlagVal(bool flag);
};
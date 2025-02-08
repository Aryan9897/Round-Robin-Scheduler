#include <iostream>
#include "process.h"

using namespace std;

Process::Process(int id, double arrival, double burst) {
    processID = id;
    arrivalTime = arrival; 
    burstTime = burst;
    
    remainingTime = burst;
    completionTime = 0;
    turnAroundTime = 0;
    waitingTime = 0;
    flagVal = false;
}

//Getter functions implementation
int Process::getProcessID() const {
    return processID;
}

double Process::getArrivalTime() const {
    return arrivalTime;
}

double Process::getBurstTime() const {
    return burstTime;
}

double Process::getRemainingTime() const {
    return remainingTime;
}

double Process::getCompletionTime() const {
    return completionTime;
}

double Process::getTurnAroundTime() const {
    return turnAroundTime;
}

double Process::getWaitingTime() const {
    return waitingTime;
}

bool Process::getFlagVal() const {
    return flagVal;
}

//Setter functions implementation
void Process::setRemainingTime(double time) {
    remainingTime = time;
}

void Process::setCompletionTime(double time) {
    completionTime = time;
}

void Process::setTurnAroundTime(double time) {
    turnAroundTime = time;
}

void Process::setWaitingTime(double time) {
    waitingTime = time;
}

void Process::setFlagVal(bool flag) {
    flagVal = flag;
}
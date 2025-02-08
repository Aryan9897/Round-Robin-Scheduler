### INSTRUCTIONS ON HOW TO EXECUTE THE PROGRAM ###

This program is a Round Robin Scheduler.

To run this program, you need to use the command "g++ main.cpp process.cpp scheduler.cpp -o main.out".

The above mentioned command creates a main.out file which can be run using the command "./main.out"


### HOW THE PROGRAM WORKS ###

1) Once you run the command "./main.out", the program will ask you to enter the number of processes.
2) After you enter the number of processes, the program asks for the quantum time
3) After the quantum time, the program asks for the context switch time. If you don't have a context switch time, you can enter 0.
4) Based on the number of processes you entered, the program will then ask you to enter the process ID, the arrival time, and the burst time of all the processes.
5) After you enter everything, the program will then provide a table with the process ID, the arrival time, the burst time, the completion time, the turnaround time, and the waiting time of all the processes. At the end, there will also be the average turnaround time and the average wait time. The order in which the processes are listed would be based on arrival time.


### IMPORTANT NOTES ###
Make sure to enter data correctly, otherwise the program might not run or give unexpected results. Only enter integer or double values.


### ABOUT THE PROGRAM ###

The program contains 5 files. The files and the information about them is listed below.

1) main.cpp
This is the main file that uses all the other files. It contains integers and double variables to function as inputs for the user and then taken as arguments for class object initalization. The file contains code that asks the user for the number of processes, the quantum time, and the arrival time. Based on this information, a scheduler object is created with the quantum time and the arrival time. It then has a for loop that runs for the number of processes the user entered. The loop asks the process ID, the arrival time, and the burst time for each process, which is used to initialize a process class object. The file then calls the main round robin algorithm and then the final results function to display the final outcome.


2) process.h
This is the header file for the process.cpp file. It contains private variables for each process that is created, including the process ID, arrival time, burst time, completion time, waiting time, turn around time, etc. The public section contains the declarations of the getter and setter functions for each of the private variables as well as the constructor.


3) process.cpp
This file contains the initializations of all the getter and setter functions as well as the initialization of the constructor.


4) scheduler.h
This file is the header file for the scheduler.cpp file. It includes the header for the process.h class file as well in order to declare a vector of the process type class and a queue of the process type class as well. Further, the private section also contains the variables for the quantum time, the context switch time, and the current time and two functions. The first function checks to see if there is a process in the queue, and the second function checks to see if any function is pending. The public section contains the constructor, the destructor, and a few function declarations. The functions are a static bool function for comparison, a function to add a new process to the processList, a function that has the main round robin algorithm, and a function to display the final results.


5) scheduler.cpp
This file contains the bulk of the code. It first initailizes the contructor with the quantum and the context switch time, and initializes the currentTime to be 0. It also contains the destructor to clear out the dynamically allocated memory. It further contains the function initializations. The first function initialized is the is in queue function, which basically checks to see whether a function is already in the queue so as to not add it again. The next function is the isPending function, which basically checks to see if the remaining time of any function is greater than 0. The third function is the compareByArrival function, which is used to sort out the list of all processes based on the arrival time. The next function is the newProcess function, which adds the process to the process list.

The next function is the main function, which is the roundRobin function. The function first sorts the list so that the processes are arranged based on arrival time. This is essential to maintain the correct order of the ready queue of processes. The function then has a while loop that keeps running until the queue is empty or if any process is pending, meaning the remaining time of any process is greater than 0. Inside the while loop, we first have a for loop that checks to see if any process is in the process list that has an arrival time less than the current time. This for loop checks every time a process has had its turn to make sure that the processes are added to the queue in the correct order. The next part of the while loop is for updating the remaining time of the processes. It takes the process that is at the front of the queue and first updates the waiting time to the first time the process is processed. It then checks to see if the remaining time of the process is greater than the quantum time, in which case it reduces the remaining time by the quantum time and updates the current time by adding the quantum time to it. Before adding the process back to the queue, another for loop is there to check if any processes have an arrival time less than the updated current time, and if so, they are added to the queue before the current process is added back to the queue. In case the current process' remaining time is less than the quantum time, the remaining time is set to 0 and the remaining time is added to the current time. The completion time of that process is also set to the current time. The process is then popped from the list and the context switch time, if any, is added to the current time. In case no process is ready, the current time is incremented by 1.

The next function is the final display function, which has the tabular format to display the process id, arrival time, burst time, completion time, turn around time, and waiting time for each process. It also contains the calculations for the average turn around time and average waiting time. 
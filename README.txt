=============================================================================
Name        : PA5.c
Author      : Yu-sen Wu Dominic Chang
Version     :
Copyright   :
Description : A class of Rational numbers and a test program on 		operators overloaded in the class
=============================================================================
=============================================================================
					Abstract
=============================================================================
Here are the results form an example simulation

Bank Simulation for one line per teller
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Number of tellers: 5
Number of customers: 50
Minutes that bank was opened for: 120
The average service time for a teller 2.7398
Average customer visit time: 4.34524
The standard deviation for customer visit time: 1.86481
The total time spent servicing customers: 136.99
The total time spent idle by tellers: 467.325
The maximum time spent waiting by a customer: 4.6317


Bank Simulation for one line for all tellers
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
Number of tellers: 5
Number of customers: 50
Minutes that bank was opened for: 120
The average service time for a teller 2.3268
Average customer visit time: 3.65485
The standard deviation for customer visit time: 1.59972
The total time spent servicing customers: 116.34
The total time spent idle by tellers: 486.799
The maximum time spent waiting by a customer: 3.64953
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

It was found that for a oneline per teller event, the maximum time waited by customers was
higher than the alternative, however, it was also found that tellers would spend more time idling.
Since the average service time was the same in both cases, we conclude that the average visit time
for customers in a bank with oneline per teller would be longer than the alternative.
=============================================================================
					PA5
=============================================================================
The user provides the program with arguments:
inputs: one or more text file inputs

=============================================================================
					How To Run
=============================================================================

1. Open terminal
2. Run make
3. Execute with ./qSim numberOfCustomers numberOfTellers SimulationTime averageServiceTime <seed>
4. The program will print statitcs for 2 different que types. One with one line for all tellers, 
and another with one line for each teller into standard out.

** Limitations for memory is defined in wordparse.h
*
*
** These can be changed according to specs.

=============================================================================
					How It Works
=============================================================================
1) Teller and customer events are made at the begining. The Teller events are initially idle with times
all set to 0. The customer event times are set to a random number between 0 and the simulation time.
2) All the events enter the eventque by time order and perform an action when they are poped from the que 
which updates the state and/or pushes an event to the que.
3) Customers that are popped from the que join a tellerline which sets the teller to not idle once the teller
has finished his/her last task.
4) When the customer is served, the Customer even is deleted and the teller performs a new task.
5) Tellers can service customers after closing time, but will not push a new event after closing time.
6)Once the simulation ends all objects are deleted and statistics are printed to standard out for a bank with
one line for all tellers.
7) The simulation is repeated for a bank with one line per teller.
=============================================================================
					SortedList
=============================================================================
Events are sorted by time once they are pushed to the list. Each event in the list points to the 
next event in the list. The SortedList class has a root pointer which points to the Event with the 
shortest time in the list. The SortedList stores information on it's length and allows for poping
and pushing to the list.

=============================================================================
					EventQueue
=============================================================================
EventQueue implements priority_queue. to store Event pointers. the implementation of 
EventQue is identical to SortedList with the exception that instead of a root pointer
to Events, there is a priority_que of pointers to events.


=============================================================================
References
=============================================================================
1) http://stdcxx.apache.org/doc/stdlibug/11-3.html
Gave motivation for the use of a simulation whih controls the simulation.




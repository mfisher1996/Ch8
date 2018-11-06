
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <queue>

#include "simulation.h"
#include "simulationImp.cpp"
#include "queueAsArray.h"

using namespace std;

void setSimulationParameters(int& sTime, int& numOfServers,
                             int& transTime,
                             int& tBetweenCArrival);

void runSimulation();
void updateWaitingQueue(queue<customerType>&);

int main()
{

    runSimulation();
    cout<< endl << endl;

    return 0;
}

void setSimulationParameters(int& sTime, int& numOfServers,
							 int& transTime,
							 int& tBetweenCArrival)
{
    cout << "Enter the simulation time: ";
    cin >> sTime;
    cout << endl;

    cout << "Enter the number of servers: ";
    cin >> numOfServers;
    cout << endl;

    cout << "Enter the transaction time: ";
    cin >> transTime;
    cout << endl;

    cout << "Enter the time between customer arrivals: ";
    cin >> tBetweenCArrival;
    cout << endl;

    cout<< "\n************************************************" << endl;
    cout<< endl;
}
void updateWaitingQueue(queue<customerType> & queue){
    
    customerType cust;
    
    cust.setWaitingTime(-1);
    int wTime = 0;
    
    queue.push(cust);
    
    while (wTime != -1)
    {
        cust = queue.front();
        queue.pop();
        
        wTime = cust.getWaitingTime();
        if (wTime == -1)
            break;
        cust.incrementWaitingTime();
        queue.push(cust);
    }

}

void runSimulation()
{

    int sTime; //Total simulation time.
    int numOfServers; //Number of servers.
    int transTime; //Time it takes for 1 transaction to occur.
    int tBetweenCArrival; //The time interval a customer may enter the line.

    int customerNumber = 1; //1st customer will start as customer number 1.
    int totalWaitingTime = 0; //The total waiting time of all customers.
    float averageWaitingTime = 0;
    int numOfCustomersServed = 0; //Number of customers who have
                                //successfully completed transactions.
    int numOfCustomersLeftInQueue = 0; //Number of customers who have yet
                                        //to see a server.

    float e = 2.718; //euler's number.
    float customerCutOffProbability;

    float rNum;

    customerType frontCustomer; //Customer at the beginning of the line.
    queue<customerType> customerQueue; //Line of customers
    customerType customer;

    unsigned seed = time(0);
    srand(seed);


    //Get user-inputted simulation time, number of servers,
    //the time a transaction takes, and the time between possible
    //arrival of customers. (1 customer possible per user-inputted time).
    setSimulationParameters(sTime, numOfServers,
                            transTime, tBetweenCArrival);

    //Create serverList object holding a user-inputted number of servers
    serverListType serverList(numOfServers);


    //The book says a customer should arrive in-line only if
    //a generated random number is greater than e^-(userInput).
    customerCutOffProbability = pow(e, -(1.0/tBetweenCArrival));

    //This for-loop represents the passage of time.
    for(int clock = 1; clock <= sTime; clock++)
    {
        //If a customer is with a server, that transaction time
        //between the customer and server, which starts at a user-defined time,
        //is decremented by 1. So each iteration of the for-loop,
        //if a customer is with a server, 1 minute worth of transaction time passes.
        //If the transaction time becomes 0, that means that the transaction is finished,
        //the customer leaves, and the server that was with that customer becomes available
        //for another customer.
        serverList.updateServers(cout);


        if(!customerQueue.empty()) //Just for the first loop.
        {                                  //Will constantly get populated
                                          //with -1's, so it will never actually be
                                          //empty besides for the first loop.
            frontCustomer = customerQueue.front();

            if(frontCustomer.getWaitingTime() != -1) //If queue is non-empty.
            {
                updateWaitingQueue(customerQueue); //Each customer object in the queue
            }                                       //has their waiting time increased by 1.
        }

        rNum = rand() % 2; //To get a random number of 1 or 0.

        if(rNum > customerCutOffProbability) //If a customer arrives
        {                                   //(Will happen if rNum = 1).
             cout<< "\nCustomer number " << customerNumber
                 << " arrived at time unit " << clock << endl;

            //That customer gets a number designated to him/her,
            //and holds the time he/she arrived. Starts with a waiting
            //time of 0, and holds a transaction time or 5 that will be
            //decremented in serverList's updateServers() function.
            customer.setCustomerInfo(customerNumber, clock, 0, transTime);

            //Add this customer who just arrived to th queue.
            customerQueue.push(customer);

            //starts at customer #1, then #2, etc.
            customerNumber = customerNumber + 1;
        }

        if(!customerQueue.empty())//Just for the first loop.
        {
            //If a server is free and customer queue is non-empty
            if(serverList.getFreeServerID() != -1 && customerQueue.front().getWaitingTime() != -1)
            {
                //A server becomes busy with the customer.
                serverList.setServerBusy(serverList.getFreeServerID(), customerQueue.front(), transTime);

                //That customer's time waiting in line is accumulated with every other customer's
                //time waiting in line. At this point, does not take into account the customers
                //who will not see a server before time runs out.
                totalWaitingTime =  totalWaitingTime + customerQueue.front().getWaitingTime();

                customerQueue.pop(); //Remove the customer at the front of the line from the queue.


            }
        }

    }


    if(!customerQueue.empty()) //Probably don't need this if statement, but oh well.
    {
        frontCustomer = customerQueue.front();

        if(frontCustomer.getWaitingTime() != -1) //If queue is non-empty.
        {
            //Increment all customers' waiting times by 1 that are still in the queue.
            //Need to do this because when we exit the for loop,
            //each customer's waiting time (in the queue) is 1 behind where it actually
            //should be.
            updateWaitingQueue(customerQueue);
        }
    }


    while(!customerQueue.empty()) //Go through the entirety of the queue.
    {
        if(customerQueue.front().getWaitingTime() != -1) //If we're not at a dummy customer.
        {
            //get the waiting times of customers who never got to see a server within the
            //allotted simulation time.
            totalWaitingTime =  totalWaitingTime + customerQueue.front().getWaitingTime();


            numOfCustomersLeftInQueue++;

        }
        customerQueue.pop(); //Delete dat customer.
    }

    //1.0 used to bypass integer division.
    //customerNumber will be 1 greater then the actual number of customers
    //at this point, so customerNumber-1 is accurate.
    averageWaitingTime = 1.0 * totalWaitingTime / (customerNumber-1);

    cout<< "\n\n************************************************" << endl;
    cout<< "\nThe Simulation ran for " << sTime << " time units" << endl;
    cout<< "Number of servers: " << numOfServers << endl;
    cout<< "Average transaction time: " << transTime << endl;
    cout<< "Average arrival time between customers: " << tBetweenCArrival << endl;
    cout<< "Total waiting time: " << totalWaitingTime << endl;
    cout<< "Number of customers that completed a transaction: " << serverList.getNumOfCustomersServed() << endl;
    cout<< "Number of customers left in the servers: " << serverList.getNumberOfBusyServers() << endl;
    cout<< "The number of customers left in the queue: " << numOfCustomersLeftInQueue << endl;
    cout<< "Average waiting time: " << setprecision(3) << averageWaitingTime << endl << endl;
    cout<< "*************** END SIMULATION *****************" << endl;
}


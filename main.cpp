#include <iostream>
#include <list>
#include "process.h"

/*
 * Created by Nicholas Chao
 */


using namespace std;

int main()
{
    std::list<process> rqueue;  //ready queue
    std::list<process> wqueue;  //waiting queue
    int pidcount = 1;

    int input = 0;
    while(input == 0)
    {
        cout << "What do you want to do?" << endl;
        cout << "1: Add a PCB" << endl;
        cout << "2: Print Ready Queue" << endl;
        cout << "3: Print Waiting Queue" << endl;
        cout << "4: Delete a PCB (Given a Pid)" << endl;
        cin >> input;

        if (input == 1) // Add a PCB (1)
        {
            int pid = pidcount;
            pidcount = pidcount +1;
            string name;
            string desc;
            cout << "Enter the name of the Process" << endl;
            cin >> name;
            cout << "Enter the description of the Process:" << endl;
            cin >> desc;

            process PCB = process(pid, name, desc);
            cout << "The Process you have created:" << endl;
            PCB.printPCB();
            cout << "Which queue do you want to add it to?" << endl;
            cout << "1: Ready Queue" << endl;
            cout << "2: Waiting Queue" << endl;
            cin >> input;
            while((input != 1) && (input != 2)) // Bad input
            {
                cout << "Invalid input" << endl;
                cout << "Which queue do you want to add it to?" << endl;
                cout << "1: Ready Queue" << endl;
                cout << "2: Waiting Queue" << endl;
                cin >> input;
            }
            if(input == 1) //Ready Queue
            {
                PCB.changeState("ready");
                rqueue.push_back(PCB);
            }
            if(input == 2) //Waiting Queue
            {
                PCB.changeState("waiting");
                wqueue.push_back(PCB);
            }
            input = 0;
        }
        else if(input == 2) //Print Ready Queue (2)
        {
            cout << "The ready queue contains: " << endl;
            for (std::list<process>::iterator it=rqueue.begin(); it != rqueue.end(); ++it)
            {
                process pcb = *it;
                pcb.printPCB();
            }
            input = 0;
        }
        else if (input == 3) //Print Waiting Queue (3)
        {
            cout << "The waiting queue contains: " << endl;
            for (std::list<process>::iterator it=wqueue.begin(); it != wqueue.end(); ++it)
            {
                process pcb = *it;
                pcb.printPCB();
            }
            input = 0;
        }
        else if (input == 4) //Delete a PCB
        {
            int rpid;
            cout << "Enter the pid of the PCB to be deleted:";
            cin >> rpid;
            //go through all lists
            int found = 0; //found the PCB
            // Ready Queue
            if (found == 0)
            {
                for (std::list<process>::iterator it=rqueue.begin(); it != rqueue.end(); ++it)
                {
                    process pcb = *it;
                    if (rpid == pcb.getpid())
                    { // Delete PCB
                        rqueue.erase(it);
                        found = 1;
                    }

                }
            }
            // Waiting Queue
            if (found == 0)
            {
                for (std::list<process>::iterator it=wqueue.begin(); it != wqueue.end(); ++it)
                {
                    process pcb = *it;
                    if(rpid == pcb.getpid())
                    { // Delete PCB
                        wqueue.erase(it);
                        found = 1;
                    }
                }
            }
            if(found == 1)
            {
                cout << "Process has been deleted" << endl;
            }
            else
            {
                cout << "Process with pid " << rpid << " not found" << endl;
            }
            input = 0;
        }
        else //Error input (input != 1,2,3,or 4)
        {
            cout << "GoodBye!" << endl;
            input = -1; // Make sure that the program leaves the loop
        }
    }

}


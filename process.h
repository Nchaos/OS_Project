#ifndef PROCESS
#define PROCESS

#include <iostream>
#include <string>

using namespace std;

class process
{
    private:
        int pid;    //process id number
        string state; //new, ready, waiting, running, terminated
        char* pCounter; //program counter
        char* reg[15];  // 15 registers
        string name; //process name
        string desc; //proces description

    public:
        process(int pid);
        process(int pid, string name, string desc);
        // Getters
        int getpid();
        string getState();
        string getName();
        string getDesc();
        const char* getPCounter();
        // Setters
        void changeState(string newState);
        void setName(string name);
        void setDesc(string desc);
        void setPCounter(char* newPCounter);

        void printPCB();
        bool operator==(process &pcb1);

};

#endif // PROCESS


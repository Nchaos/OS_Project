#include "process.h"


process::process(int pid)
{
    this->pid = pid;
    state = "new";
    pCounter = nullptr;
    name ="unknown";
    desc ="unknown";
}

process::process(int pid, string name, string desc)
{
    this->pid = pid;
    state = "new";
    pCounter = nullptr;
    this->name = name;
    this->desc = desc;
}

int process::getpid()
{
    return pid;
}

string process::getState()
{
    return state;
}

string process::getName()
{
    return name;
}

string process::getDesc()
{
    return desc;
}

const char* process::getPCounter()
{
    return pCounter;
}

void process::changeState(string newState)
{
    state = newState;
}

void process::setName(string name)
{
    this->name = name;
}

void process::setDesc(string desc)
{
    this->desc = desc;
}

void process::setPCounter(char* newPCounter)
{
    pCounter = newPCounter;
}

void process::printPCB()
{
    cout << "--------------------------------------" << endl;
    cout << "| Program id: " << getpid() << endl;
    cout << "| State: " << getState() << endl;
    cout << "| Name: " << getName() << endl;
    cout << "| Description: " << getDesc() << endl;
    cout << "--------------------------------------" << endl;
}

bool process::operator==(process &pcb1)
{
    return getpid() == pcb1.getpid();
}

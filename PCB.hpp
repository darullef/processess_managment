//
// Created by darul on 08.04.2019.
//

#ifndef PROCESSESS_MANAGMENT_PCB_HPP
#define PROCESSESS_MANAGMENT_PCB_HPP

#include <string>
using namespace std;

enum status { AKTYWNY, GOTOWY, OCZEKUJACY, ZAKONCZONY };

class PCB
{
private:
    status state;
    int priority;
    string program_instructions;
    int program_counter;
    int AX;
    int BX;
    int CX;
    int memory;

public:
    string name;
    int PID;
    PCB(string na, string prog, int pr, int mmr);
    ~PCB();

    //settery
    void setStatuss(status st);
    void setPriority(int pr);

    void displayHelper();
    void displayOne();

};


#endif //PROCESSESS_MANAGMENT_PCB_HPP

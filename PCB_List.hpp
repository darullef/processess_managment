//
// Created by darul on 08.04.2019.
//

#ifndef PROCESSESS_MANAGMENT_PCB_LIST_HPP
#define PROCESSESS_MANAGMENT_PCB_LIST_HPP

#include <list>
#include <vector>
#include "PCB.hpp"
using namespace std;

class PCB_List
{
private:
    list<PCB>PCB_container;
    list<PCB>::iterator it;
public:
    PCB_List();
    ~PCB_List();

    void cp4(string na, string prog, int pr, int mmr);
    void createPCB(vector<string>v);
    void setStatus(vector<string>v);
    void setPriority(vector<string>v);
    void displayAll();
    void display(vector<string>v);
    void kill(vector<string>v);
    void hlep();
};


#endif //PROCESSESS_MANAGMENT_PCB_LIST_HPP

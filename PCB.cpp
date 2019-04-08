//
// Created by darul on 08.04.2019.
//

#include "PCB.hpp"
#include "PCB_List.hpp"
#include <iostream>

PCB::PCB(string na, string prog, int pr, int mmr)
{
    this->name = na;
    this->PID = rand() % 999 + 100;
    this->state = GOTOWY;
    this->priority = pr;
    this->program_instructions = prog;
    this->program_counter = 0;
    this->AX = 0;
    this->BX = 0;
    this->CX = 0;
    this->memory = mmr;
}

PCB::~PCB()
{
}

void PCB::setStatuss(status st)
{
    this->state = st;
}

void PCB::setPriority(int pr)
{
    this->priority = pr;
}

void PCB::displayHelper()
{
    cout << endl;
    cout << "PID: " << this->PID << endl;
    cout << "Nazwa procesu: " << this->name << endl;
    cout << "Status procesu: " << this->state << endl;
    cout << "Priorytet: " << this->priority << endl;
}

void PCB::displayOne()
{
    cout << "PID: " << this->PID << endl;
    cout << "Nazwa procesu: " << this->name << endl;
    cout << "Status procesu: " << this->state << endl;
    cout << "Priorytet: " << this->priority << endl;
    cout << "Program: " << this->program_instructions << endl;
    cout << "AX: " << this->AX << endl;
    cout << "BX: " << this->BX << endl;
    cout << "CX: " << this->CX << endl;
    cout << "Pamiec: " << this->memory << endl;
}

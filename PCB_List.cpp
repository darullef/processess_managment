//
// Created by darul on 08.04.2019.
//

#include "PCB_List.hpp"
#include "PCB.hpp"
#include <vector>
#include <iostream>


PCB_List::PCB_List()
{
}

PCB_List::~PCB_List(){
}

void PCB_List::cp4(string na, string prog, int pr, int mmr)
{
    PCB a(na, prog, pr, mmr);
    PCB_container.push_back(a);
}

void PCB_List::createPCB(vector<string>v)
{
    cp4(v[0], v[1], stoi(v[2]), stoi(v[3]));
    cout << "Utworzono proces." << endl;
}

void PCB_List::setStatus(vector<string>v)
{
    status s;
    if (v[1] == "zakonczony")
    {
        s = ZAKONCZONY;
    }
    else if (v[1] == "gotowy")
    {
        s = GOTOWY;
    }
    else if (v[1] == "oczekujacy")
    {
        s = OCZEKUJACY;
    }
    else if (v[1] == "aktywny")
    {
        s = AKTYWNY;
    }
    for (it = PCB_container.begin(); it != PCB_container.end(); it++)
    {
        if (it->PID == stoi(v[0]))
        {
            it->setStatuss(s);
            cout << "Ustwiono status. " << endl;
        }
        else
        {
            cout << "Nie ma procesu o takim PID." << endl;
        }
    }

}

void PCB_List::setPriority(vector<string>v)
{
    for (it = PCB_container.begin(); it != PCB_container.end(); it++)
    {
        if (it->PID == stoi(v[0]))
        {
            it->setPriority(stoi(v[1]));
            cout << "Ustawiono priorytet. " << endl;
        }
        else
        {
            cout << "Nie ma procesu o takim PID." << endl;
        }
    }

}

void PCB_List::displayAll()	//takslist
{
    for (it = PCB_container.begin(); it != PCB_container.end(); it++)
    {
        it->displayHelper();
    }
}

void PCB_List::display(vector<string>v)	//show
{
    bool czy = false;
    for (it = PCB_container.begin(); it != PCB_container.end(); it++)
    {
        if (it->PID == stoi(v[0]))
        {
            it->displayOne();
            czy = true;
        }
    }
    if (czy == false)
    {
        cout << "Nie ma procesu o takim PID." << endl;
    }
}

void PCB_List::kill(vector<string>v)
{
    for (it = PCB_container.begin(); it != PCB_container.end(); it++)
    {
        if (it->PID == stoi(v[0]))
        {
            PCB_container.erase(it);
            cout << "Usunieto proces. " << endl;
            return;
        }
    }
    cout << "Nie ma procesu o takim PID." << endl;
}

void PCB_List::hlep()
{
    cout << "CP [nazwa procesu] [program] [priorytet] [pamiec] - tworzenie procesu." << endl;
    cout << "SS [PID] [status] - zmiana statusu." << endl;
    cout << "SP [PID] [priorytet] - zmiana priorytetu." << endl;
    cout << "SHOW [PID] - wyswietlanie procesu." << endl;
    cout << "TASKLIST - wyswietlanie wszystkich procesow." << endl;
    cout << "KILL [PID] - zabija proces." << endl;
}


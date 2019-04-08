#include "PCB.hpp"
#include "PCB_List.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

PCB_List a;

string Wczytaj() {
    string msg;
    getline(cin, msg);
    return msg;
}

vector<string> Interpret(string msg) {
    if (msg == "") {
        vector<string> pusty;
        return pusty;
    }
    vector<string> tabmsg;
    //spacja ma kod ASCII 32
    string temp = "";
    int x = msg.size();
    for (int i = 0; i < x; i++) {
        if (msg[i] != 32) {
            temp = temp + msg[i];
        }
        if (msg[i] == 32) {
            tabmsg.push_back(temp);
            temp = "";
        }
    }
    if (temp != "") {
        tabmsg.push_back(temp);
    }
    string polecenie = tabmsg[0];
    x = tabmsg.size();
    return tabmsg;
}

string ToUp(string s) {
    setlocale(LC_CTYPE, "pl_PL.UTF-8");
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

string ToDown(string s) {
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

void Wywolaj(vector<string> tab)
{
    int x = tab.size();
    if (x == 0) {
        return;
    }
    string polecenie = tab[0];
    polecenie = ToUp(polecenie);
    vector<string> parametry;
    if (x > 1) {
        for (int i = 1; i < x; i++) {
            parametry.push_back(tab[i]);
            parametry[i - 1] = ToDown(parametry[i - 1]);
        }
    }
    if (polecenie == "CP") {
        a.createPCB(parametry);
        return;
    }
    else if (polecenie == "SP") {
        a.setPriority(parametry);
        return;
    }
    else if (polecenie == "SS") {
        a.setStatus(parametry);
        return;
    }
    else if (polecenie == "TASKLIST") {
        a.displayAll();
        return;
    }
    else if (polecenie == "SHOW") {
        a.display(parametry);
        return;
    }
    else if (polecenie == "HELP") {
        a.hlep();
        return;
    }
    else if (polecenie == "KILL") {
        a.kill(parametry);
        return;
    }
    else if (polecenie == "EXIT") {
        exit(0);
    }
}

int main()
{
    while (true)
    {
        cout << "P:/";
        string a = Wczytaj();
        vector<string> b = Interpret(a);
        Wywolaj(b);
    }
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class IComponent{
    public : 
        virtual void showPrice() = 0;
};

class Leaf : public IComponent{
    private:
        string name;
        int price;
    public:
        Leaf(string name,int price){
            this->name = name;
            this->price = price;
        }
        void showPrice(){ 
            cout << name << " : " << price;
        }
};

class Composite : public IComponent{
    private:
        string name;
        vector<IComponent*> components;
    public:
        Composite(string name){
            this->name = name;
        }
        void addComponent(IComponent* cmp){
            components.push_back(cmp);
        }
        void showPrice(){ 
            cout << name << endl;
            for(IComponent* c: components){
                c->showPrice();
                cout << " , ";
            }
            cout << endl;
        }
};

;

int main() {

    IComponent* hd = new Leaf("Hard Disk",4000);
    IComponent* mouse = new Leaf("Mouse",500);
    IComponent* monitor = new Leaf("Monitor",20000);
    IComponent* ram = new Leaf("Ram",7000);
    IComponent* cpu = new Leaf("CPU",15000);

    Composite* ph = new Composite("Peripheral");
    Composite* cabinet = new Composite("Cabinet");
    Composite* mb = new Composite("MB");
    Composite* computer = new Composite("Computer");

    ph->addComponent(mouse);
    ph->addComponent(monitor);

    mb->addComponent(cpu);
    mb->addComponent(ram);

    cabinet->addComponent(hd);
    cabinet->addComponent(mb);

    computer->addComponent(ph);
    computer->addComponent(cabinet);

    computer->showPrice();
    
    return 0;
}



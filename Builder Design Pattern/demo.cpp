#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Desktop{
    private:
        string ram;
        string mouse;
        string monitor;
        string keyoard;
        string processor;
        string motherBoard;
    public:
        void setRam(string ram);
        void setMouse(string mouse);
        void setMonitor(string monitor);
        void setKeyboard(string keyoard);
        void setProcessor(string processor);
        void setMotherBoard(string motherBoard);
        void showSpec();
};

void Desktop::setRam(string ram){ this->ram = ram; }
void Desktop::setMouse(string mouse){ this->mouse = mouse; }
void Desktop::setMonitor(string monitor){ this->monitor = monitor; }
void Desktop::setKeyboard(string keyoard){ this->keyoard = keyoard; }
void Desktop::setProcessor(string processor){ this->processor = processor; }
void Desktop::setMotherBoard(string motherBoard){ this->motherBoard = motherBoard; }
void Desktop::showSpec(){
    cout << "--------------------------------" << endl;
    cout << "Ram : " << ram << endl;
    cout << "Mouse : " << mouse << endl;
    cout << "Monitor : " << monitor << endl;
    cout << "Keyoard : " << keyoard << endl;
    cout << "Processor : " << processor << endl;
    cout << "MotherBoard : " << motherBoard << endl;
    cout << "--------------------------------" << endl;

    cout << endl;
}

class DesktopBuilder{
    protected:
        Desktop* desktop;
    public:
        DesktopBuilder(){
            desktop = new Desktop();
        }
        virtual void buildRam() = 0; 
        virtual void buildMouse () = 0;
        virtual void buildMonitor() = 0;
        virtual void buildKeyboard() = 0;
        virtual void buildProcessor() = 0;
        virtual void buildMotherBoard() = 0;
        virtual Desktop* getDesktop(){ return desktop; }
};

class DellDesktopBuilder : public DesktopBuilder{
    public:
        void buildRam() { desktop->setRam("Dell Ram"); }
        void buildMouse() { desktop->setMouse("Dell Mouse"); }
        void buildMonitor() { desktop->setMonitor("Dell Monitor"); }
        void buildKeyboard() { desktop->setKeyboard("Dell Keyoboard"); }
        void buildProcessor() { desktop->setProcessor("Dell Processor"); }
        void buildMotherBoard() { desktop->setMotherBoard("Dell MotherBoard"); }
};

class HpDesktopBuilder : public DesktopBuilder{
    public:
        void buildRam() { desktop->setRam("Hp Ram"); }
        void buildMouse() { desktop->setMouse("Hp Mouse"); }
        void buildMonitor() { desktop->setMonitor("Hp Monitor"); }
        void buildKeyboard() { desktop->setKeyboard("Hp Keyoboard"); }
        void buildProcessor() { desktop->setProcessor("Hp Processor"); }
        void buildMotherBoard() { desktop->setMotherBoard("Hp MotherBoard"); }
};

class DesktopDirector {
    private:
        DesktopBuilder* desktopBuilder;
    public:
        DesktopDirector(DesktopBuilder* desktopBuilder){ 
            this->desktopBuilder = desktopBuilder;  
        }
        Desktop* buildDesktop(){
            desktopBuilder->buildRam();
            desktopBuilder->buildMouse();
            desktopBuilder->buildMonitor();
            desktopBuilder->buildKeyboard();
            desktopBuilder->buildProcessor();
            desktopBuilder->buildMotherBoard();
            return desktopBuilder->getDesktop();
        }
};


int main() {

    HpDesktopBuilder* hpDesktopBuilder = new HpDesktopBuilder();
    DellDesktopBuilder* dellDesktopBuilder = new DellDesktopBuilder();
    
    DesktopDirector* director1 = new DesktopDirector(hpDesktopBuilder);
    DesktopDirector* director2 = new DesktopDirector(dellDesktopBuilder);

    Desktop* desktop1 = director1->buildDesktop();
    Desktop* desktop2 = director2->buildDesktop();

    cout << endl;
    
    cout << "Desktop 1 " << endl; 
    desktop1->showSpec();    
    
    cout << "Desktop 2 " << endl; 
    desktop2->showSpec();    
    
    return 0;
}



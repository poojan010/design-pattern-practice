#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Alarm{
    public:
        void turnOn(){
            cout << "Alarm Turned on" << endl;
        }
        void turnOff(){
            cout << "Alarm Turned off" << endl;
        }
};

class Tv{
    public:
        void turnOn(){
            cout << "Tv Turned on" << endl;
        }
        void turnOff(){
            cout << "Tv Turned off" << endl;
        }
};

class Ac{
    public:
        void turnOn(){
            cout << "Ac Turned on" << endl;
        }
        void turnOff(){
            cout << "Ac Turned off" << endl;
        }
};


class HouseFacade{
    private:
        Alarm alarm;
        Tv tv;
        Ac ac;
    public:
        void goingToWork(){
            cout << "Going to work " << endl;
            alarm.turnOff();
            tv.turnOff();
            ac.turnOff();
        }
        void comingBackHome(){
            cout << "Coming back to home " << endl;
            alarm.turnOn();
            tv.turnOn();
            ac.turnOn();
        }
};

int main() {

    //Rather than calling 100 different on and off functions thanks to facade I only have 2 functions...
    
    HouseFacade house;

    house.goingToWork();
    
    cout << endl;

    house.comingBackHome();

    return 0;
}

/** 
    Facade defines a higher-level interface that makes the subsystem easier to use by wrapping a complicated subsystem.
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


class IMobileAlertState{
    public:
        virtual void alert() = 0;
};

class Ringing : public IMobileAlertState{
    public:
        void alert(){ cout << "Mobile is Ringing.." << endl; };
};
class Vibrate : public IMobileAlertState{
    public:
        void alert(){ cout << "Mobile is Vibrating.."<< endl; };
};
class Silent : public IMobileAlertState{
    public:
        void alert(){ cout << "Mobile is in Silent Mode."<< endl; };
};


class MobileContext{
    private:
        IMobileAlertState* state;

    public:
        MobileContext(){
            this->state = new Ringing();
        }
        void alert(){
            state->alert();
        }
        void setState(IMobileAlertState* newState){
            this->state = newState;
        }
};

int main() {

    MobileContext* mobile = new MobileContext();

    cout << "ALERT :"; mobile->alert();

    
    cout << endl << "Changing Mobile state to vibrate." << endl;
    mobile->setState(new Vibrate());
    cout << "ALERT :"; mobile->alert();
    
    
    cout << endl  << "Changing Mobile state to silent." << endl;
    mobile->setState(new Silent());
    cout << "ALERT :"; mobile->alert();
    
    
    cout << endl  << "Changing Mobile state to ringing." << endl;
    mobile->setState(new Ringing());
    cout << "ALERT :"; mobile->alert();

    
    return 0;
}



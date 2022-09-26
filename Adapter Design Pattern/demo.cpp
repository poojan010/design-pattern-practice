#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class ISocketIndian{
    public:
        virtual void indianCharge(int) = 0;
};

class SocketUSA{
    public:
        void usaCharge(){ cout << "Charging type USA " << endl; }
}; 

class SocketCanada{
    public:
        void canadaCharge(){ cout << "Charging type Canada " << endl; }
}; 


class SocketAdapter : public ISocketIndian, SocketUSA, SocketCanada{
    public :
        void indianCharge(int type){
            switch(type){
                case 1:
                    usaCharge();
                    break;
                case 2:
                    canadaCharge();
                    break;
                default:
                    break;
            }
        }
};

int main() {

    SocketAdapter *indian = new SocketAdapter();
    indian->indianCharge(2);
    
    return 0;
}



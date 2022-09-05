#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Vehicle{
    public:
        virtual void createVehicle() = 0;
};

class Car : public Vehicle{
    public: 
        void createVehicle(){
            cout << "Creating Vehicle Car." << endl;
        }    
};

class Bike : public Vehicle{
    public: 
        void createVehicle(){
            cout << "Creating Bike Bike." << endl;
        }    
};

class Bus : public Vehicle{
    public: 
        void createVehicle(){
            cout << "Creating Vehicle Bus." << endl;
        }    
};

class VehicleFactory{
    public :
        static Vehicle* getVehicle(string vehicleType){
            Vehicle* vehicle;
            if(vehicleType == "car"){
                vehicle = new Car();
            }
            else if(vehicleType == "bike"){
                vehicle = new Bike();
            }
            else if(vehicleType == "bus"){
                vehicle = new Bus();
            }
            else{
                cout << " Invalid type of vehicle " << endl;
            }
            
            return vehicle;    
        }
};



int main() {

    string vehicleType;
    cin >> vehicleType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vehicleType);

    vehicle->createVehicle();

    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;




class ICar {
    public: 
        virtual void runCar() = 0;    
};

class HyundaiCar : public ICar{
    public : 
        void runCar(){
            cout << "Hyundai Car Running" << endl;
        }
};

class ToyotaCar : public ICar{
    public : 
        void runCar(){
            cout << "Toyota Car Running" << endl;
        }
};






class IBike{
    public: 
        virtual void runBike() = 0;       
};

class HyundaiBike : public IBike{
    public : 
        void runBike(){
            cout << "Hyundai Bike Running" << endl;
        }
};

class ToyotaBike : public IBike{
    public : 
        void runBike(){
            cout << "Toyota Bike Running" << endl;
        }
};






class IFactory{
    public:
        virtual ICar* getCar() = 0;
        virtual IBike* getBike() = 0;
};

class HyundaiFactory : public IFactory{
    public :
        ICar* getCar(){
            return new HyundaiCar();
        }
        IBike* getBike(){
            return new HyundaiBike();
        }
};

class ToyotaFactory : public IFactory{
    public :
        ICar* getCar(){
            return new ToyotaCar();
        }
        IBike* getBike(){
            return new ToyotaBike();
        }
};






class GUIAbstractFactory{
    public:
        static IFactory* createFactory(string factoryType){
            if(factoryType == "Hyundai"){
                return new HyundaiFactory();
            }
            else if(factoryType == "Toyota"){
                return new ToyotaFactory();
            }
            else{
                return new HyundaiFactory();
            }
        }
};






int main() {

    cout << "Enter Factory name : ";
    string factType;
    cin >> factType;

    IFactory* fact = GUIAbstractFactory::createFactory(factType);

    ICar* car = fact->getCar();
    car->runCar();
    
    IBike* bike = fact->getBike();
    bike->runBike();
    
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class IMilkshake{
    public:
        virtual string serve() = 0;
        virtual int getPrice() = 0;
};


class SimpleMilkShake : public IMilkshake{
    public:
        string serve(){ return "Serving Simple Milkshake"; }
        int getPrice(){ return 20; }
};

class MilkShakeDecorator : public IMilkshake{
    protected:
        IMilkshake *milkShake;
    public:
        MilkShakeDecorator(IMilkshake *milkShake){
            this->milkShake = milkShake;
        }
        string serve(){ return milkShake->serve(); }
        int getPrice(){ return milkShake->getPrice(); }
};

class MangoMilkShake : public MilkShakeDecorator{
    public:
        MangoMilkShake(IMilkshake *milkShake): MilkShakeDecorator(milkShake) {}
        string serve(){ return milkShake->serve() + " " + "with Mango"; }
        int getPrice(){ return milkShake->getPrice() + 15; }
};

class VanilaMilkShake : public MilkShakeDecorator{
    public:
        VanilaMilkShake(IMilkshake *milkShake): MilkShakeDecorator(milkShake) {}
        string serve(){ return milkShake->serve() + " " + "with vanila"; }
        int getPrice(){ return milkShake->getPrice() + 25; }
};

int main() {

    IMilkshake *simpleMilkShake = new SimpleMilkShake();
    cout << "Simple Milk shake \n";
    cout << simpleMilkShake->serve() << endl;
    cout << simpleMilkShake->getPrice() << endl;    

    cout << "\n";
    
    IMilkshake* decoratedMilkShake = new MangoMilkShake(simpleMilkShake);
    cout << "Decorated Milk shake with Mango \n";
    cout << decoratedMilkShake->serve() << endl;
    cout << decoratedMilkShake->getPrice() << endl;

    cout << "\n";
    
    IMilkshake* decoratedMilkShake2 = new VanilaMilkShake(simpleMilkShake);
    cout << "Decorated Milk shake with vaila \n";
    cout << decoratedMilkShake2->serve() << endl;
    cout << decoratedMilkShake2->getPrice() << endl;

    cout << "\n";
    
    IMilkshake* decoratedMilkShake3 = new MangoMilkShake(new VanilaMilkShake(simpleMilkShake));
    cout << "Decorated Milk shake with 2 flavours \n";
    cout << decoratedMilkShake3->serve() << endl;
    cout << decoratedMilkShake3->getPrice() << endl;

    
    return 0;
}



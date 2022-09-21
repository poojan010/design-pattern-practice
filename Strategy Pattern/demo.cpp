#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Old Code

/**

class Animal(){
    private:
        string name;
        double height;
        double weight;
        string sound;
        
    public:
        void setName(string name){ this->name = name; }
        string getName(){ return name; }
        void setSound(string sound){ this->sound = sound; }
        string getSound(){ return sound; }
        void setHeight(double height){ this->height = height; }
        double getHeight(){ return height; }
        void setWeight(double weight){ this->weight = weight; }
        double setWeight(){ return weight; }

};


class Dog : public Animal{
    public:
        Dog(){
            setSound("baark");
        }
};


class Pigeon : public Animal{
    public:
        Pigeon(){
            setSound("grrr.");
        }
};

*/

/** 
Let's say we need to add new funtionality to the Animals : "Fly"
some animals can fly while some can not

If we add functionalty to base class and let sub class inherit that functionality
then we need to implemnt empty methods for non flying animals

Instead of using an interface in a traditional way
we use an instance variable that is a subclass
of the Flys interface.
*/

class IFly {
    public: 
        virtual void fly() = 0;    
};

class CanFly : public IFly{
    public: 
        void fly(){
            cout << "Flying High" << endl;
        }    
};
class CanNotFly : public IFly{
    public: 
        void fly(){
            cout << "I can not Fly" << endl;
        }    
};

class Animal{
    private:
        string name;
        double height;
        double weight;
        string sound;
        
    public:
        IFly* flyingType; 
        void setName(string name){ this->name = name; }
        string getName(){ return name; }
        void setSound(string sound){ this->sound = sound; }
        string getSound(){ return sound; }
        void setHeight(double height){ this->height = height; }
        double getHeight(){ return height; }
        void setWeight(double weight){ this->weight = weight; }
        double setWeight(){ return weight; }
        void tryToFly(){
            flyingType->fly();
        }
        void setFlyAbility(IFly* flyingType){
            this->flyingType = flyingType;
        }

};


class Dog : public Animal{
    public:
        Dog(){
            setSound("baark");
            flyingType = new CanNotFly();
        }
};


class Pigeon : public Animal{
    public:
        Pigeon(){
            setSound("grrr...");
            flyingType = new CanFly();
        }
};


int main() {

    Animal* dog = new Dog();
    Animal* pigeon = new Pigeon();

    cout << "Dog : ";
    dog->tryToFly();
    cout << "Pigeon : ";
    pigeon->tryToFly();

    dog->setFlyAbility(new CanFly());

    cout << "Dog : ";
    dog->tryToFly();

  return 0;
}
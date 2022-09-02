
class Vehicle {
    public:
        virtual void startEngine();
};

class Car : public Vehicle{
    void startEngine(); 
};

class Bicycle : public Vehicle{
    void  startEngine();
};

// In above scenario 
// Bicycle does not need startEngine method
// Principle states that
// "Derived class must be substitutable for their base class."

// Solution 

class VehicleWithEngine {
    public : 
        virtual void startEngine() = 0; 
};

class VehicleWithoutEngine {
    public : 
        virtual void startMoving() = 0; 
};

class CarNew : public VehicleWithEngine{
    void startEngine(); 
};

class BicycleNew : public VehicleWithoutEngine{
    void  startMoving();
};


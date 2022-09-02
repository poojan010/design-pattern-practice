
// Violates Single responsibility principle
class Person{

    // methods
    void cookFood();
    void driveCar();
    void paintWall();
};


// Solution
class Driver{
    void driveCar();
};

class Chef{
    void cookFood();
};

class Painter{
    void paintWall();
};

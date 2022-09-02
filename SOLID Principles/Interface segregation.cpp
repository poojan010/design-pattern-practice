
class Shape {
    public:
        virtual void calculateArea() = 0;
        virtual void calculateVolume() = 0;
};

class Cube : public Shape{
    void calculateArea(){
        
    }
    void calculateVolume(){
        
    }
};

class Square : public Shape{
    void calculateArea(){
        
    }
    void calculateVolume(){
        
    }
};

// Here calculateVolume method in Square class is not needed 
// still it has to implement

// Solution
class TwoDimensionShape{
    public:
        virtual void calculateArea() = 0;
};
class ThreeDimensionShape{
    public:
        virtual void calculateVolume() = 0;
};

class CubeNew : public TwoDimensionShape, public ThreeDimensionShape {
    void calculateArea(){
        
    }
    void calculateVolume(){
        
    }
};

class SquareNew : public TwoDimensionShape{
    void calculateArea(){
        
    }

};
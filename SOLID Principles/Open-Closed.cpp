
class Operation {

  double calculate(double d1, double d2, char operationType) {
    switch (operationType) {

        case '+': {
            return d1 + d2;
        }

        case '-': {
            return d1 - d2;
        }

        default: {
            return 0.0;
        }
    }
  }
};

// Let's say if new requirements come '*'
// then we have to modify the existing method
// that can lead to produce bug in existing system

// Solution

class OperationInterface {
public:
  virtual double calculate(double, double) = 0;
};

class AddOperation : public OperationInterface {
public:
  double calculate(double d1, double d2) { return d1 + d2; }
};

class MinusOperation : public OperationInterface {
public:
  double calculate(double d1, double d2) { return d1 - d2; }
};

// So, now Operation Class is closed for modification
// and open for extension.

#include <iostream>
using namespace std;

class largerUnit; // Forward declaration

class smallUnit {
private:
    int inches;

public:
    smallUnit(int inches) : inches(inches) {}

    operator largerUnit(); // Forward declaration of conversion operator

    void display() {
        cout << "Measurement in inches: " << inches << " inches" << endl;
    }
};

class largerUnit {
private:
    int feet;

public:
    largerUnit(int feet) : feet(feet) {}

    void display() {
        cout << "Measurement in feet: " << feet << " feet" << endl;
    }
};

// Definition of conversion operator
smallUnit::operator largerUnit() {
    return largerUnit(inches / 12);
}

int main() {
    smallUnit smallUnit_OBJ(36); // 36 inches
    largerUnit largerUnit_OBJ = smallUnit_OBJ; // Conversion from smallUnit to largerUnit

    largerUnit_OBJ.display(); // Display measurement in feet
    smallUnit_OBJ.display(); // Display measurement in inches

    return 0;
}

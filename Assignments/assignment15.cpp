#include <iostream>
using namespace std;

class ClassB; // Forward declaration

class ClassA {
private:
    int a;

public:
    ClassA(int a) : a(a) {}

    // Declare friend function to access private members of ClassA and ClassB
    friend int sum(const ClassA& objA, const ClassB& objB);
};

class ClassB {
private:
    int b;

public:
    ClassB(int b) : b(b) {}

    // Declare friend function to access private members of ClassA and ClassB
    friend int sum(const ClassA& objA, const ClassB& objB);
};

// Friend function to access private members of ClassA and ClassB
int sum(const ClassA& objA, const ClassB& objB) {
    return objA.a + objB.b;
}

int main() {
    ClassA objA(5);
    ClassB objB(10);

    cout << "Sum: " << sum(objA, objB) << endl;

    return 0;
}


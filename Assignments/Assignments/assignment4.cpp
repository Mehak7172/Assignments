#include <iostream>
#include <iostream>
using namespace std;

class computation {
public:
    int compute(int num1, int num2) {
        return num1 + num2;
    }

    float compute(int num, float fnum) {
        return num + fnum;
    }

    double compute(int num, double dnum) {
        return num + dnum;
    }

    int compute(char char1, char char2) {
        return int(char1) + int(char2);
    }

    int compute(char ch, int num) {
        return int(ch) + num;
    }

    int compute() {
        return 0;
    }
};

int main() {
    computation obj;

    int num1, num2;
    float fnum;
    double dnum;
    char char1, char2, ch;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    cout << "1 + 2 = " << obj.compute(num1, num2) << endl;

    cout << "Enter an integer and a float: ";
    cin >> num1 >> fnum;
    cout << "1 + 2.5 = " << obj.compute(num1, fnum) << endl;

    cout << "Enter an integer and a double: ";
    cin >> num1 >> dnum;
    cout << "1 + 2.5 = " << obj.compute(num1, dnum) << endl;

    cout << "Enter two characters: ";
    cin >> char1 >> char2;
    cout << "ASCII value of 'a' + ASCII value of 'b' = " << obj.compute(char1, char2) << endl;

    cout << "Enter a character and an integer: ";
    cin >> ch >> num1;
    cout << "ASCII value of 'a' + 2 = " << obj.compute(ch, num1) << endl;

    cout << "No value provided = " << obj.compute() << endl;

    return 0;
}


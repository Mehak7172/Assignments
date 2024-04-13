#include <iostream>
using namespace std;

class sample {
public:
    int Compute(int (sample::*func)(int), int n) {
        return (this->*func)(n);
    }

    int findFactorial(int n) {
        int fact = 1;
        for(int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }

    int findSquare(int n) {
        return n * n;
    }

    int findCube(int n) {
        return n * n * n;
    }
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <number>" << endl;
        return 1;
    }

    int N = atoi(argv[1]); // Convert command line argument to integer

    sample obj;
    // Call Compute method and pass the findFactorial function as an argument
    cout << "Factorial of " << N << ": " << obj.Compute(&sample::findFactorial, N) << endl;
    // Call Compute method and pass the findSquare function as an argument
    cout << "Square of " << N << ": " << obj.Compute(&sample::findSquare, N) << endl;
    // Call Compute method and pass the findCube function as an argument
    cout << "Cube of " << N << ": " << obj.Compute(&sample::findCube, N) << endl;

return 0;
}

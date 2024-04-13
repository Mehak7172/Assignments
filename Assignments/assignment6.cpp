#include <iostream>
#include <functional> // for std::function
#include <cstdlib>    // for std::atoi
using namespace std;

class sample {
public:
    int Compute(std::function<int(int)> func, int n) {
        return func(n);
    }

    int findFactorial(int n) {
        int fact = 1;
        for (int i = 1; i <= n; i++) {
            fact = fact * i;
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
    if (argc != 3) {
        cout << "Usage: " << argv[0] << " <number> <function>" << endl;
        cout << "Functions: factorial, square, cube" << endl;
        return 1;
    }

    int n = atoi(argv[1]); // Convert command-line argument to integer
    string function_name = argv[2]; // Get the function name from command line

    sample obj;

    std::function<int(int)> func;

    // Select the appropriate function based on the command-line argument
    if (function_name == "factorial")
        func = [&](int x) { return obj.findFactorial(x); };
    else if (function_name == "square")
        func = [&](int x) { return obj.findSquare(x); };
    else if (function_name == "cube")
        func = [&](int x) { return obj.findCube(x); };
    else {
        cout << "Invalid function name!" << endl;
        return 1;
    }

    // Call Compute method and pass the appropriate member function as an argument
    cout << function_name << " of " << n << " is: " << obj.Compute(func, n) << endl;

    return 0;
}

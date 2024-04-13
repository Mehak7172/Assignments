#include<iostream>
#include<cstring>
using namespace std;

class sample {
public:
    char *name;

    // Default constructor
    sample() : name(nullptr) {}

    // Constructor with parameters
    sample(const char *str, int length) {
        name = new char[length + 1];
        strcpy(name, str);
    }

    // Copy constructor for deep copying
    sample(const sample &other) {
        if (other.name != nullptr) {
            int length = strlen(other.name);
            name = new char[length + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
    }

    // Destructor to release dynamically allocated memory
    ~sample() {
        delete[] name;
    }
};

int main(int argc, char *argv[]) {
    sample user1("chitkara", 8);
    sample user2 = user1; // Invokes copy constructor

    // Modify user2's name
    strcpy(user2.name, "dummy");

    // Output user2's name followed by user1's name
    cout << user2.name << " " << user1.name << endl;

    return 0;
}

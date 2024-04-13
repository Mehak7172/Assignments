#include <iostream>
#include <string>
#include <sstream> // for std::stringstream
using namespace std;

class StringAnalyzer {
private:
    string* strPtr;

public:
    // Constructor to initialize the string pointer with the given string
    StringAnalyzer(const string& str) {
        strPtr = new string(str);
    }

    // Destructor to free the memory allocated for the string
    ~StringAnalyzer() {
        delete strPtr;
    }

    // Function to calculate the total number of words in the string
    int countWords() const {
        stringstream ss(*strPtr);
        string word;
        int count = 0;
        while (ss >> word) {
            count++;
        }
        return count;
    }
};

int main() {
    string inputString = "This is a sample sentence.";

    // Create an object of StringAnalyzer with the given string
    StringAnalyzer analyzer(inputString);

    // Calculate and display the total number of words
    cout << "Total words in the string: " << analyzer.countWords() << endl;

    return 0;
}


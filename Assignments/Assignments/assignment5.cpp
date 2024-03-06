#include <iostream>
#include <string>
using namespace std;

class User {
public:
    string name;
    int birth_year;
    int birth_month;
    int birth_day;
    double salary;

    // Constructor to initialize member variables
    User(string name, int year, int month, int day, double salary) {
        this->name = name;
        this->birth_year = year;
        this->birth_month = month;
        this->birth_day = day;
        this->salary = salary;
    }

    // Overloaded '==' operator to compare users' ages
    int operator==(const User& other) const {
        if (this->birth_year < other.birth_year)
            return 1;
        else if (this->birth_year > other.birth_year)
            return -1;
        else {
            if (this->birth_month < other.birth_month)
                return 1;
            else if (this->birth_month > other.birth_month)
                return -1;
            else {
                if (this->birth_day < other.birth_day)
                    return 1;
                else if (this->birth_day > other.birth_day)
                    return -1;
                else
                    return 0;
            }
        }
    }

    // Overloaded '+' operator to compute average salary
    double operator+(const User& other) const {
        return (this->salary + other.salary) / 2.0;
    }

    // Method to add annual increment in percentage
    void operator+(double increment) {
        this->salary *= (1 + increment / 100.0);
    }

    // Method to display user details
    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Birth Date: " << birth_year << "/" << birth_month << "/" << birth_day << endl;
        cout << "Salary: $" << salary << endl;
    }
};

int main() {
    // Creating user objects
    string name1, name2;
    int year1, month1, day1, year2, month2, day2;
    double salary1, salary2;

    cout << "Enter details for User 1:" << endl;
    cout << "Name: ";
    cin >> name1;
    cout << "Birth Year: ";
    cin >> year1;
    cout << "Birth Month: ";
    cin >> month1;
    cout << "Birth Day: ";
    cin >> day1;
    cout << "Salary: ";
    cin >> salary1;

    cout << "\nEnter details for User 2:" << endl;
    cout << "Name: ";
    cin >> name2;
    cout << "Birth Year: ";
    cin >> year2;
    cout << "Birth Month: ";
    cin >> month2;
    cout << "Birth Day: ";
    cin >> day2;
    cout << "Salary: ";
    cin >> salary2;

    User user1(name1, year1, month1, day1, salary1);
    User user2(name2, year2, month2, day2, salary2);

    // Comparing users' ages
    int result = user1 == user2;
    if (result == 1)
        cout << "User 1 is elder." << endl;
    else if (result == -1)
        cout << "User 2 is elder." << endl;
    else
        cout << "Both users are of the same age." << endl;

    // Computing average salary
    double average_sal = user1 + user2;
    cout << "Average Salary: $" << average_sal << endl;

    // Adding annual increment
    double increment1, increment2;
    cout << "\nEnter annual increment percentage for User 1: ";
    cin >> increment1;
    user1 + increment1; // Adding increment for user1
    cout << "Enter annual increment percentage for User 2: ";
    cin >> increment2;
    user2 + increment2; // Adding increment for user2

    // Displaying updated user details
    cout << "\nAfter annual increment:\n";
    cout << "User 1:\n";
    user1.displayDetails();
    cout << "\nUser 2:\n";
    user2.displayDetails();

    return 0;
}

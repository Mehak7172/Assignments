#include <iostream>
#include <string>

using namespace std;

// Base class representing a menu item
class MenuItem {
protected:
    string name;
    double price;

public:
    MenuItem(const string& name, double price) : name(name), price(price) {}

    virtual double getPrice() const {
        return price;
    }

    virtual void display() const {
        cout << left << setw(20) << name << " $" << getPrice() << endl;
    }

    virtual ~MenuItem() {}
};

// Derived class representing food items
class FoodItem : public MenuItem {
private:
    string category;

public:
    FoodItem(const string& name, double price, const string& category)
        : MenuItem(name, price), category(category) {}

    void display() const override {
        cout << left << setw(20) << name << " $" << getPrice() << " (" << category << ")" << endl;
    }
};

// Derived class representing beverages
class Beverage : public MenuItem {
private:
    bool alcoholic;

public:
    Beverage(const string& name, double price, bool alcoholic)
        : MenuItem(name, price), alcoholic(alcoholic) {}

    void display() const override {
        cout << left << setw(20) << name << " $" << getPrice() << " (";
        if (alcoholic)
            cout << "Alcoholic";
        else
            cout << "Non-Alcoholic";
        cout << ")" << endl;
    }
};

// Derived class representing desserts
class Dessert : public MenuItem {
public:
    Dessert(const string& name, double price) : MenuItem(name, price) {}

    void display() const override {
        cout << left << setw(20) << name << " $" << getPrice() << endl;
    }
};

// Class representing a bill
class Bill {
private:
    const MenuItem* items[3]; // Maximum number of items is 3

public:
    Bill() {
        for (int i = 0; i < 3; ++i) {
            items[i] = nullptr;
        }
    }

    void addItem(const MenuItem* item, int index) {
        if (index >= 0 && index < 3) {
            items[index] = item;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    double calculateTotal() const {
        double total = 0.0;
        for (int i = 0; i < 3; ++i) {
            if (items[i] != nullptr) {
                total += items[i]->getPrice();
            }
        }
        return total;
    }

    void displayBill() const {
        cout << "==============================" << endl;
        cout << "            Bill              " << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < 3; ++i) {
            if (items[i] != nullptr) {
                items[i]->display();
            }
        }
        cout << "------------------------------" << endl;
        cout << "Total: $" << calculateTotal() << endl;
        cout << "==============================" << endl;
    }

    // Destructor to deallocate memory
    ~Bill() {
        for (int i = 0; i < 3; ++i) {
            delete items[i];
        }
    }
};

int main() {
    // Creating items
    MenuItem* pizza = new FoodItem("Pizza", 10.99, "Italian");
    MenuItem* cola = new Beverage("Cola", 2.50, false);
    MenuItem* iceCream = new Dessert("Ice Cream", 4.99);

    // Creating a bill
    Bill bill;

    // Adding items to the bill
    bill.addItem(pizza, 0);
    bill.addItem(cola, 1);
    bill.addItem(iceCream, 2);

    // Displaying the bill
    bill.displayBill();

    // Freeing memory
    delete pizza;
    delete cola;
    delete iceCream;

    return 0;
}


#include <iostream>
using namespace std;

//FROM THE END OF THE LINE REMEMBER THAT PLEASE

// defines car struct to represent the car data
struct Car { //node
    string model;
    double price;
    Car* next;

    Car(string model, double price) : model(model), price(price), next(nullptr) {}
};

// defines a factoryBelt class to manage the conveyor belt of cars
class factoryBelt {
private:
    Car* head;

public:
    factoryBelt() : head(nullptr) {}

    // adds a new car to the end of the conveyor belt(tail)
    void addCar(string model, double price) {
        Car* newCar = new Car(model, price);
        if (!head) {
            head = newCar;
        } else {
            Car* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newCar;
        }
    }

    // prints the model and price of the first car in line
    void printFirstCar() {
        if (head) {
            cout << "Car Model: " << head->model << ", Price: $" << head->price << endl;
        } else {
            cout << "No cars on the conveyor belt." << endl;
        }
    }

    // removes the defected car x places from the end
    void removeDefected(int x) {
        if (!head) {
            cout << "No cars on the conveyor belt to remove." << endl;
            return;
        }

        Car* slow = head;
        Car* fast = head;

        // moves the fast pointer x positions ahead
        for (int i = 0; i < x; i++) {
            if (fast->next) {
                fast = fast->next;
            } else {
                cout << "Not enough cars on the conveyor belt." << endl;
                return;
            }
        }

        Car* prev = nullptr;

        // move both the pointers until the fast pointer reaches the end
        while (fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }

        if (!prev) {
            //first car is getting removed
            head = slow->next;
        } else {
            prev->next = slow->next;
        }

        cout << "Removed car: Model " << slow->model <<endl;
        delete slow;
    }
};

int main() {
    factoryBelt belt;

    string model;
    double price;
    int numCars;

    cout << "Enter number of cars placed on the conveyor belt: ";
    cin >> numCars;

    for (int i = 0; i < numCars; i++) {
        cout << "Enter the model for car " << i + 1 << ": ";
        cin >> model;

        cout << "Enter the price for car " << i + 1 << ": ";
        cin >> price;

        belt.addCar(model, price);
    }

    belt.printFirstCar(); // prints the first car in line

    int x;
    cout << "Enter the position of the defected car to remove: ";
    cin >> x;

    belt.removeDefected(x); // removes the defected car from the specified position

    belt.printFirstCar(); // prints new first car in the line

    return 0;
}
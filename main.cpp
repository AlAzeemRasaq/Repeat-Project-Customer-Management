#include "pch.h"
#include "Customer.h"

using namespace std;

vector<Customer> allCustomers;

void addCustomer();
void displayCustomers();
void findCustomer();
void findByPurchase();
void manageData();

int main() {
    std::cout << "Customer Management System" << std::endl;
    return 0;

    int menu;
    do {
        std::cout
                << "Menu:\n"
                   "1. Add customer\n"
                   "2. Display all customers\n"
                   "3. Find customer\n"
                   "4. Find customer by purchase number\n"
                   "5. Load/store data\n"
                   "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> menu;

        switch(menu) {
            case 1:
                addCustomer();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                cout << "Goodbye\n";
                break;
            default:
                std::cout << "Invalid. Try again.\n";
        }
    } while (menu > 0 && menu <= 8);

}

void addCustomer() {
    int id = 0,
        purchaseCount = 1,
        purchase = 0;
    string title,
           name,
           type;

    cout << "Enter id: " << endl;
    while (id < 1) {
        if (id < 1) {
            cin >> id;
            cout << "Invalid. Try again." << endl;
        }
    }

    cout << "Enter title: " << endl;
    while (title.length() < 2) {
        if (title.length() < 2) {
            cin >> title;
            cout << "Too short." << endl;
        }
    }

    cout << "Enter name: " << endl;
    while (name.length() < 4) {
        if (name.length() < 4) {
            cin >> name;
            cout << "Too short." << endl;
        }
    }

    cout << "Enter purchase count: " << endl;
    while (purchaseCount < 0 || purchaseCount > 10000) {
        cin >> purchaseCount;
    }

    cout << "Enter purchases: " << endl;
    int purchases[purchaseCount];
    for (int i = 0; i < purchaseCount; i++) {
        cin >> purchases[i];
    }

    cout << "New or regular? " << endl;
    while (type!="New" || type!="Regular") {
        if (type!="New" || type!="Regular") {
            cin >> type;
            cout << "Invalid." << endl;
        }
    }
    Customer custom = *new Customer(id, title, name, purchaseCount, purchase[purchaseCount], type); // creation of an object

    allCustomers.push_back(custom);
}

void displayCustomers() {
    for (int i = 0; i < allCustomers.size(); i++) {
        cout << allCustomers[i] << endl;
        cout << "Sort by name or title?" << endl;
        allCustomers[i].getName();
    }
}

void findCustomer() {

}

void findByPurchase() {

}

void manageData() {

}
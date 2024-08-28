#include "pch.h"
#include "Customer.h"

using namespace std;

vector<Customer> allCustomers;

void addCustomer();
void displayCustomers();
const Customer* findCustomer(int customerId);
const Customer* findByPurchase(int purchaseNumber);
void saveCustomerData(const std::vector<Customer>& customers);
void loadCustomerData();

int main() {
    std::cout << "Customer Management System" << std::endl;
    int menu;
    do {
        std::cout
                << "1. Add customer\n"
                   "2. Display all customers\n"
                   "3. Find customer\n"
                   "4. Find customer by purchase number\n"
                   "5. Load/store data\n"
                   "6. Exit\n";
        std::cout << "Enter your choice:  ";
        std::cin >> menu;

        switch(menu) {
            case 1:
                addCustomer();
                break;
            case 2:
                displayCustomers();
                break;
            case 3: {
                int id;
                std::cout << "Enter Customer ID: ";
                std::cin >> id;
                const Customer* customer = findCustomer(id);
                if (customer) {
                    std::cout << "Customer found: " << customer->getName() << std::endl;
                } else {
                    std::cout << "Customer not found.\n";
                }
                break;
            }
            case 4: {
                int purchaseNumber;
                std::cout << "Enter Purchase Number: ";
                std::cin >> purchaseNumber;
                const Customer *customer = findByPurchase(purchaseNumber);
                if (customer) {
                    std::cout << "Customer found: " << customer->getName() << std::endl;
                } else {
                    std::cout << "Customer not found by purchase number.\n";
                }
                break;
            }
            case 5:
                char choice;
                std::cout << "Do you want to load (L) or store (S) data? ";
                std::cin >> choice;
                if (choice == 'L' || choice == 'l') {
                    loadCustomerData();
                } else if (choice == 'S' || choice == 's') {
                    saveCustomerData(allCustomers);
                } else {
                    std::cout << "Invalid choice.\n";
                }
                break;
            case 6:
                cout << "Goodbye\n";
                break;
            default:
                std::cout << "Invalid. Try again.\n";
        }
    } while (menu > 0 && menu <= 8);

    return 0;
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
    Customer custom(id, name, title, purchaseCount, purchases, type); // creation of an object

    allCustomers.push_back(custom);
}

void displayCustomers() {
    for (int i = 0; i < allCustomers.size(); i++) {
        cout << allCustomers[i] << endl;
        cout << "Display by name or title?" << endl;
        allCustomers[i].getName();
    }
}

const Customer* findCustomer(int customerId) {
    for (int i = 0; i < allCustomers.size(); i++) {
        if (allCustomers[i].getCustomerId() == customerId) {
            return &allCustomers[i];
        }
    }
    return nullptr; // Customer not found
}

const Customer* findByPurchase(int purchaseNumber) {
    for (const auto& customer : allCustomers) {
        int* purchases = customer.getPurchase(); // Assuming getPurchase() returns a pointer to the array
        for (int i = 0; i < customer.getPurchaseCount(); i++) {
            if (purchases[i] == purchaseNumber) {
                return &customer;
            }
        }
    }
    return nullptr; // Customer not found
}

// Function to save customer data to a text file
void saveCustomerData(const std::vector<Customer>& customers) {
    std::ofstream file("customers.txt");
    if (file.is_open()) {
        for (const Customer& customer : customers) {
            file << customer.getCustomerId() << " "
                 << customer.getTitle() << " "
                 << customer.getName() << " "
                 << customer.getPurchaseCount() << " "
                 << customer.getType() << std::endl;
            for (int i = 0; i < customer.getPurchaseCount(); i++) {
                file << customer.getPurchase() << " ";
            }
            file << std::endl;
        }
        file.close();
        std::cout << "Customer data saved to customers.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for writing" << std::endl;
    }
}
// Function to load customer data from a text file
void loadCustomerData() {
    std::ifstream file("customers.txt");
    vector<Customer> customers;
    if (file.is_open()) {
        allCustomers.clear();
        int id, purchaseCount;
        std::string title, name, type;
        while (file >> id >> title >> name >> purchaseCount >> type) {
            int purchases[purchaseCount];
            for (int i = 0; i < purchaseCount; i++) {
                file >> purchases[i];
            }
            Customer c(id, name, title, purchaseCount, purchases, type);
            customers.push_back(c);
        }
        file.close();
        std::cout << "Customer data loaded from customers.txt" << std::endl;
    } else {
        std::cerr << "Unable to open file for reading" << std::endl;
    }
}

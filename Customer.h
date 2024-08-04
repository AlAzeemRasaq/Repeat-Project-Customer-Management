#include "pch.h"
#ifndef CLASSES_CUSTOMER_H
#define CLASSES_CUSTOMER_H

using namespace std;

class Customer {
private:
public: //getters and setters
    int getCustomerId() const;
    void setCustomerId(int customerId);
    const string &getTitle() const;
    void setTitle(const string &title);
    const string &getName() const;
    void setName(const string &name);
    int getPurchaseCount() const;
    void setPurchaseCount(int purchaseCount);
    int *getPurchase() const;
    void setPurchase(int *purchase);
    const string &getType() const;
    void setType(const string &type);

private:
    int CustomerID;
    string title, name;
    int purchaseCount, purchase[];
    string type;
public:
    void addCustomer();
    void displayCustomers();
    void findCustomer();
    void findByPurchase();
    void manageData();

    Customer(int customerID, string name, string title, int purchaseCount, int purchase[purchaseCount], string type); // full constructor
    Customer();

    explicit Customer(int **purchase);

    // default constructor
    ~Customer(); // destructor
};

std::ostream& operator<<(ostream& os, Customer& customer) { // main operator
    return os << "Customer: [" <<
        customer.getCustomerId() << ", " <<
        customer.getName() << ", " <<
        customer.getTitle() << ", " <<
        customer.getPurchaseCount() << ", " <<
        customer.getPurchase() << ", " <<
        customer.getType() <<
    "]";
}

#endif //CLASSES_CUSTOMER_H
#include "pch.h"
#ifndef CLASSES_CUSTOMER_H
#define CLASSES_CUSTOMER_H

using namespace std;

class Customer {
private:
    int CustomerID;
    string title;
    string name;
    int purchaseCount;
    string type;
    int *purchase;
public:
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

    Customer(int customerID, string name, string title, int purchaseCount, int purchase[], string type); // full constructor
    Customer(); // default constructor
    ~Customer(); // destructor
};

inline std::ostream& operator<<(ostream& os, Customer& customer) { // main operator
    return os << "Customer: [" <<
        customer.getCustomerId() << ", " <<
        customer.getName() << ", " <<
        customer.getTitle() << ", " <<
        customer.getPurchaseCount() << ", " <<
        customer.getPurchase() << ", " <<
        customer.getType() <<
    "]";
}

inline Customer::Customer(int customerID, string name, string title, int purchaseCount, int purchase[], string type) { // full constructor defined
    this->setCustomerId(customerID);
    this->setName(name);
    this->setTitle(title);
    this->setPurchaseCount(purchaseCount);
    this->setPurchase(purchase);
    this->setType(type);
}
inline Customer::Customer() { // default constructor defined
    this->setCustomerId(1234);
    this->setName("Name");
}
inline Customer::~Customer() {} // destructor defined

#endif //CLASSES_CUSTOMER_H

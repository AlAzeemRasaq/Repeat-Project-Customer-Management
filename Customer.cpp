#include "Customer.h"

int Customer::getCustomerId() const {
    return CustomerID;
}
void Customer::setCustomerId(int customerId) {
    CustomerID = customerId;
}
const string &Customer::getTitle() const {
    return title;
}
void Customer::setTitle(const string &title) {
    Customer::title = title;
}
const string &Customer::getName() const {
    return name;
}
void Customer::setName(const string &name) {
    Customer::name = name;
}
int Customer::getPurchaseCount() const {
    return purchaseCount;
}
void Customer::setPurchaseCount(int purchaseCount) {
    Customer::purchaseCount = purchaseCount;
}
int *Customer::getPurchase() const {
    return purchase;
}
void Customer::setPurchase(int *purchase) {
    Customer::purchase = purchase;
}
const string &Customer::getType() const {
    return type;
}
void Customer::setType(const string &type) {
    Customer::type = type;
}

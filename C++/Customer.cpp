#include "Customer.h"

Customer::Customer(const std::string &name, const std::string &email)
    : name(name), email(email)
{
}

const std::string &Customer::getName() const
{
    return name;
}

const std::string &Customer::getEmail() const
{
    return email;
}
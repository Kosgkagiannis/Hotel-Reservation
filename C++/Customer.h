#pragma once
#include <string>

class Customer
{
private:
    std::string name;
    std::string email;

public:
    Customer(const std::string &name, const std::string &email);
    const std::string &getName() const;
    const std::string &getEmail() const;
};
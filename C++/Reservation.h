#pragma once
#include "Customer.h"
#include "Room.h"
#include <string>
#include <vector>

class Reservation
{
private:
    Room room;
    Customer customer;
    std::string checkInDate;
    std::string checkOutDate;

public:
    Reservation(Customer customer, Room room, const std::string &checkInDate, const std::string &checkOutDate);
    const Customer &getCustomer() const;
    const Room &getRoom() const;
    const std::string &getCheckInDate() const;
    const std::string &getCheckOutDate() const;
};
#include "Reservation.h"

Reservation::Reservation(Customer customer, Room room, const std::string &checkInDate, const std::string &checkOutDate)
    : customer(customer), room(room), checkInDate(checkInDate), checkOutDate(checkOutDate)
{
}

const Customer &Reservation::getCustomer() const
{
    return customer;
}

const Room &Reservation::getRoom() const
{
    return room;
}

const std::string &Reservation::getCheckInDate() const
{
    return checkInDate;
}

const std::string &Reservation::getCheckOutDate() const
{
    return checkOutDate;
}
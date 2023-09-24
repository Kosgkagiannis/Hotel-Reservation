#pragma once
#include "Room.h"
#include "Reservation.h"
#include <vector>

class Hotel
{
private:
    std::vector<Room> rooms;
    std::vector<Reservation> reservations;

public:
    Hotel();
    void addRoom(const Room &room);
    void makeReservation(Customer customer, int roomNumber, const std::string &checkInDate, const std::string &checkOutDate);
    bool isRoomAvailable(int roomNumber, const std::string &checkInDate, const std::string &checkOutDate);
    void listReservations();
    void printReservationConfirmation(const Reservation &reservation);

private:
    std::vector<std::vector<bool>> availabilityCalendar;
    void initializeAvailabilityCalendar();
    void updateAvailabilityCalendar(const Reservation &reservation);
    bool isRoomAvailableOnDate(int roomNumber, const std::string &date) const;

private:
    double calculateTotalCost(const Room &room, const std::string &checkInDate, const std::string &checkOutDate);
    int calculateNumberOfNights(const std::string &checkInDate, const std::string &checkOutDate);
    std::string generateConfirmationNumber();
};

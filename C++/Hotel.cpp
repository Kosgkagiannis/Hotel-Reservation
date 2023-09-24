#include "Hotel.h"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include "Reservation.h"

void Hotel::printReservationConfirmation(const Reservation &reservation)
{
    const Customer &customer = reservation.getCustomer();
    const Room &room = reservation.getRoom();
    const std::string &checkInDate = reservation.getCheckInDate();
    const std::string &checkOutDate = reservation.getCheckOutDate();

    double totalCost = calculateTotalCost(room, checkInDate, checkOutDate);

    std::cout << "Reservation Confirmation" << std::endl;
    std::cout << "Customer Name: " << customer.getName() << std::endl;
    std::cout << "Customer Email: " << customer.getEmail() << std::endl;
    std::cout << "Room Number: " << room.getRoomNumber() << std::endl;
    std::cout << "Check-In Date: " << checkInDate << std::endl;
    std::cout << "Check-Out Date: " << checkOutDate << std::endl;
    std::cout << "Total Cost: $" << totalCost << std::endl;
    std::cout << "Confirmation Number: " << generateConfirmationNumber() << std::endl;
    std::cout << std::endl;
}

void Hotel::updateAvailabilityCalendar(const Reservation &reservation)
{
    const Room &room = reservation.getRoom();
    const std::string &checkInDate = reservation.getCheckInDate();
    const std::string &checkOutDate = reservation.getCheckOutDate();

    int roomIndex = -1;
    for (size_t i = 0; i < rooms.size(); ++i)
    {
        if (rooms[i].getRoomNumber() == room.getRoomNumber())
        {
            roomIndex = static_cast<int>(i);
            break;
        }
    }

    if (roomIndex == -1)
    {
        std::cerr << "Error: Room not found." << std::endl;
        return;
    }

    struct tm tm_in = {};
    struct tm tm_out = {};
    strptime(checkInDate.c_str(), "%Y-%m-%d", &tm_in);
    strptime(checkOutDate.c_str(), "%Y-%m-%d", &tm_out);
    int checkInDay = tm_in.tm_yday;
    int checkOutDay = tm_out.tm_yday;

    for (int day = 0; day < 365; ++day)
    {
        if (day >= checkInDay && day <= checkOutDay)
        {
            availabilityCalendar[roomIndex][day] = false; // Room not available on this day
        }
    }
}

void Hotel::initializeAvailabilityCalendar()
{
    availabilityCalendar.resize(rooms.size(), std::vector<bool>(365, true));
}

Hotel::Hotel()
{
    initializeAvailabilityCalendar();
}

void Hotel::addRoom(const Room &room)
{
    rooms.push_back(room);
}

double Hotel::calculateTotalCost(const Room &room, const std::string &checkInDate, const std::string &checkOutDate)
{
    double pricePerNight = room.getPricePerNight();
    int numberOfNights = calculateNumberOfNights(checkInDate, checkOutDate);
    return pricePerNight * numberOfNights;
}

int Hotel::calculateNumberOfNights(const std::string &checkInDate, const std::string &checkOutDate)
{
    std::tm checkInTm = {};
    std::tm checkOutTm = {};
    std::istringstream(checkInDate) >> std::get_time(&checkInTm, "%Y-%m-%d");
    std::istringstream(checkOutDate) >> std::get_time(&checkOutTm, "%Y-%m-%d");

    std::time_t checkInTime = std::mktime(&checkInTm);
    std::time_t checkOutTime = std::mktime(&checkOutTm);

    std::time_t difference = checkOutTime - checkInTime;

    int numberOfNights = static_cast<int>(difference / (60 * 60 * 24));

    // User must stay at least 1 night
    return (numberOfNights > 0) ? numberOfNights : 1;
}

std::string Hotel::generateConfirmationNumber()
{

    std::time_t currentTime = std::time(nullptr);

    int randomNumber = rand() % 10000;
    std::stringstream confirmationNumber;
    confirmationNumber << "CONF" << std::put_time(std::localtime(&currentTime), "%Y%m%d%H%M%S") << randomNumber;

    return confirmationNumber.str();
}

bool Hotel::isRoomAvailable(int roomNumber, const std::string &checkInDate, const std::string &checkOutDate)
{

    for (const Reservation &reservation : reservations)
    {
        const Room &reservedRoom = reservation.getRoom();
        const std::string &reservedCheckIn = reservation.getCheckInDate();
        const std::string &reservedCheckOut = reservation.getCheckOutDate();

        if (reservedRoom.getRoomNumber() == roomNumber)
        {
            if ((checkInDate >= reservedCheckIn && checkInDate < reservedCheckOut) ||
                (checkOutDate > reservedCheckIn && checkOutDate <= reservedCheckOut))
            {
                return false;
            }
        }
    }

    return true;
}

void Hotel::listReservations()
{
    std::cout << "List of Reservations:" << std::endl;

    if (reservations.empty())
    {
        std::cout << "No reservations have been made." << std::endl;
    }
    else
    {
        for (const Reservation &reservation : reservations)
        {
            printReservationConfirmation(reservation);
        }
    }
    std::cout << std::endl;
}

void Hotel::makeReservation(Customer customer, int roomNumber, const std::string &checkInDate, const std::string &checkOutDate)
{
    // Check room availability here:
    if (!isRoomAvailable(roomNumber, checkInDate, checkOutDate))
    {
        std::cout << "Room is not available for the specified dates." << std::endl;
        return;
    }

    Room *room = nullptr;
    for (Room &r : rooms)
    {
        if (r.getRoomNumber() == roomNumber)
        {
            room = &r;
            break;
        }
    }

    if (room == nullptr)
    {
        std::cout << "Room not found." << std::endl;
        return;
    }

    Reservation reservation(customer, *room, checkInDate, checkOutDate);

    reservations.push_back(reservation);

    updateAvailabilityCalendar(reservation);

    std::cout << "Reservation made successfully!" << std::endl;
}

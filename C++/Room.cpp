#include "Room.h"

Room::Room(int roomNumber, const std::string &roomType, double pricePerNight, int maxOccupancy, const std::string &amenities)
    : roomNumber(roomNumber), isOccupied(false), roomType(roomType), pricePerNight(pricePerNight), maxOccupancy(maxOccupancy), amenities(amenities)
{
}

std::string Room::getRoomType()
{
    return roomType;
}

int Room::getRoomNumber() const
{
    return roomNumber;
}

double Room::getPricePerNight() const
{
    return pricePerNight;
}

int Room::getMaxOccupancy()
{
    return maxOccupancy;
}

std::string Room::getAmenities()
{
    return amenities;
}

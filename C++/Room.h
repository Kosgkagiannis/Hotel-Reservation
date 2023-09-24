#pragma once
#include <string>

class Room
{
private:
    int roomNumber;
    bool isOccupied;
    std::string roomType;
    double pricePerNight;
    int maxOccupancy;
    std::string amenities;

public:
    Room(int roomNumber, const std::string &roomType, double pricePerNight, int maxOccupancy, const std::string &amenities);
    void occupyRoom();
    void vacateRoom();
    int getRoomNumber() const;
    bool isOccupiedStatus();

    std::string getRoomType();
    double getPricePerNight() const;
    int getMaxOccupancy();
    std::string getAmenities();
};

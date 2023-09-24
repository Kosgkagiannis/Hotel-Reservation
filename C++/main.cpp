#include "Hotel.h"
#include <iostream>
#include <cstdlib>
#include "Hotel.h"
#include "Customer.h"
#include "Room.h"
#include "Reservation.h"

int main()
{
    Hotel hotel;

    Room room101(101, "Standard", 100.0, 2, "TV, Wi-Fi");
    Room room102(102, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi");
    Room room103(103, "Standard", 100.0, 2, "TV, Wi-Fi");
    Room room104(104, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi");
    Room room105(105, "Standard", 100.0, 2, "TV, Wi-Fi");
    Room room106(106, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi");
    Room room107(107, "Standard", 100.0, 2, "TV, Wi-Fi");
    Room room108(108, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi");
    Room room109(109, "Standard", 100.0, 2, "TV, Wi-Fi");
    Room room110(110, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi");

    hotel.addRoom(room101);
    hotel.addRoom(room102);
    hotel.addRoom(room103);
    hotel.addRoom(room104);
    hotel.addRoom(room105);
    hotel.addRoom(room106);
    hotel.addRoom(room107);
    hotel.addRoom(room108);
    hotel.addRoom(room109);
    hotel.addRoom(room110);

    while (true)
    {
        system("cls");
        std::cout << "Hotel Reservation System" << std::endl;
        std::cout << "1. Make Reservation" << std::endl;
        std::cout << "2. Check Room Availability" << std::endl;
        std::cout << "3. List Reservations" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::cin.ignore();
            std::string name, email, checkInDate, checkOutDate;
            int roomNumber;

            std::cout << "Enter customer name: ";
            std::getline(std::cin, name);

            std::cout << "Enter customer email: ";
            std::getline(std::cin, email);

            std::cout << "Enter room number: ";
            std::cin >> roomNumber;

            std::cout << "Enter check-in date (YYYY-MM-DD): ";
            std::cin >> checkInDate;

            std::cout << "Enter check-out date (YYYY-MM-DD): ";
            std::cin >> checkOutDate;

            Customer customer(name, email);
            hotel.makeReservation(customer, roomNumber, checkInDate, checkOutDate);
            break;
        }
        case 2:
        {
            int roomNumber;
            std::string checkInDate, checkOutDate;

            std::cout << "Enter room number: ";
            std::cin >> roomNumber;

            std::cout << "Enter check-in date (YYYY-MM-DD): ";
            std::cin >> checkInDate;

            std::cout << "Enter check-out date (YYYY-MM-DD): ";
            std::cin >> checkOutDate;

            bool available = hotel.isRoomAvailable(roomNumber, checkInDate, checkOutDate);
            if (available)
            {
                std::cout << "Room is available for the specified dates." << std::endl;
            }
            else
            {
                std::cout << "Room is not available for the specified dates." << std::endl;
            }
            break;
        }
        case 3:
            hotel.listReservations();
            break;
        case 4:
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}

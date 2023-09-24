from hotel import Hotel, Room
from customer import Customer 

if __name__ == "__main__":
    hotel = Hotel()

    room101 = Room(101, "Standard", 100.0, 2, "TV, Wi-Fi")
    room102 = Room(102, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi")
    room103 = Room(103, "Standard", 100.0, 2, "TV, Wi-Fi")
    room104 = Room(104, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi")
    room105 = Room(105, "Standard", 100.0, 2, "TV, Wi-Fi")
    room106 = Room(106, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi")
    room107 = Room(107, "Standard", 100.0, 2, "TV, Wi-Fi")
    room108 = Room(108, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi")
    room109 = Room(109, "Standard", 100.0, 2, "TV, Wi-Fi")
    room110 = Room(110, "Deluxe", 150.0, 4, "TV, Wi-Fi, Jacuzzi")

    hotel.add_room(room101)
    hotel.add_room(room102)
    hotel.add_room(room103)
    hotel.add_room(room104)
    hotel.add_room(room105)
    hotel.add_room(room106)
    hotel.add_room(room107)
    hotel.add_room(room108)
    hotel.add_room(room109)
    hotel.add_room(room110)

    while True:
        print("Hotel Reservation System")
        print("1. Make Reservation")
        print("2. Check Room Availability")
        print("3. List Reservations")
        print("4. Exit")

        choice = int(input("Enter your choice: "))

        if choice == 1:
            name = input("Enter customer name: ")
            email = input("Enter customer email: ")
            room_number = int(input("Enter room number: "))
            check_in_date = input("Enter check-in date (YYYY-MM-DD): ")
            check_out_date = input("Enter check-out date (YYYY-MM-DD): ")

            customer = Customer(name, email)
            hotel.make_reservation(customer, room_number, check_in_date, check_out_date)
        elif choice == 2:
            room_number = int(input("Enter room number: "))
            check_in_date = input("Enter check-in date (YYYY-MM-DD): ")
            check_out_date = input("Enter check-out date (YYYY-MM-DD): ")

            available = hotel.is_room_available(room_number, check_in_date, check_out_date)
            if available:
                print("Room is available for the specified dates.")
            else:
                print("Room is not available for the specified dates.")
        elif choice == 3:
            hotel.list_reservations()
        elif choice == 4:
            break
        else:
            print("Invalid choice. Please try again.")
        input("Press Enter to continue...")

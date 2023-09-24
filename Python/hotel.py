from random import randrange
from datetime import datetime

class Hotel:
    def __init__(self):
        self.rooms = []
        self.reservations = []
        self.availability_calendar = [[True] * 365 for _ in self.rooms]
        self.initialize_availability_calendar()

    def add_room(self, room):
        self.rooms.append(room)

    def calculate_total_cost(self, room, check_in_date, check_out_date):
        price_per_night = room.get_price_per_night()
        number_of_nights = self.calculate_number_of_nights(check_in_date, check_out_date)
        return price_per_night * number_of_nights

    def calculate_number_of_nights(self, check_in_date, check_out_date):
        check_in_date = datetime.strptime(check_in_date, "%Y-%m-%d")
        check_out_date = datetime.strptime(check_out_date, "%Y-%m-%d")
        difference = check_out_date - check_in_date
        number_of_nights = difference.days
        return max(number_of_nights, 1)

    def generate_confirmation_number(self):
        current_time = datetime.now().strftime("%Y%m%d%H%M%S")
        random_number = randrange(10000)
        confirmation_number = f"CONF{current_time}{random_number}"
        return confirmation_number

    def is_room_available(self, room_number, check_in_date, check_out_date):
        for reservation in self.reservations:
            reserved_room = reservation.get_room()
            reserved_check_in = reservation.get_check_in_date()
            reserved_check_out = reservation.get_check_out_date()

            if reserved_room.get_room_number() == room_number:
                if (
                    check_in_date >= reserved_check_in
                    and check_in_date < reserved_check_out
                ) or (check_out_date > reserved_check_in and check_out_date <= reserved_check_out):
                    return False
        return True

    def list_reservations(self):
        print("List of Reservations:")
        if not self.reservations:
            print("No reservations have been made.")
        else:
            for reservation in self.reservations:
                self.print_reservation_confirmation(reservation)
        print()

    def make_reservation(self, customer, room_number, check_in_date, check_out_date):
        if not self.is_room_available(room_number, check_in_date, check_out_date):
            print("Room is not available for the specified dates.")
            return

        room = None
        for r in self.rooms:
            if r.get_room_number() == room_number:
                room = r
                break

        if room is None:
            print("Room not found.")
            return

        reservation = Reservation(customer, room, check_in_date, check_out_date)
        self.reservations.append(reservation)
        self.update_availability_calendar(reservation)
        print("Reservation made successfully!")

    def initialize_availability_calendar(self):
        self.availability_calendar = [[True] * 365 for _ in self.rooms]

    def update_availability_calendar(self, reservation):
        room = reservation.get_room()
        check_in_date = reservation.get_check_in_date()
        check_out_date = reservation.get_check_out_date()

        room_index = -1
        for i, r in enumerate(self.rooms):
            if r.get_room_number() == room.get_room_number():
                room_index = i
                break

        if room_index == -1:
            print("Error: Room not found.")
            return

        check_in_date = datetime.strptime(check_in_date, "%Y-%m-%d")
        check_out_date = datetime.strptime(check_out_date, "%Y-%m-%d")

        check_in_day = check_in_date.timetuple().tm_yday
        check_out_day = check_out_date.timetuple().tm_yday

        while len(self.availability_calendar[room_index]) < 365:
            self.availability_calendar[room_index].append(True)

        for day in range(check_in_day - 1, check_out_day):
            self.availability_calendar[room_index][day] = False


class Room:
    def __init__(self, room_number, room_type, price_per_night, max_occupancy, amenities):
        self.room_number = room_number
        self.is_occupied = False
        self.room_type = room_type
        self.price_per_night = price_per_night
        self.max_occupancy = max_occupancy
        self.amenities = amenities

    def get_room_type(self):
        return self.room_type

    def get_room_number(self):
        return self.room_number

    def get_price_per_night(self):
        return self.price_per_night

    def get_max_occupancy(self):
        return self.max_occupancy

    def get_amenities(self):
        return self.amenities

class Reservation:
    def __init__(self, customer, room, check_in_date, check_out_date):
        self.customer = customer
        self.room = room
        self.check_in_date = check_in_date
        self.check_out_date = check_out_date

    def get_customer(self):
        return self.customer

    def get_room(self):
        return self.room

    def get_check_in_date(self):
        return self.check_in_date

    def get_check_out_date(self):
        return self.check_out_date

if __name__ == "__main__":
    hotel = Hotel()

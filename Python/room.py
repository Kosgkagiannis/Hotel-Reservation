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

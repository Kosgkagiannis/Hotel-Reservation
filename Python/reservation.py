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

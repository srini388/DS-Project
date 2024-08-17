
#define MAX 150

typedef struct {
    int seatNumber;
    char *name;
    char *phoneNumber;
} Seat;

typedef struct {
    int totalSeats;
    int availableSeats;
    int price;
    Seat *seats;
} SeatClass;

typedef struct {
    int screenNumber;
    SeatClass VIP;
    SeatClass GOLD;
    SeatClass SILVER;
} Screen;

void initializeScreens(Screen *screens, int numScreens) ;
void displayAvailableSeats(Screen *screens, int screenNumber);
int bookSeats(Screen *screens, int screenNumber, char *seatClass, int seatNumber, const char *customerName, const char *phoneNumber) ;
int cancelBooking(Screen *screens, int screenNumber, char *seatClass, int seatNumber, const char *phoneNumber) ;


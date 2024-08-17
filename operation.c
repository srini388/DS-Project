// Function to initialize the screens and their seat classes
void initializeScreens(Screen *screens, int numScreens) {
    for (int i = 0; i < numScreens; i++) {
        screens[i].screenNumber = i + 1;

        // Initialize VIP Class
        screens[i].VIP.totalSeats = MAX;
        screens[i].VIP.availableSeats = MAX;
        screens[i].VIP.price = 500;
        screens[i].VIP.seats = (Seat *)malloc(MAX * sizeof(Seat));
        for (int j = 0; j < MAX; j++) {
            screens[i].VIP.seats[j].seatNumber = j + 1;
            screens[i].VIP.seats[j].name = NULL;
            screens[i].VIP.seats[j].phoneNumber = NULL;
        }

        // Initialize GOLD Class
        screens[i].GOLD.totalSeats = MAX;
        screens[i].GOLD.availableSeats = MAX;
        screens[i].GOLD.price = 300;
        screens[i].GOLD.seats = (Seat *)malloc(MAX * sizeof(Seat));
        for (int j = 0; j < MAX; j++) {
            screens[i].GOLD.seats[j].seatNumber = j + 1;
            screens[i].GOLD.seats[j].name = NULL;
            screens[i].GOLD.seats[j].phoneNumber = NULL;
        }

        // Initialize SILVER Class
        screens[i].SILVER.totalSeats = MAX;
        screens[i].SILVER.availableSeats = MAX;
        screens[i].SILVER.price = 150;
        screens[i].SILVER.seats = (Seat *)malloc(MAX * sizeof(Seat));
        for (int j = 0; j < MAX; j++) {
            screens[i].SILVER.seats[j].seatNumber = j + 1;
            screens[i].SILVER.seats[j].name = NULL;
            screens[i].SILVER.seats[j].phoneNumber = NULL;
        }
    }
}

// Function to display available seats for a given screen and seat class
void displayAvailableSeats(Screen *screens, int screenNumber) {
    Screen screen = screens[screenNumber - 1];
    printf("Screen %d\n", screen.screenNumber);

    // Display VIP Seats
    printf("VIP Class: Available Seats = %d\n", screen.VIP.availableSeats);
    for (int i = 0; i < screen.VIP.totalSeats; i++) {
        if (screen.VIP.seats[i].name == NULL) {
            printf("Seat %d is available\n", screen.VIP.seats[i].seatNumber);
        }
    }

    // Display GOLD Seats
    printf("GOLD Class: Available Seats = %d\n", screen.GOLD.availableSeats);
    for (int i = 0; i < screen.GOLD.totalSeats; i++) {
        if (screen.GOLD.seats[i].name == NULL) {
            printf("Seat %d is available\n", screen.GOLD.seats[i].seatNumber);
        }
    }

    // Display SILVER Seats
    printf("SILVER Class: Available Seats = %d\n", screen.SILVER.availableSeats);
    for (int i = 0; i < screen.SILVER.totalSeats; i++) {
        if (screen.SILVER.seats[i].name == NULL) {
            printf("Seat %d is available\n", screen.SILVER.seats[i].seatNumber);
        }
    }
}

// Function to book a seat
int bookSeats(Screen *screens, int screenNumber, char *seatClass, int seatNumber, const char *customerName, const char *phoneNumber) {
    Screen *screen = &screens[screenNumber - 1];
    SeatClass *selectedClass = NULL;

    if (strcmp(seatClass, "VIP") == 0) {
        selectedClass = &screen->VIP;
    } else if (strcmp(seatClass, "GOLD") == 0) {
        selectedClass = &screen->GOLD;
    } else if (strcmp(seatClass, "SILVER") == 0) {
        selectedClass = &screen->SILVER;
    }

    if (selectedClass != NULL && selectedClass->availableSeats > 0) {
        Seat *seat = &selectedClass->seats[seatNumber - 1];
        if (seat->name == NULL) {
            seat->name = (char *)malloc(strlen(customerName) + 1);
            seat->phoneNumber = (char *)malloc(strlen(phoneNumber) + 1);
            strcpy(seat->name, customerName);
            strcpy(seat->phoneNumber, phoneNumber);
            selectedClass->availableSeats--;
            printf("Seat %d in %s class booked successfully!\n", seatNumber, seatClass);
            return 1;
        } else {
            printf("Seat %d in %s class is already booked.\n", seatNumber, seatClass);
            return 0;
        }
    }
    return 0;
}

// Function to cancel a booking
int cancelBooking(Screen *screens, int screenNumber, char *seatClass, int seatNumber, const char *phoneNumber) {
    Screen *screen = &screens[screenNumber - 1];
    SeatClass *selectedClass = NULL;

    if (strcmp(seatClass, "VIP") == 0) {
        selectedClass = &screen->VIP;
    } else if (strcmp(seatClass, "GOLD") == 0) {
        selectedClass = &screen->GOLD;
    } else if (strcmp(seatClass, "SILVER") == 0) {
        selectedClass = &screen->SILVER;
    }

    if (selectedClass != NULL) {
        Seat *seat = &selectedClass->seats[seatNumber - 1];
        if (seat->phoneNumber != NULL && strcmp(seat->phoneNumber, phoneNumber) == 0) {
            free(seat->name);
            free(seat->phoneNumber);
            seat->name = NULL;
            seat->phoneNumber = NULL;
            selectedClass->availableSeats++;
            printf("Booking for Seat %d in %s class canceled successfully!\n", seatNumber, seatClass);
            return 1;
        } else {
            printf("Phone number does not match or the seat is not booked.\n");
            return 0;
        }
    }
    return 0;
}

int main() {
    int numScreens = 3;
    Screen screens[numScreens];

    // Initialize screens
    initializeScreens(screens, numScreens);

    int choice, screenNumber, seatNumber;
    char seatClass[10], customerName[50], phoneNumber[15];

    while (1) {
        printf("\n--- Theater Booking System ---\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter screen number (1-%d): ", numScreens);
                scanf("%d", &screenNumber);
                if (screenNumber >= 1 && screenNumber <= numScreens) {
                    displayAvailableSeats(screens, screenNumber);
                } else {
                    printf("Invalid screen number.\n");
                }
                break;

            case 2:
                printf("Enter screen number (1-%d): ", numScreens);
                scanf("%d", &screenNumber);
                if (screenNumber >= 1 && screenNumber <= numScreens) {
                    printf("Enter seat class (VIP/GOLD/SILVER): ");
                    scanf("%s", seatClass);
                    printf("Enter seat number (1-%d): ", MAX);
                    scanf("%d", &seatNumber);
                    printf("Enter customer name: ");
                    scanf("%s", customerName);
                    printf("Enter phone number: ");
                    scanf("%s", phoneNumber);
                    bookSeats(screens, screenNumber, seatClass, seatNumber, customerName, phoneNumber);
                } else {
                    printf("Invalid screen number.\n");
                }
                break;

            case 3:
                printf("Enter screen number (1-%d): ", numScreens);
                scanf("%d", &screenNumber);
                if (screenNumber >= 1 && screenNumber <= numScreens) {
                    printf("Enter seat class (VIP/GOLD/SILVER): ");
                    scanf("%s", seatClass);
                    printf("Enter seat number (1-%d): ", MAX);
                    scanf("%d", &seatNumber);
                    printf("Enter phone number: ");
                    scanf("%s", phoneNumber);
                    cancelBooking(screens, screenNumber, seatClass, seatNumber, phoneNumber);
                } else {
                    printf

("Invalid screen number.\n");
                }
                break;

            case 4:
                printf("Exiting the system.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

#include "op.h"

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
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter screen number (1-%d): ", numScreens);
                if (scanf("%d", &screenNumber) != 1 || screenNumber < 1 || screenNumber > numScreens) {
                    printf("Invalid screen number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                displayAvailableSeats(screens, screenNumber);
                break;

            case 2:
                printf("Enter screen number (1-%d): ", numScreens);
                if (scanf("%d", &screenNumber) != 1 || screenNumber < 1 || screenNumber > numScreens) {
                    printf("Invalid screen number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                printf("Enter seat class (VIP/GOLD/SILVER): ");
                scanf("%s", seatClass);
                printf("Enter seat number (1-%d): ", MAX);
                if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > MAX) {
                    printf("Invalid seat number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                printf("Enter customer name: ");
                scanf("%s", customerName);
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                bookSeats(screens, screenNumber, seatClass, seatNumber, customerName, phoneNumber);
                break;

            case 3:
                printf("Enter screen number (1-%d): ", numScreens);
                if (scanf("%d", &screenNumber) != 1 || screenNumber < 1 || screenNumber > numScreens) {
                    printf("Invalid screen number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                printf("Enter seat class (VIP/GOLD/SILVER): ");
                scanf("%s", seatClass);
                printf("Enter seat number (1-%d): ", MAX);
                if (scanf("%d", &seatNumber) != 1 || seatNumber < 1 || seatNumber > MAX) {
                    printf("Invalid seat number.\n");
                    while (getchar() != '\n'); // Clear input buffer
                    break;
                }
                printf("Enter phone number: ");
                scanf("%s", phoneNumber);
                cancelBooking(screens, screenNumber, seatClass, seatNumber, phoneNumber);
                break;

            case 4:
                printf("Exiting the system.\n");
                // Free allocated memory
                for (int i = 0; i < numScreens; i++) {
                    for (int j = 0; j < MAX; j++) {
                        free(screens[i].VIP.seats[j].name);
                        free(screens[i].VIP.seats[j].phoneNumber);
                        free(screens[i].GOLD.seats[j].name);
                        free(screens[i].GOLD.seats[j].phoneNumber);
                        free(screens[i].SILVER.seats[j].name);
                        free(screens[i].SILVER.seats[j].phoneNumber);
                    }
                    free(screens[i].VIP.seats);
                    free(screens[i].GOLD.seats);
                    free(screens[i].SILVER.seats);
                }
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

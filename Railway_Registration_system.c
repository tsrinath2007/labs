#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Configuration ---
#define COACHES 3
#define SEATS_PER_COACH 10
#define TOTAL_SEATS (COACHES * SEATS_PER_COACH)
#define WAITLIST_MAX 5
#define BASE_FARE 500.0
#define DYNAMIC_THRESHOLD 0.75 // 75% occupancy for price increase
#define DYNAMIC_MULTIPLIER 1.2 // 20% price increase

// Structure to store passenger details
typedef struct {
    int booking_id;
    char name[50];
    int age;
    int coach;     // e.g., 0 for C1, 1 for C2 and so on
    int seat;      // e.g., 0 for S1, 1 for S2 and so on
    float fare_paid;
} Passenger;


// 2D array for seat map: 0 = Available, 1 = Booked so they can get an overview of seat availability
int seats[COACHES][SEATS_PER_COACH] = {0};

// Array to store details of confirmed bookings
Passenger confirmed_bookings[TOTAL_SEATS];
int booking_count = 0; // Current number of booked seats

// Array to act as a queue for the waitlist
Passenger waitlist[WAITLIST_MAX];
int waitlist_count = 0; // Current number of passengers on waitlist

// System state
float total_revenue = 0.0;
int next_booking_id = 1; // Simple unique ID generator


// --- Function Prototypes ---
void display_seat_map();
float calculate_dynamic_fare();
void book_ticket();
void cancel_ticket();
void add_to_waitlist(char name[], int age, float fare);
void book_from_waitlist(int coach, int seat);
void generate_revenue_report();

// --- Main Function ---
int main() {
    int choice;

    //while loop is used to continuously show the menu until the user decides to exit.
    while (1) {
        printf("\n--- Railway Reservation System ---\n");
        printf("Train: Express (Coaches: %d, Seats: %d)\n", COACHES, SEATS_PER_COACH);
        printf("1. Book Ticket\n");
        printf("2. Cancel Ticket\n");
        printf("3. View Seat Map\n");
        printf("4. Generate Revenue Report\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            // Clear invalid input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                book_ticket();
                break;
            case 2:
                cancel_ticket();
                break;
            case 3:
                display_seat_map();
                break;
            case 4:
                generate_revenue_report();
                break;
            case 5:
                printf("\nGenerating final report and exiting...\n");
                generate_revenue_report();
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// --- Function Definitions ---

/**
 * @brief Displays the current seat map.
 * 0 = Available, 1 = Booked
 */
void display_seat_map() {
    printf("\n--- Seat Map ---\n");
    printf(" (0=Available, 1=Booked)\n");
    printf("Seat:");
    for (int j = 0; j < SEATS_PER_COACH; j++) {
        printf("%3d", j + 1);
    }
    printf("\n");
    printf("-----");
    for (int j = 0; j < SEATS_PER_COACH; j++) {
        printf("---");
    }
    printf("\n");

    for (int i = 0; i < COACHES; i++) {
        printf("C-%-3d:", i + 1);
        for (int j = 0; j < SEATS_PER_COACH; j++) {
            printf("%3d", seats[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Calculates the fare based on current demand.
 * @return The calculated fare.
 */
float calculate_dynamic_fare() {
    float occupancy = (float)booking_count / TOTAL_SEATS;
    if (occupancy >= DYNAMIC_THRESHOLD) {
        printf("Dynamic fare applied! (Occupancy > 75%%)\n");
        return BASE_FARE * DYNAMIC_MULTIPLIER;
    }
    return BASE_FARE;
}

/**
 * @brief Handles the logic for booking a new ticket.
 */
void book_ticket() {
    char name[50];
    int age;

    printf("\nEnter Passenger Name: ");
    scanf(" %[^\n]s", name); // Read string with spaces
    printf("Enter Passenger Age: ");
    scanf("%d", &age);

    // Check if train is full
    if (booking_count >= TOTAL_SEATS) {
        // Train is full, check waitlist
        if (waitlist_count < WAITLIST_MAX) {
            char choice;
            printf("Train is full. Add to waitlist? (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y') {
                float fare = calculate_dynamic_fare(); // Fare is locked in at time of waitlist
                add_to_waitlist(name, age, fare);
            } else {
                printf("Booking cancelled.\n");
            }
        } else {
            printf("Sorry, the train and waitlist are both full.\n");
        }
        return;
    }

    // Find the first available seat
    int found_seat = 0;
    for (int i = 0; i < COACHES; i++) {
        for (int j = 0; j < SEATS_PER_COACH; j++) {
            if (seats[i][j] == 0) { // Seat is available
                // 1. Calculate fare
                float current_fare = calculate_dynamic_fare();
                
                // 2. Mark seat as booked
                seats[i][j] = 1;
                
                // 3. Store passenger details
                Passenger new_passenger;
                new_passenger.booking_id = next_booking_id++;
                strcpy(new_passenger.name, name);
                new_passenger.age = age;
                new_passenger.coach = i;
                new_passenger.seat = j;
                new_passenger.fare_paid = current_fare;
                
                confirmed_bookings[booking_count] = new_passenger;
                
                // 4. Update system state
                booking_count++;
                total_revenue += current_fare;
                
                printf("\n--- Ticket Booked Successfully! ---\n");
                printf("Booking ID: %d\n", new_passenger.booking_id);
                printf("Name: %s, Age: %d\n", new_passenger.name, new_passenger.age);
                printf("Coach: C-%d, Seat: %d\n", i + 1, j + 1);
                printf("Fare Paid: %.2f\n", current_fare);
                
                found_seat = 1;
                return; // Exit function after booking
            }
        }
    }
}

/**
 * @brief Adds a passenger to the waitlist queue.
 */
void add_to_waitlist(char name[], int age, float fare) {
    // Add to the end of the queue
    waitlist[waitlist_count].booking_id = next_booking_id++;
    strcpy(waitlist[waitlist_count].name, name);
    waitlist[waitlist_count].age = age;
    waitlist[waitlist_count].fare_paid = fare; // Store the fare they agreed to
    waitlist[waitlist_count].coach = -1; // -1 means waitlisted
    waitlist[waitlist_count].seat = -1;
    
    waitlist_count++;
    
    printf("\nAdded to waitlist. Booking ID: %d, Position: %d\n", 
           waitlist[waitlist_count - 1].booking_id, waitlist_count);
}

/**
 * @brief Handles logic for cancelling a ticket.
 */
void cancel_ticket() {
    int booking_id;
    printf("\nEnter Booking ID to cancel: ");
    scanf("%d", &booking_id);

    int found_index = -1;
    // Search for the booking in confirmed list
    for (int i = 0; i < booking_count; i++) {
        if (confirmed_bookings[i].booking_id == booking_id) {
            found_index = i;
            break;
        }
    }

    if (found_index == -1) {
        // Check waitlist (maybe they want to cancel a waitlist ticket)
        for (int i = 0; i < waitlist_count; i++) {
            if (waitlist[i].booking_id == booking_id) {
                printf("Removing %s from waitlist position %d.\n", waitlist[i].name, i + 1);
                // Shift waitlist queue up
                for (int j = i; j < waitlist_count - 1; j++) {
                    waitlist[j] = waitlist[j + 1];
                }
                waitlist_count--;
                return;
            }
        }
        printf("Error: Booking ID %d not found.\n", booking_id);
        return;
    }

    // Found in confirmed bookings, proceed with cancellation
    Passenger cancelled_p = confirmed_bookings[found_index];
    
    // 1. Free the seat
    seats[cancelled_p.coach][cancelled_p.seat] = 0;
    
    // 2. Refund fare (update revenue)
    total_revenue -= cancelled_p.fare_paid;
    
    printf("\n--- Ticket Cancelled ---\n");
    printf("Booking ID: %d, Name: %s\n", cancelled_p.booking_id, cancelled_p.name);
    printf("Refunded: %.2f\n", cancelled_p.fare_paid);

    // 3. Remove passenger from confirmed_bookings array by shifting
    for (int i = found_index; i < booking_count - 1; i++) {
        confirmed_bookings[i] = confirmed_bookings[i + 1];
    }
    booking_count--;

    // 4. Check waitlist and promote if possible
    if (waitlist_count > 0) {
        printf("A seat has opened. Booking first passenger from waitlist...\n");
        // Book the newly opened seat (cancelled_p.coach, cancelled_p.seat)
        book_from_waitlist(cancelled_p.coach, cancelled_p.seat);
    }
}

/**
 * @brief Books the first person from the waitlist into a specific seat.
 */
void book_from_waitlist(int coach, int seat) {
    // 1. Get first person from waitlist (FIFO queue)
    Passenger lucky_passenger = waitlist[0];
    
    // 2. Book them into the new seat
    lucky_passenger.coach = coach;
    lucky_passenger.seat = seat;
    
    // 3. Add them to confirmed bookings
    confirmed_bookings[booking_count] = lucky_passenger;
    
    // 4. Update system state
    seats[coach][seat] = 1; // Mark seat as booked
    booking_count++;
    total_revenue += lucky_passenger.fare_paid; // Add their pre-paid fare
    
    printf("\n--- Waitlist Ticket Confirmed! ---\n");
    printf("Booking ID: %d\n", lucky_passenger.booking_id);
    printf("Name: %s, Age: %d\n", lucky_passenger.name, lucky_passenger.age);
    printf("New Coach: C-%d, New Seat: %d\n", coach + 1, seat + 1);
    printf("Fare Paid: %.2f\n", lucky_passenger.fare_paid);

    // 5. Shift the waitlist queue
    for (int i = 0; i < waitlist_count - 1; i++) {
        waitlist[i] = waitlist[i + 1];
    }
    waitlist_count--;
}

/**
 * @brief Prints a summary of all bookings and total revenue.
 */
void generate_revenue_report() {
    printf("\n--- End of Day Revenue Report ---\n");
    printf("Total Bookings: %d\n", booking_count);
    printf("Total Revenue Generated: %.2f\n", total_revenue);
    
    printf("\n--- Confirmed Bookings List ---\n");
    if (booking_count == 0) {
        printf("No tickets booked.\n");
    } else {
        printf("ID   | Name                 | Age | Coach | Seat | Fare\n");
        printf("-----|----------------------|-----|-------|------|-------\n");
        for (int i = 0; i < booking_count; i++) {
            Passenger p = confirmed_bookings[i];
            printf("%-4d | %-20s | %-3d | C-%-4d | %-4d | %.2f\n",
                   p.booking_id, p.name, p.age, p.coach + 1, p.seat + 1, p.fare_paid);
        }
    }
    
    printf("\n--- Current Waitlist ---\n");
    if (waitlist_count == 0) {
        printf("Waitlist is empty.\n");
    } else {
        printf("Pos | ID   | Name                 | Age\n");
        printf("----|------|----------------------|-----\n");
        for (int i = 0; i < waitlist_count; i++) {
            printf("%-3d | %-4d | %-20s | %-3d\n",
                   i + 1, waitlist[i].booking_id, waitlist[i].name, waitlist[i].age);
        }
    }
    printf("-----------------------------------\n");
}

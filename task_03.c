#include<stdio.h>

void show_routes(void) {
    printf("------------------------------------------\n");
    printf("Bus Ticket Prices for different Routes\n");
    printf("------------------------------------------\n");
    printf("%-4s %-10s %-12s\n", "#", "Price", "Route");
    printf("%-4s %-10s %-12s\n", "1", "Rs. 800",  "Karachi to Hyderabad");
    printf("%-4s %-10s %-12s\n", "2", "Rs. 2200",  "Karachi to Sukkur");
    printf("%-4s %-10s %-12s\n", "3", "Rs. 3500",  "Karachi to Multan");
    printf("------------------------------------------\n");
}

void get_route(int *routeNumber,int *seats) {
    while(1){
        printf("\nSelect the route you want to travel on (1-3): ");
        scanf("%d", routeNumber);
        printf("\nSelect the number of seats you want to book(1-6): ");
        scanf("%d", seats);

        if(*routeNumber >= 1 && *routeNumber <= 3 && *seats >= 1 && *seats <= 6){
            break;
        }
        else if(*routeNumber < 1 || *routeNumber > 3){
            printf("Invalid choice. Please enter a number from 1 to 3 for route.\n");
        }
        else if(*seats < 1 || *seats > 6){
            printf("Invalid choice. Please enter a number from 1 to 6 for seats.\n");
        }
    }
}

int singleFare(int *routeNumber){
    int fare = 0;
    switch(*routeNumber){
        case 1:
            fare = 800;
            break;
        case 2:
            fare = 2200;
            break;
        case 3:
            fare = 3500;
            break;
        default:
            printf("Invalid route number.\n");
            break;
    }
    return fare;
}

int totalFare(int *fare,int *seats){
    return *fare * *seats;
}

char seat_type(void){
    char seatType;
    while(1){
        printf("\nSelect the seat type you want to book(E for Economy, B for Business): ");
        scanf(" %c", &seatType);

        if(seatType == 'E' || seatType == 'e' || seatType == 'B' || seatType == 'b'){
            return seatType;
        }
        printf("Invalid seat type. Please enter E for Economy or B for Business.\n");
    }
}

int seatCharge(int totalCharges, char seatType){
    if(seatType == 'B' || seatType == 'b'){
        return totalCharges + (int)(totalCharges * 0.3);
    }
    return totalCharges;
}

void ticketSlip(int *routeNumber, int *seats, char *seatType, int *totalCharges){
    printf("------------------------------------------\n");
    printf("============ Bus Ticket ============\n");
    printf("------------------------------------------\n");
    switch(*seatType){
        case 'E':
        case 'e':
        printf("\nSeat Type: Economy\n");
        break;
        case 'B':
        case 'b':
        printf("\nSeat Type: Business\n");
        break;
        default:
        printf("Invalid seat type.\n");
        break;
    }
    
    switch(*routeNumber){
        case 1:
        printf("Route: Karachi to Hyderabad\n");
        break;
        case 2:
        printf("Route: Karachi to Sukkur\n");
        break;
        case 3:
        printf("Route: Karachi to Multan\n");
        break;
        default:
        printf("Invalid route type.\n");
        break;
    }

    printf("Number of Seats Reserved: %d\n", *seats);
    printf("Final Total Charges: Rs. %d\n", *totalCharges);

    printf("------------------------------------------\n");
}


int main(){
    int routeNumber,seats,companyIncome = 0;
    for(int i=0;i<2;i++){
        printf("\nBooking for passenger %d:\n", i+1);

        show_routes();
        get_route(&routeNumber,&seats);
        int fare = singleFare(&routeNumber);
        int totalCharges = totalFare(&fare,&seats);
        char seatType = seat_type();
        totalCharges = seatCharge(totalCharges, seatType);

        ticketSlip(&routeNumber,&seats,&seatType,&totalCharges);
        companyIncome += totalCharges;

        printf("Company's total income from all bookings: Rs. %d\n", companyIncome);
    }
    return 0;
}
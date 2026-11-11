#include<stdio.h>

void fareDisplay(){
    printf("----------------------------------------------\n");
    printf("======== Fare Rules of a Taxi Company ========\n");
    printf("----------------------------------------------\n");
    printf("Base Fare Rs. 150\n");
    printf("Rs. 60 per km for first 10 km\n");
    printf("Rs. 45 per km after 10 km\n");
    printf("----------------------------------------------\n");
}


void inputDist(int *distance,int *waitingTime){
    while(1){

        printf("\nEnter the distance in km(1-200): ");
        scanf("%d", distance);
        printf("\nEnter the waiting time in minutes(0-120): ");
        scanf("%d", waitingTime);
        if(*distance >= 1 && *distance <= 200 && *waitingTime >= 0 && *waitingTime <= 120){
            break;
        }
        printf("Invalid input. Please enter valid values.\n");
    }

}

int distanceCharge(int *distance){
    int baseFare = 150;
    int distanceFare = 0;
    
    if(*distance <= 10){
        distanceFare = baseFare + (*distance * 60);
    }
    else{
        distanceFare = baseFare + (10 * 60) + ((*distance - 10) * 45);
    }
    return distanceFare;
}

int waitingCharge(int *waitingTime){
    int waitingFare = 0;
    if(*waitingTime <= 5){
        waitingFare = 0;
    }
    else{
        waitingFare = (*waitingTime - 5) * 10;
    }
    return waitingFare;
}

int nightCharge(int *totalFare){
    int hour;
    while(1){
        printf("Enter the hour of the trip(0-23): ");
        scanf("%d", &hour);
        if(hour >= 0 && hour <= 23){
            break;
        }
        printf("Invalid hour. Please enter a value from 0 to 23.\n");
    }
    if(hour >= 22 || hour < 6){
        *totalFare += *totalFare * 0.25; // Add 25% surcharge
    }
    return *totalFare;
}

void finalReceipt(int distance,int waitingTime,int totalFare){
    printf("----------------------------------------------\n");
    printf("======== Final Receipt ========\n");
    printf("----------------------------------------------\n");
    printf("Distance Travelled: %d km\n", distance);
    printf("Waiting Time: %d minutes\n", waitingTime);
    printf("Total Fare: Rs. %d\n", totalFare);
    printf("----------------------------------------------\n");

}

int main(){
    int distance,waitingTime,totalIncome = 0,highestFare = 0;
    for(int i=0;i<3;i++){
        printf("\nTrip Day%d:\n", i+1);
        fareDisplay();
        inputDist(&distance,&waitingTime);
        int distanceFare = distanceCharge(&distance);
        int waitingFare = waitingCharge(&waitingTime);
        int totalFare = distanceFare + waitingFare;
        totalFare = nightCharge(&totalFare);
        if(totalFare > highestFare){
            highestFare = totalFare;
        }
        totalIncome += totalFare;
        finalReceipt(distance,waitingTime,totalFare);
    }
    printf("\nTotal Earnings of Taxi Company: Rs. %d\n", totalIncome);
    printf("Highest Fare of the Day: Rs. %d\n", highestFare);
    return 0;
}


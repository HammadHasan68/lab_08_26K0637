#include<stdio.h>

void show_charges(void) {
    printf("------------------------------------------\n");
    printf("Agha Khan Hospital Room Charges per Day\n");
    printf("------------------------------------------\n");
    printf("%-4s %-10s %-12s\n", "#", "Price", "Ward Type");
    printf("%-4s %-10s %-12s\n", "1", "Rs. 1500",  "General Ward");
    printf("%-4s %-10s %-12s\n", "2", "Rs. 3500",  "Semi Private");
    printf("%-4s %-10s %-12s\n", "3", "Rs. 6000",  "Private");
    printf("------------------------------------------\n");
}

void room_type(int *roomType,int *days) {
    while(1){
        printf("\nSelect the room type you want to stay in (1-3): ");
        scanf("%d", roomType);
        printf("\nSelect the number of days stayed(1-30): ");
        scanf("%d", days);

        if(*roomType >= 1 && *roomType <= 3 && *days >= 1 && *days <= 30){
            break;
        }
        else if(*roomType < 1 || *roomType > 3){
            printf("Invalid choice. Please enter a number from 1 to 3 for room type.\n");
        }
        else if(*days < 1 || *days > 30){
            printf("Invalid choice. Please enter a number from 1 to 30 for days.\n");
        }
    }
}

int room_charges(int *roomType, int *days){
    int charges = 0;
    switch(*roomType){
        case 1:
            charges = 1500 * (*days);
            break;
        case 2:
            charges = 3500 * (*days);
            break;
        case 3:
            charges = 6000 * (*days);
            break;
        default:
            printf("Invalid room type.\n");
            break;
    }
    return charges;
}

int medicine_charge(){
    int medicineBill,medicineCharges;
    printf("\nEnter the medicine charges: ");
    scanf("%d", &medicineBill);

    medicineCharges = medicineBill + medicineBill * 0.05;
    return medicineCharges;
}

int discount(int *days, int *totalCharges){
    if(*days >= 7){
        return *totalCharges * 0.08;
    }
    return 0;
}

void seniorCitizenDiscount(int *totalCharges){
    char isSenior;
    printf("\nIs the patient a senior citizen? (y/n): ");
    scanf(" %c", &isSenior);
    if(isSenior == 'y' || isSenior == 'Y'){
        *totalCharges -= 1000;
        printf("Senior citizen discount of Rs. 1000 applied.\n");
        if(*totalCharges < 0){
            *totalCharges = 0;
        }
    }
}


void finalBill(int roomType,int days,int roomCharges,int medicineCharges,int totalCharges){
    
    printf("------------------------------------------\n");
    printf("=========== Final Bill ===========\n");
    printf("------------------------------------------\n");
    switch(roomType){
        case 1:
        printf("\nRoom Type: General Ward\n");
        break;
        case 2:
        printf("\nRoom Type: Semi Private\n");
        break;
        case 3:
        printf("\nRoom Type: Private\n");
        break;
        default:
        printf("Invalid room type.\n");
        break;
    }
    
    printf("Number of Days Stayed: %d\n", days);
    printf("Room Charges: Rs. %d\n", roomCharges);
    printf("Medicine Charges: Rs. %d\n", medicineCharges);
    printf("Total Charges: Rs. %d\n", totalCharges);

    
    printf("------------------------------------------\n");
}


int main(){
    int roomType,days;

    show_charges();
    room_type(&roomType,&days);

    int roomCharges = room_charges(&roomType,&days);
    int medicineCharges = medicine_charge();
    int totalCharges = roomCharges + medicineCharges;
    int discountAmount = discount(&days,&totalCharges);

    totalCharges -= discountAmount;

    seniorCitizenDiscount(&totalCharges);
    finalBill(roomType,days,roomCharges,medicineCharges,totalCharges);

    return 0;
}
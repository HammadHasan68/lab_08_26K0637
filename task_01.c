#include <stdio.h>

/* Clears leftover characters in the input buffer using scanf */
void clear_input(void) {
    char junk[100];
    scanf("%99[^\n]", junk);
    scanf("%*c");
}

/* 1. Print the title and the list of packs */
void show_packs(void) {
    printf("------------------------------------------\n");
    printf("List of the Available Packages\n");
    printf("------------------------------------------\n");
    printf("%-4s %-10s %-12s %-20s\n", "#", "Price", "Balance", "Type");
    printf("%-4s %-10s %-12s %-20s\n", "1", "Rs. 100",  "Rs. 100",  "TalkTime Balance");
    printf("%-4s %-10s %-12s %-20s\n", "2", "Rs. 200",  "Rs. 200",  "TalkTime Balance");
    printf("%-4s %-10s %-12s %-20s\n", "3", "Rs. 500",  "Rs. 500",  "TalkTime Balance");
    printf("%-4s %-10s %-12s %-20s\n", "4", "Rs. 1000", "Rs. 1000", "TalkTime Balance");
    printf("------------------------------------------\n");
}

/* 2. Ask for the pack number (1 to 4) and return it */
int get_package(void) {
    int pack;
    while (1) {
        printf("\nSelect the package you want to subscribe (1-4): ");
        if (scanf("%d", &pack) == 1 && pack >= 1 && pack <= 4) {
            clear_input();
            return pack;
        }
        printf("Invalid choice. Please enter a number from 1 to 4.\n");
        clear_input();
    }
}

/* 3. Ask for an 11-digit mobile number and return it as long long.
    The input is read as text with %s, checked character by character,
      and then built into a number, so the leading 0 is kept. */
long long get_mobile(void) {
    while (1) {
        char text[50];
        long long number = 0;
        int count = 0;
        int valid = 1;
        int i;

        printf("\nEnter your mobile number (11 digit): ");
        scanf("%49s", text);

        for (i = 0; text[i] != '\0'; i++) {
            if (text[i] >= '0' && text[i] <= '9') {
                number = number * 10 + (text[i] - '0');
                count++;
            } else {
                valid = 0;
            }
        }

        if (valid && count == 11) {
            clear_input();
            return number;
        }
        printf("Invalid number. Please enter exactly 11 digits.\n");
    }
}

/* 4. Find the pack amount from the pack number using switch */
double get_amount(int pack) {
    switch (pack) {
        case 1: return 100;
        case 2: return 200;
        case 3: return 500;
        case 4: return 1000;
        default: return 0;
    }
}

/* 5. Add 15% tax and return the new total */
double add_tax(double amount) {
    return amount + amount * 0.15;
}

/* 6. Bonus is 10% for packs of Rs. 500 or more, otherwise 0 */
double get_bonus(double amount) {
    if (amount >= 500) {
        return amount * 0.10;
    }
    return 0;
}

/* 7. Print the recharge slip */
void print_slip(long long mobile, double amount, double tax,
                double total_paid, double total_balance) {
    printf("\n------------- Recharge Slip ------------\n");
    printf("User Mobile Number is: %011lld\n", mobile);
    printf("Amount of pack is Rs. %.2f\n", amount);
    printf("Tax on Amount is Rs. %.2f\n", tax);
    printf("Amount to be paid is Rs. %.2f\n", total_paid);
    printf("Total Balance Recharged is Rs. %.2f\n", total_balance);
    printf("---------------------------------------\n");
}

int main(void) {
    double total_spent = 0;

    for (int i = 1; i <= 3; i++) {
        printf("\n===== Recharge %d of 3 =====\n", i);

        show_packs();
        int pack = get_package();
        long long mobile = get_mobile();

        double amount = get_amount(pack);
        double total_paid = add_tax(amount);
        double tax = total_paid - amount;
        double bonus = get_bonus(amount);

        print_slip(mobile, amount, tax, total_paid, amount + bonus);

        total_spent += total_paid;
    }

    printf("\nTotal money spent after 3 recharges: Rs. %.2f\n", total_spent);
    return 0;
}
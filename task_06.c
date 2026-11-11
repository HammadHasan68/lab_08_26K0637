#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i, hotDays = 0;
    double *temp, *ptr, hottest, coldest;

    do {
        printf("Enter number of days (1-10): ");
        scanf("%d", &n);
    } while (n < 1 || n > 10);

    temp = malloc(n * sizeof(double));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        do {
            printf("Enter temperature for day %d (-10 to 55): ", i + 1);
            scanf("%lf", &temp[i]);
        } while (temp[i] < -10 || temp[i] > 55);
    }

    for (i = 0; i < n; i++) {
        printf("Day %d: %.1f at address %p\n", i + 1, temp[i], (void *)&temp[i]);
    }

    ptr = temp;
    hottest = *ptr;
    coldest = *ptr;
    for (i = 0; i < n; i++) {
        if (*ptr > hottest) hottest = *ptr;
        if (*ptr < coldest) coldest = *ptr;
        ptr++;
    }
    printf("Hottest: %.1f\n", hottest);
    printf("Coldest: %.1f\n", coldest);

    for (i = 0; i < n; i++) {
        if (temp[i] > 40) hotDays++;
    }
    printf("Days hotter than 40: %d\n", hotDays);

    free(temp);
    temp = NULL;
    printf("Memory released successfully.\n");

    return 0;
}
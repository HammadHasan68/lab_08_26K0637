#include <stdio.h>

/* Prints one row of the address table.
   void * is used so any pointer type can be passed in. */
void print_row(const char *name, void *address) {
    printf("%-18s %2p\n", name, address);
}

int main(void) {
    double costPrice, sellPrice, quantity;
    double totalCost, totalSales, profit, profitPercent;

    /* Pointers to the input variables */
    double *costPtr = &costPrice;
    double *sellPtr = &sellPrice;
    double *quantityPtr = &quantity;

    /* Pointers to the calculated results */
    double *totalCostPtr = &totalCost;
    double *totalSalesPtr = &totalSales;
    double *profitPtr = &profit;
    double *profitPercentPtr = &profitPercent;

    /* Pointer to the larger price (step 6) */
    double *largerPtr;

    /* Step 2: read values through pointers */
    printf("\nEnter the cost price of the item: ");
    scanf("%lf", costPtr);
    printf("Enter the selling price of the item: ");
    scanf("%lf", sellPtr);
    printf("Enter the quantity sold: ");
    scanf("%lf", quantityPtr);

    /* Step 3: calculate totals and profit through pointers */
    *totalCostPtr = *costPtr * *quantityPtr;
    *totalSalesPtr = *sellPtr * *quantityPtr;
    *profitPtr = *totalSalesPtr - *totalCostPtr;

    printf("\nTotal Cost: %.2f", *totalCostPtr);
    printf("\nTotal Sales: %.2f\n", *totalSalesPtr);

    /* Step 4: decision structure */
    if (*totalSalesPtr > *totalCostPtr) {
        printf("\nProfit: %.2f\n", *profitPtr);
    }
    else if (*totalSalesPtr < *totalCostPtr) {
        printf("\nLoss: %.2f\n", -*profitPtr);
    }
    else {
        printf("\nNo profit no loss\n");
    }

    /* Step 5: profit percentage through pointers (guard against division by zero) */
    if (*totalCostPtr != 0) {
        *profitPercentPtr = (*profitPtr / *totalCostPtr) * 100;
    }
    else {
        *profitPercentPtr = 0;
    }
    printf("Profit Percentage: %.2f%%\n", *profitPercentPtr);

    /* Step 6: pointer to the larger of costPrice and sellPrice */
    if (*costPtr >= *sellPtr) {
        largerPtr = costPtr;
        printf("\nLarger price is costPrice, value: %.2f\n", *largerPtr);
    }
    else {
        largerPtr = sellPtr;
        printf("\nLarger price is sellPrice, value: %.2f\n", *largerPtr);
    }

    /* Step 7: address table of every variable and every pointer */
    printf("\n%-18s %2s\n", "Name", "Address");
    printf("------------------------------------------\n");
    
    print_row("costPrice", (void *)&costPrice);
    print_row("sellPrice", (void *)&sellPrice);
    print_row("quantity", (void *)&quantity);
    print_row("totalCost", (void *)&totalCost);
    print_row("totalSales", (void *)&totalSales);
    print_row("profit", (void *)&profit);
    print_row("profitPercent", (void *)&profitPercent);

    print_row("costPtr", (void *)&costPtr);
    print_row("sellPtr", (void *)&sellPtr);
    print_row("quantityPtr", (void *)&quantityPtr);
    print_row("totalCostPtr", (void *)&totalCostPtr);
    print_row("totalSalesPtr", (void *)&totalSalesPtr);
    print_row("profitPtr", (void *)&profitPtr);
    print_row("profitPercentPtr", (void *)&profitPercentPtr);
    print_row("largerPtr", (void *)&largerPtr);

    printf("------------------------------------------\n");
    return 0;
}
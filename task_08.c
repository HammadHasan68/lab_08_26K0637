#include<stdio.h>
#include<stdlib.h>

void fillArray(int *p, int n){

    for(int i=0; i<n; i++){
        printf("Enter the stock of item %d: ", i+1);
        scanf("%d", (p+i));
    }
}

void showMenu(int *choice){

    printf("=====================\n");
    printf("Grocery Shop Menu:\n");
    printf("=====================\n");
    printf("\n1. Display Stock\n");
    printf("2. Update Stock of a Item\n");
    printf("3. Insert a new Item\n");
    printf("4. Delete an Item\n");
    printf("5. Sort Stock\n");
    printf("0. Exit\n");
    printf("=====================\n");

    printf("\nEnter the choice: ");
    scanf("%d", choice);
}

void displayStock(int *p, int n){

    printf("\nCurrent Stock:\n");
    for(int i=0; i<n; i++){
        printf("\nItem %d: %d\n", i+1, *(p+i));
    }
}


void UpdateStock(int *p, int n){

    int itemNumber, newStock;

    printf("Enter the item number to update (1 to %d): ", n);
    scanf("%d", &itemNumber);

    if(itemNumber < 1 || itemNumber > n){
        printf("Invalid item number!\n");
        return;
    }

    printf("Enter the new stock for item %d: ", itemNumber);
    scanf("%d", &newStock);

    *(p + (itemNumber - 1)) = newStock;
    printf("Stock updated successfully!\n");
}

void InsertItem(int **p, int *n){

    int newStock;

    printf("Enter the stock for the new item: ");
    scanf("%d", &newStock);

    *p = (int*)realloc(*p, (*n + 1) * sizeof(int));
    if(*p == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    *(*p + *n) = newStock;
    (*n)++;
    printf("New item inserted successfully!\n");
}

void DeleteItem(int **p, int *n){

    int itemNumber;

    printf("Enter the item number to delete (1 to %d): ", *n);
    scanf("%d", &itemNumber);

    if(itemNumber < 1 || itemNumber > *n){
        printf("Invalid item number!\n");
        return;
    }

    for(int i = itemNumber - 1; i < *n - 1; i++){
        *(*p + i) = *(*p + i + 1);
    }

    *p = (int*)realloc(*p, (*n - 1) * sizeof(int));
    if(*p == NULL && *n - 1 > 0){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    (*n)--;
    printf("Item deleted successfully!\n");
}   

void SortStock(int *p, int n){

    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(*(p + j) > *(p + j + 1)){
                int temp = *(p + j);
                *(p + j) = *(p + j + 1);
                *(p + j + 1) = temp;
            }
        }
    }
    printf("Stock sorted successfully!\n");
}

void printTotalAndLowest(int *p, int n){
    if(n <= 0){
        printf("No items in stock.\n");
        return;
    }

    int totalStock = 0;
    int lowestStock = *p;
    int lowestItemIndex = 0;

    for(int i = 0; i < n; i++){
        totalStock += *(p + i);
        if(*(p + i) < lowestStock){
            lowestStock = *(p + i);
            lowestItemIndex = i;
        }
    }

    printf("Total Stock: %d\n", totalStock);
    printf("Item with the Lowest Stock: Item %d with %d units\n", lowestItemIndex + 1, lowestStock);
}

int main(){
// Print the total stock and the item with the lowest stock after every change.


    int n, choice;

    printf("Enter the starting size: ");
    scanf("%d", &n);

    int *stock = (int*)malloc(n * sizeof(int));

    fillArray(stock, n);
    while(1){
        showMenu(&choice);
    
        switch(choice){
            case 1:
                displayStock(stock, n);
                printTotalAndLowest(stock, n);
                break;
            case 2:
                UpdateStock(stock, n);
                printTotalAndLowest(stock, n);
                break;
            case 3:
                InsertItem(&stock, &n);
                printTotalAndLowest(stock, n);
                break;
            case 4:
                DeleteItem(&stock, &n);
                printTotalAndLowest(stock, n);
                break;
            case 5:
                SortStock(stock, n);
                printTotalAndLowest(stock, n);
                break;
            case 0:
                free(stock);
                printf("Exiting the program.\n");
                exit(0);
        }
    }
    return 0;
}


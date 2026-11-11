#include<stdio.h>

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

int main(){

    int n, choice;

    printf("Enter the starting size: ");
    scanf("%d", &n);

    int *array = malloc(n * sizeof(int));
    
    showMenu(&choice);
    
    switch(choice){
        case 1:
            displayStock(array, n);
            break;
    }
    displayStock(array, n);
    return 0;
}